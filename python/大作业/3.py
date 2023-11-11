import matplotlib.pyplot as plt
import numpy as np
import random


plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

month20 = np.arange(1,13)
moth21=month20+0.3

data20 = [5.2, 2.7, 5.8, 5.7, 7.3, 9.2, 8.7, 15.6, 10.5, 11.0, 7.8, 3.9]
data21 = [3.6, 4.6, 2.1, 3.8, 8.9, 5.8, 6.5, 27.8, 13.9, 6.2, 10.3, 3.7]
print(month20)

plt.bar(month20, data20,width=0.3,color='b')
plt.bar(moth21, data21,width=0.3,color='r')
plt.title('20年与21年销售额度')

plt.show()
