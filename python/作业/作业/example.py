import matplotlib.pyplot as plt
month = list(range(1,13))
money = [5.2,2.7,5.8,7.3,9.2,18.7,15.6,20.5,18.0,7.8,6.9]
for x,y in zip(month,money) :
    color='#%02x'%int( y*10)+'6666'
    plt.bar(x,y,color=color,hatch='*',width=0.6,edgecolor='b',linestyle='--',linewidth=1.5)

    plt.text(x-0.3,y+0.2,'%.1f'%y)
plt.xlabel('月份',fontproperties='simhei')
plt.ylabel('营业额（万元）',fontproperties='simhei',fontsize=14)
plt.xticks(month)
xzuo=list(range(0,22))
plt.ylim(0,22)
plt.show()