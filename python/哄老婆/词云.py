import wordcloud
import jieba
from imageio.v2 import imread
mk=imread("R-C.jfif")

txt="最 爱 小 冠 冠 了 "

w=wordcloud.WordCloud(font_path='msyh.ttc',mask=mk,background_color="white")
#w=wordcloud.WordCloud(font_path='msyh.ttc',width=1000,height=700,background_color="white")
w.generate(txt)
w.to_file("yiqingjiayou.png")