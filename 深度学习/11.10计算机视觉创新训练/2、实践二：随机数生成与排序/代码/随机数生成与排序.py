#!/usr/bin/env python
# coding: utf-8

# In[1]:


# python3
import random

# 函数功能：生成ranges范围内的nums个整数
def random_int(ranges=[0,100],num=1):  
    if ranges[0]>ranges[1]:   # 检查生成随机数的范围是否有错
        print('取值范围错误')
        return []
    res = []
    for i in range(num):
        res.append(random.randint(ranges[0],ranges[1]+1))
    return res

# 函数功能：生成ranges范围内的nums个小数
def random_float(ranges=[0,100],num=1):
    if ranges[0]>ranges[1]:   # 检查生成随机数的范围是否有错
        print('取值范围错误')
        return []  
    res = []
    for i in range(num):
        res.append(random.random()*(ranges[1]-ranges[0])+ranges[0])
    return res

# 函数功能：快速排序
def quick_sort(arr): 
    if len(arr) < 2:
        return arr
    # 选取基准，随便选哪个都可以，选中间的便于理解
    mid_index = len(arr) // 2
    # 定义基准值左中右三个数列
    left, mid, right = [], [], []
    
    for item in arr: 
        if item > arr[mid_index]:  # 大于arr[mid_index]的放在右边集合
            right.append(item)     
        elif item==arr[mid_index]: # 等于arr[mid_index]的放在中间集合
            mid.append(item)
        else:                      # 小于arr[mid_index]的放在左边集合
            left.append(item)
    # 使用迭代进行比较
    return quick_sort(left) + mid + quick_sort(right)


if __name__ == '__main__':
    int_list = random_int([20,60],5)
    float_list = random_float([20.1,60],5)
    int_list_sort = quick_sort(int_list)
    float_list_sort = quick_sort(float_list)
    # 上面排序后是升序，如果想降序排列，只需加下列命令
    # int_list_sort = int_list_sort[::-1]
    print('整数列表排序前：',int_list)
    print('整数列表排序前：',int_list_sort)
    print('浮点列表排序前：',float_list)
    print('浮点列表排序前：',float_list_sort)
    


# 请点击[此处](https://ai.baidu.com/docs#/AIStudio_Project_Notebook/a38e5576)查看本环境基本用法.  <br>
# Please click [here ](https://ai.baidu.com/docs#/AIStudio_Project_Notebook/a38e5576) for more detailed instructions. 
