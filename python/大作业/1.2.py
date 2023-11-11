import wordcloud
import jieba
from imageio.v2 import imread
mk=imread("doctor.jpg")
f=open("中共中央关于党的百年奋斗重大成就和历史经验的决议.txt",encoding="utf-8")
text=f.read()
f.close()
ls=jieba.lcut(text)
txt=" ".join(ls)

w=wordcloud.WordCloud(font_path='msyh.ttc',mask=mk,background_color="white")
#w=wordcloud.WordCloud(font_path='msyh.ttc',width=1000,height=700,background_color="white")
w.generate(txt)
w.to_file("yiqingjiayou.png")