#!/usr/bin/env python
# coding: utf-8

# In[1]:


import os
 
# 函数功能：批量修改文件夹路径下所有文件的文件名，此处以在原文件名前面加一个'rename_'为例
def change_file_name(dir_path):
    files = os.listdir(dir_path)  # 读取文件名
    for f in files:
        #设置旧文件名（路径+文件名）
        oldname=os.path.join(dir_path,f)
        #设置新文件名
        newname=os.path.join(dir_path,'rename_'+f)
        #用os模块中的rename方法对文件改名
        os.rename(oldname,newname)
        print(oldname,'======>',newname)

if __name__=='__main__':
    change_file_name('data/data105415')


# In[ ]:





# 请点击[此处](https://ai.baidu.com/docs#/AIStudio_Project_Notebook/a38e5576)查看本环境基本用法.  <br>
# Please click [here ](https://ai.baidu.com/docs#/AIStudio_Project_Notebook/a38e5576) for more detailed instructions. 
