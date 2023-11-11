text=input('请输入一个包含空格的字符')
print(''.join(text.split()))

text=input('请输入一个字符串')
table=''.maketrans('aeoiu','AEOIU')
print(text.translate(table))

