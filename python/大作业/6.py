import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
x=np.arange(0,2*np.pi,0.01)
y=np.sin(x)
plt.plot(x,y,'y:',linewidth=4, marker='v',markersize=6,)
plt.xlabel('x轴')
plt.ylabel('y轴')
plt.title("正弦函数图像")
plt.show()