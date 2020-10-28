x = input()
n = len(x)
i=0
j=n-1
while i<j:
   if x[i]!=x[j]:
      return False
   i+=1
   j-=1
return True
