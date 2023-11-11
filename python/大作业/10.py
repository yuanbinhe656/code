import numpy as np
import math
import matplotlib.pyplot as plt

fig = plt.figure(figsize=(10, 6))

ax = plt.subplot(111, polar=True)

ax.set_theta_direction(-1)

ax.set_theta_zero_location('N')

r = np.arange(100, 800, 20)

theta = np.linspace(0, np.pi * 2, len(r), endpoint=False)

ax.bar(theta, r,

       width=0.18,

       color=np.random.random((len(r), 3)),
       align='edge',
       bottom=100)


ax.text(np.pi * 3 / 2 - 0.2, 90, 'Origin', fontsize=14)

for angle, height in zip(theta, r):
    if math.degrees(angle) >= 180:
        ax.text(angle + 0.03, height + 105, str(height), fontsize=height / 80,
                rotation=-(math.degrees(angle) + 90))
    else:
        ax.text(angle + 0.03, height + 105, str(height), fontsize=height / 80,
                rotation=-(math.degrees(angle) + 270))

plt.axis('off')
plt.tight_layout()

plt.savefig('polarBar.png', dpi=480)
plt.show()
