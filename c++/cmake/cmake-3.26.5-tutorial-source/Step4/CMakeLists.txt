# TODO 4: Update the minimum required version to 3.15

cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# TODO 1: 将下面的代码替换为:
# * 创建一个interface库tutorial_compiler_flags
#   Hint: use add_library() with the INTERFACE signature
# * 添加编译特性cxx_std_11到tutorial_compiler_flags
#   Hint: Use target_compile_features()
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_14)



# TODO 5: 创建一些辅助变量用来确定用的是哪个编译器:
# * 创建一个变量gcc_like_cxx如果用的是CXX并且用的是下列任意一个编译器那么值为true
#         ARMClang, AppleClang, Clang, GNU, LCC
# * 创建一个变量msvc_cxx如果用的是CXX和MSVC那么值为true
# Hint: Use set() and COMPILE_LANG_AND_ID

# TODO 6: 向interface库tutorial_compiler_flags中添加警告选项：
# 
# * 如果是gcc_like_cxx, 添加 -Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused
# * 如果是msvc_cxx, 添加 -W3
# Hint: Use target_compile_options()

# TODO 7: 用嵌套生成器表达式, 只在构建的时警告
# 
# Hint: Use BUILD_INTERFACE

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()

# add the executable
add_executable(Tutorial tutorial.cxx)

# TODO 2: 链接tutorial_compiler_flags

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )