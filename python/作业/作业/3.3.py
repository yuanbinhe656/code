vector1= eval (input('请输入一个包含若干整数的向量'))
vector2= eval (input('请输入一个包含若干整数等长的向量'))
print(sum([num1*num2 for num1,num2 in zip( vector1,vector2)]))

data=eval(input('请输入一个包含若干整数的列表：'))
m = max(data)
print(m)
print([index for index,value in enumerate(data) if value==m ])

