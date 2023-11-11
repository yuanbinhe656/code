#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class CMyString {
public:
    CMyString(const char* str = nullptr) {
        cout << "CMyString(const char* str = nullptr)" << endl;
        if (str) {
            data_ = new char[strlen(str) + 1];
            strcpy(data_, str);
        }
        else {
            data_ = nullptr;
        }
    }

    // 移动构造函数
    CMyString(CMyString&& other) noexcept {
        cout << " CMyString(CMyString&& other) noexcept {" << endl;
        data_ = other.data_;
        other.data_ = nullptr;
    }

    // 移动赋值运算符
    CMyString& operator=(CMyString&& other) noexcept {
        cout << " CMyString& operator=(CMyString&& other)" << endl;
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            other.data_ = nullptr;
        }
        return *this;
    }

    ~CMyString() {
        delete[] data_;
    }

private:
    char* data_;
};
CMyString GetString()
{
    char strs[3] = "aa";
    CMyString str(strs);
    return str;
}

int main() {
    
    CMyString str2 = GetString();  // 使用 std::move 将 str1 移动到 str2
    int* ptr = new int[10];
    int* pre = ptr + 2;
    delete[] pre;
    cout << *ptr;
    // 输出 str2 应该包含 "Hello"
    ///cout << "str2: " << str2 << std::endl;

    // str1 现在应该为空
    //cout << "str1: " << str1 << std::endl;

    return 0;
}