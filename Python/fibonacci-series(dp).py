#Using Dynamic Programming for Fibonacci Series
#To output the nth term in fibonacci series
#defining a method fib
def fib(n: int):
    #taking a variable "a" 
    a = [0,0,1]
    for i in range(3,n+1):
        a.append(a[i-1]+a[i-2])
    return a

upperCount = int(input("Enter the count of fibonacci series: "))
fibList = fib(upperCount)
print("First {} numbers of Fibonacci Series are: ".format(upperCount))
for i in range(1, len(fibList)):
              print(" {0} ".format(fibList[i]),end = "")
    
