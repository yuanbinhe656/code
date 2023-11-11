#-*- coding:utf-8 -*-
#wlj@2020/2/13 21:17
#用中文汉字填充，实现彩色字符画
#用法 python img2txt.py [源文件] [目标文件]
#如 python img2txt.py 1.jpeg 1 会输入一个1.png文件，目标文件不需要带后缀名
from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
import sys

txt = '最爱小冠冠了' #填充的汉字
font_size = 15 #字体的大小
font = ImageFont.truetype('simkai.ttf',font_size)  #设置字体
im_path = '郑州.png'  #原图路径
im = Image.open(im_path)
width, height = im.size
newImg = Image.new("RGBA",(width, height),(255,255,255))  #背景色rgb，偏黑显示好一些
x=0
for i in range(0,height,font_size):   #需要与字体大小一致
    for j in range(0,width,font_size): #需要与字体大小一致
        a,b,c,d = im.getpixel((j,i))
        draw = ImageDraw.Draw(newImg)
        if(a==b==c==255):
            draw.text((j, i), ' ', fill=(a, a, a), font=font)
        else:
            draw.text((j,i), txt[x%len(txt)], fill=(a,b,c),font=font)
        x+=1
        del draw
newImg.save("output.png" ,'PNG')