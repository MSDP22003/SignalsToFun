import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
from mayplotlib.animation import FuncAnimation
##plotting live data
x_vals = [] #creating empty arrays for live data to go into
y_vals = []

index = count() #counts up by 1

def animate(i):
    x_vals.append(next(index))
    y_vals.append(random,randint(0,5))
    plt.cla() #clears axis (&legend) and makes it so that it doesnt change colors every time it updates
    plt.plot(x_vals, y_vals)
    plt.legend(loc='upper left') #dictates where the legend is located on the graph

ani = FuncAnimation(plt.gcf(), animate, interval=1000) #interval time in ms


plt.tight_layout() #adds extra padding (visual)
plt.show()

##using animation below
style.use('fivethirtyeight') #makes graph more aesthetics

fig = plt.figure()
ax1 = fig.add_subplot(1,1,1) #means the subplot is on a grid system thats 1x1

def animate(i): #i is the interval
    graph_data = open('example.txt', 'r')
    lines = graph_data.split('\n') #splitting the data by the new line
    xs = []
    ys = []
    for line in lines:
        if len(line)>1: #check for empty lines
            x, y = line.split(',') #splitting the line by a comma
            xs.append(x)
            ys.append(y)
    ax1.clear() #clears any data that was previously on the graph
    ax1.plot(xs, ys)

ani = animation.FuncAnimation(fig, animate, interval=1000) #updates the graph called fig with the function called animate every 1000 ms
plt.show()

##Below is basics of using matplotlib
x = [1,2,3]
y = [5,7,4]

x2 = [1,2,3]
y2 = [10,14,12]

plt.plot(x,y, label='First Line') #plot(x, y)
plt.plot(x2,y2, label='Second Line')
plt.xlabel('Plot Number')
plt.ylabel('Important Variable')

plt.title('Interesting Graph\nCheck it out') #\n starts a new line
plt.legend()
#you can put xlabel/ylabel/title/etc after plt.plot and before plt.show
plt.show() #allows us to see the graph
