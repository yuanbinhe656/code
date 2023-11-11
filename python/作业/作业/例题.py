data=[2**i for i in range(64)]
sum=0;
for i in range(64):
    sum=data[i]+sum
print(data)
print(sum)

b = eval(input('请输入一个包含若干整数的列表：'))
a=[]
for i in b:
    if(i%2==1):
        a.append(i)
print(a)

