import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif']=['SimHei']
labels = '二七区47', '中原区27', '管城区14', '高新区6', '航空港区4', '金水区4', '郑东新区1'

sizes = [47, 27, 14, 6, 4, 4, 1]

colors = ['lightgreen', 'gold', 'lightskyblue', 'lightcoral''lightred', 'lightgray', 'yellow']

explode =[ 0, 0, 0, 0, 0, 0, 0]


plt.pie(sizes, labels=labels)

plt.axis('equal')

plt.axis('equal')

plt.show()
