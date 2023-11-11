from typing import List
import collections

print(3+5)
print(3.4+4.5)
print((3+4j)+(5+6j))
print('abc'+'def')
print([1,2]+[3,4])
print((1,2)+(3,))


print(7.9-4.5)
print(5-3)
num=3
print(-num)
print(--num)
print(-(-num))
print({1,2,3}-{3,4,5})
print({3,4,5}-{1,2,3})

print(33333*55555)
print((3+4j)*(5+6j))
print('重要的事情说三遍!'*3)
print([0]*5)
print((0,)*3)

print(17/4)
print(17//4)
print((-17)/4)
print((-17)//4)

print(365%7)
print(365%2)
print('%c,%c,%c'%(65,97,48))


print(2**4)
print(3**3**3)
print(3**(3**3))
print(9**0.5)
print((-1)**0.5)


print(3+2<7+8)
print(3<5>2)
print(3==3<5)
print('12345'>'23456')
print('abcd'>"Abcd")
print([85,92,73,84]<[91,82,73])
print([180,90,101]>[180,90,90])
print({1,2,3,4}>{3,4,5})
print({1,2,3,4}<={3,4,5})
print([1,2,3,4]>[1,2,3])

print(60 in [70,60,50,80])
print('abc' in 'a1b2c3fg')
print([3 in [[3],[4],[5]]])
print('3'in map(str,range(5)))
print(5 in range(5))

A = {35,45,55,65,75}
B = {65,75,85,95}
print(A | B)
print(A & B)
print(A - B)
print(B - A)
print(A ^ B)

print(3 in range(5) and 'abc' in 'abcdefg')
print(3-3 or 5-2)
print(not 5)
print(not [])

print(int(3.5))
print(int('119'))
print(int('1111',2))
print(int('1111',8))
print(int('1111',16))
print(int('   9\n'))
print(float('3.1415926'))
print(float('-inf'))
print(complex(3,4))
print(complex(6j))
print(complex('3'))

print(bin(8888))
print(oct(8888))
print(hex(8888))

print(ord('a'))
print(ord('董'))
print(chr(65))
print(chr(33891))
print(str([1,2,3,4]))
print(str({1,2,3,4}))

print(list(),tuple(),dict(),set())
s={3,2,1,4}
print(list(s),tuple(s))
lst=[1,1,2,2,3,4]
print(tuple(lst),set(lst))
print(list(str(lst)))
print(dict(name='dong',sex='male',age='41'))

print(eval('3+4j'))
print(eval('8**2'))
print(eval('[1,2,3,4,5]'))
print(eval('{1,2,3,4}'))

data: list[int] = [3, 22, 111]
print(data)
print(max(data))
print(min(data))
print(max(data,key=str))
data = ['3', '22', '111']
print(max(data))

print(max(data,key=len))
data=['abc', 'Abcd', 'ab']
print(max(data))
print(max(data,key=str.lower))
data = [1,1,1,2,2,1,3,1]
print(max(set(data),key=data.count))
print(max(range(len(data)),key=data.__getitem__))

data=[1,2,3,4]
print(len(data))
print(sum(data))
print(1, 2,3)
print(len(data))
print(sum(data))

data={1,2,3}
print(len(data))
print(sum(data))
data = 'Readability counts.'
print(len(data))
data={97: 'a',65:'A',48:'0'}
print(len(data))
print(sum(data))
from random import shuffle

data = list(range(20))
shuffle(data)
print(data)
print(sorted(data))
print(sorted(data, key=str))
print(sorted(data,key=str,reverse = True))

data=list(range(20))
shuffle(data)
print(data)
reversedData = reversed(data)
print(reversedData)
print(list(reversedData))
print(tuple(reversedData))