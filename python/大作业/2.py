import numpy as np
import matplotlib.pyplot as plt

# 某学生的课程与成绩
courses = ['英语' 'Java技术' '线性代数' '马克思主义' '计算机导论' '体育' 'Python程序设计' '网页设计']
scores1 = [78, 90, 78, 90, 48, 79, 82, 93]
scores2 = [83, 85, 65, 82, 75, 85, 78, 85]
scores3 = [88, 85, 71, 83, 86, 87, 89, 56]
scores4 = [90, 80, 67, 76, 86, 90, 76, 92]
scores5 = [72, 73, 80, 71, 74, 71, 82, 84]
scores6 = [70, 86, 86, 72, 67, 81, 66, 77]
dataLength = len(scores1)  # 数据长度
# angles数组把圆周等分为dataLength份
angles = np.linspace(0,  # 数组第一个数据
                     2 * np.pi,  # 数组最后一个数据
                     dataLength,  # 数组中数据数量
                     endpoint=False)  # 不包含终点
scores1.append(scores1[0])
scores2.append(scores2[0])
scores3.append(scores3[0])
scores4.append(scores4[0])
scores5.append(scores5[0])
scores6.append(scores6[0])

angles = np.append(angles, angles[0])  # 闭合
# 绘制雷达图
plt.polar(angles,  # 设置角度
          scores1,  # 设置各角度上的数据
          'rv--',  # 设置颜色、线型和端点符

          linewidth=2)  # 设置线宽
plt.polar(angles,  # 设置角度
          scores2,  # 设置各角度上的数据
          'bv--',  # 设置颜色、线型和端点符

          linewidth=2)  # 设置线宽
plt.polar(angles,  # 设置角度
          scores3,  # 设置各角度上的数据
          'gv--',  # 设置颜色、线型和端点符

          linewidth=2)  # 设置线宽
plt.polar(angles,  # 设置角度
          scores4,  # 设置各角度上的数据
          'yv--',  # 设置颜色、线型和端点符

          linewidth=2)  # 设置线宽
plt.polar(angles,  # 设置角度
          scores5,  # 设置各角度上的数据
          'v--', color='brown' , # 设置颜色、线型和端点符

          linewidth=2)  # 设置线宽
plt.polar(angles,  # 设置角度
          scores6,  # 设置各角度上的数据
          'v--', color='gray' ,# 设置颜色、线型和端点符

          linewidth=2)  # 设置线宽
# 设置角度网格标签
plt.thetagrids(angles * 180 / np.pi,
               courses,
               fontproperties='simhei')
# 填充雷达图内部
plt.fill(angles,
         scores1,
         facecolor='r',
         alpha=0.4)
plt.show()
