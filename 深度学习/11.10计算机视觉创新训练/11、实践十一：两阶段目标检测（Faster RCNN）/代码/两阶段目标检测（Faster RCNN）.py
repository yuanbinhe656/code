#!/usr/bin/env python
# coding: utf-8

# ## 使用PaddleDetection实现目标检测(考虑到下载时间，在这里我们使用一个i)
# PaddleDetection飞桨目标检测开发套件，旨在帮助开发者更快更好地完成检测模型的组建、训练、优化及部署等全开发流程。
# 
# PaddleDetection模块化地实现了多种主流目标检测算法，提供了丰富的数据增强策略、网络模块组件（如骨干网络）、损失函数等，并集成了模型压缩和跨平台高性能部署能力。
# 
# 经过长时间产业实践打磨，PaddleDetection已拥有顺畅、卓越的使用体验，被工业质检、遥感图像检测、无人巡检、新零售、互联网、科研等十多个行业的开发者广泛应用。
# ****   
#  
# 
# ### 特性
# 
# - **模型丰富**: 包含**目标检测**、**实例分割**、**人脸检测**等**100+个预训练模型**，涵盖多种**全球竞赛冠军**方案
# - **使用简洁**：模块化设计，解耦各个网络组件，开发者轻松搭建、试用各种检测模型及优化策略，快速得到高性能、定制化的算法。
# - **端到端打通**: 从数据增强、组网、训练、压缩、部署端到端打通，并完备支持**云端**/**边缘端**多架构、多设备部署。
# - **高性能**: 基于飞桨的高性能内核，模型训练速度及显存占用优势明显。支持FP16训练, 支持多机训练。

# ### 准备环境

# In[ ]:


#PaddleDetection的代码库下载，同时支持github源和gitee源，为了在国内网络环境更快下载，此处使用gitee源。  
#! git clone https://github.com/PaddlePaddle/PaddleDetection.git
get_ipython().system(' git clone https://gitee.com/paddlepaddle/PaddleDetection.git')
get_ipython().run_line_magic('cd', 'PaddleDetection')
# 安装其他依赖
get_ipython().system(' pip install paddledet==2.0.1 -i https://mirror.baidu.com/pypi/simple')


# ### 确认环境安装是否正常
# 如果出现，则表示安装成功
# ```
# .....
# ----------------------------------------------------------------------
# Ran 5 tests in x.xxxs
# 
# OK
# ```

# In[ ]:


get_ipython().system('python ppdet/modeling/tests/test_architectures.py')


# ### 数据准备
# 我们使用路标识别数据集进行实验 运行下载准备好的数据集  
# 
# 也可以进行挂载，请参考[如何准备数据集](https://github.com/PaddlePaddle/PaddleDetection/blob/release/2.0/docs/tutorials/PrepareDataSet.md)

# In[ ]:


get_ipython().system(' python dataset/roadsign_voc/download_roadsign_voc.py')


# ## 训练数据
# 
# 这里使用的是`faster_rcnn_r50_1x_coco.yml`需要对文件进行修改，打开文件把`/datasets/roadsign_voc.yml`替换原先的训练集！  
# 然后进行训练即可（可以修改参数进行调节）  
# 除此之外需要修改`PaddleDetection/configs/faster_rcnn/_base_/faster_fpn_reader.yml`文件的`worker_num`参数修改成0或1.  
# 
# * 训练评估参数说明
# ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210513114440448.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTYyMzA5Mw==,size_16,color_FFFFFF,t_70)

# ### 配置文件说明
# ```
# roadsign_voc.yml：训练数据文件。  
# runtime.yml：主要说明了公共的运行状态，比如说是否使用GPU、迭代轮数等等。  
# optimizer_1x.yml：主要说明模型、和主干网络的情况说明。  
# faster_rcnn_r50.yml：主要说明了学习率和优化器的配置。在其他的训练的配置中，学习率和优化器是放在了一个新的配置文件中。  
# faster_reader.yml：主要说明了读取后的预处理操作，比如resize、数据增强等等。  
# ```

# ### 执行训练

# In[ ]:


get_ipython().system(' python tools/train.py -c ./configs/faster_rcnn/faster_rcnn_r50_1x_coco.yml --eval --use_vdl=True --vdl_log_dir="./output" ')


# ## 模型评估与预测

# ### 模型评估

# In[ ]:


get_ipython().system('python -u tools/eval.py -c ./configs/faster_rcnn/faster_rcnn_r50_1x_coco.yml  -o weights=output/faster_rcnn_r50_1x_coco/model_final.pdparams')


# ### 模型预测

# In[ ]:


get_ipython().system('python tools/infer.py -c ./configs/faster_rcnn/faster_rcnn_r50_1x_coco.yml -o weights=output/faster_rcnn_r50_1x_coco/model_final.pdparams  --infer_img=dataset/roadsign_voc/images/road114.png')


# ### 结果展示

# In[ ]:


import matplotlib.pyplot as plt

# 定义显示函数
def display(img_dir):
    plt.figure(figsize=(15, 15))

    title = ['Input Image', 'Predicted Image']
    
    for i in range(len(title)):
        plt.subplot(1, len(img_dir), i+1)
        plt.title(title[i])
        img = plt.imread(img_dir[i])
        plt.imshow(img)
        plt.axis('off')
    plt.show()

# 显示检测图片效果
# 注：仅显示其中一张图片的效果。    
image_dir = "dataset/roadsign_voc/images/road114.png"
mask_dir = "./output/road114.png"
imgs = [image_dir, mask_dir]
display(imgs)

