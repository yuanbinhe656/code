#!/usr/bin/env python
# coding: utf-8

# In[1]:


# Python3

# 函数功能：打印99乘法表
def multiplication_table():
    s = ''
    for i in range(1,10):         # 1-9范围的整数
        for j in range(1,i+1):    # 1-i范围内的整数
            s += '{}*{}={}'.format(i,j,i*j)+" "   # 计算一次乘积，并且添加到整体的乘法表字符串中
        s += '\n'                 # 计算完i的乘法项，输出要换行
    return s                      # 以字符串的方式返回乘法表

if __name__=='__main__':          # python主函数解释执行的入口（可省略，直接写执行命令）
    s = multiplication_table()    # 调用产生乘法表的函数
    print(s)                      # 打印函数返回值，即乘法表


# 请点击[此处](https://ai.baidu.com/docs#/AIStudio_Project_Notebook/a38e5576)查看本环境基本用法.  <br>
# Please click [here ](https://ai.baidu.com/docs#/AIStudio_Project_Notebook/a38e5576) for more detailed instructions. 
