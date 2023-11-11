import wordcloud
import jieba
from imageio.v2 import imread
mk=imread("郑州.png")
c = [' ']
love="最爱小冠冠了"
for i in range(0,10):
    for j in love:
        c.append(j)

txt=' '.join(c)

w=wordcloud.WordCloud(font_path='msyh.ttc',mask=mk,background_color="white")
#w=wordcloud.WordCloud(font_path='msyh.ttc',width=1000,height=700,background_color="white")
w.generate(txt)
w.to_file("yiqingjiayoua.png")