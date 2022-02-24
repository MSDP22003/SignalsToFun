import matplotlib.pyplot as plt
x = [1, 2, 3]
y = [4, 6, 9]

fig, (ax1, ax2) = plt.subplots(2, sharex=True)
fig.suptitle('Aligning x-axis using sharex')

ax1.plot(x, y)
ax2.plot(x, y)

plt.show()
