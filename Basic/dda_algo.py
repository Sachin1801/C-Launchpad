import matplotlib.pyplot as plt

print("Enter the value of x1: ")
x1 = int(input())
print("Enter the value of x2: ")
x2 = int(input())
print("Enter the value of y1: ")
y1 = int(input())
print("Enter the value of y2: ")
y2 = int(input())
x=x1
y=y1
dx = x2 - x1
dy = y2 - y1
m= dy/dx
p = 2*dx - dy

xcoordinates=[]
ycoordinates=[]

if m<1:
    while x<=x2:
        xcoordinates.append(x)
        ycoordinates.append(y)
        print("x1: ", x, "y1: ", y)
        x = x + 1
        if p<0:
            p = p + 2*dy
        else:
            p = p + 2*dy - 2*dx
            y = y + 1
else:
    while y<=y2:
        xcoordinates.append(x)
        ycoordinates.append(y)
        print("x1: ", x, "y1: ", y)
        y = y + 1
        if p<0:
            p = p + 2*dx
        else:
            p = p + 2*dx - 2*dy
            x = x + 1

plt.plot(xcoordinates,ycoordinates)
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Bresenham Algorithm')
plt.show()