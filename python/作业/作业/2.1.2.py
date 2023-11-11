x_list = [1, 2, 3]
x_tuple = (1, 2, 3)
x_dict = {'a' : 97, 'b' : 98, 'c' : 99}
x_set = {1, 2, 3}
print(x_list[1])
print(x_tuple[1])
print(x_dict['c'])
print(len(x_list))
print(x_tuple.index(2))
for key ,value in x_dict.items():
    if value==98:
        print(key)
print(max(x_set))