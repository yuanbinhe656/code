import random
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm

data = {
'蔬菜':
[1350,1500,1330,1550,900,1400,980,1100,1370,1250,1000,1100],
'水果': [400,600,580,620,700,650,860,900,880,900,600,600],
'肉类': [480,700,370,440,500,400,360,380,480,600,600,400],
'日用':
[1100,1400,1040,1300,1200,1300,1000,1200,950,1000,900,950],
'衣服': [650,3500,0,300,300,3000,1400,500,800,2000,0,0],
'旅游': [4000,1800,0,0,0,0,0,4000,0,0,0,0],
'随礼': [0,4000,0,600,0,1000,600,1800,800,0,0,1000]
}
dataLength =len(data['蔬菜'])

angles =np.linspace(0,2*np.pi,dataLength,endpoint=False)
makers='v^Do'
for col in data.keys():
    color='#'+".join(map('{0.02x}.format,