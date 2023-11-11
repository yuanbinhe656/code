import os  
  
def get_folder_size(folder):  
    size = 0  
    for file in os.listdir(folder):  
        path = os.path.join(folder, file)  
        if os.path.isdir(path):  
            size += get_folder_size(path)  
        else:  
            size += os.path.getsize(path)  
    return size  
  
def main():  
    folder = input("请输入要统计的目录：")  
    if os.path.exists(folder):  
        size = get_folder_size(folder)  
        print(f"目录 '{folder}' 的大小为：{size / 1024 / 1024} MB")  
    else:  
        print("目录不存在！")  
  
if __name__ == '__main__':  
    main()