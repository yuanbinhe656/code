import random
data1=[random.randint(1,10)]*5
data2=random.choice(range(10), k=5)
data3=random.sanple(range(10),k=5)
for data in (data1,data2,data3):
    print('=='*20)
    print(data)
    k1=len(set(data))
    k2=len(data)
    if k1==k2:
        print('无重复')
    elif k1==1:
        print('完全重复')
    else :
        print('部分重复')