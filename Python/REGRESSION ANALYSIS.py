import numpy as np
import matplotlib.pyplot as plt
x=np.array([0,1,2,3,4,5,6,7,8,9])
y=np.array([1,3,5,6,7,9,10,12,13,15])
n = np.size(x)
mean_x = np.mean(x)
mean_y = np.mean(y)
a=((np.sum(y*np.sum(x*x))-np.sum(x*np.sum(x*y)))/((n*np.sum(x*x))-(np.sum(x*x))))
b=(((n*sum(x*y))-(np.sum(x)*np.sum(y)))/((n*np.sum(x*x))-(np.sum(x*x))))
print("y = {} + {}x".format(a,b))
plt.scatter(x, y, color = "b", marker = "*", s = 30) 
y_out = a + b*x #y = mx+c
plt.plot(x,y_out,color="r")
plt.xlabel("X axis")
plt.ylabel("Y label")
plt.show()
