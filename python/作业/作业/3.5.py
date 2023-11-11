from string import digits
from random import choice

z=''.join(choice(digits) for i in range(1000))
result={}
for ch in z:
    result[ch] = result.get(ch,0)+1
for digit,fre in sorted(result.items()):
    print(digit,fre,sep=':')


text = input('请输入一个字符串')
result= ''.join(sorted(set(text),key=lambda ch:text.index(ch)))
print(result)

A=eval(input('请输入一个集合'))
B=eval(input('请输入一个集合'))
print('并集：',A|B)
print('交集',A&B)
print('对称差集',A^B)
print('差集A-B',A-B)
print('差集B-A',B-A)
