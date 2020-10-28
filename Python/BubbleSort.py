def bubbleSort(arr):
  for i in range(0,len(arr)-1):
    sorted=True                     
    for j in range(0,len(arr)-1-i): 
      if arr[j]>arr[j+1]:
        arr[j],arr[j+1]=arr[j+1],arr[j]
        sorted=False
    
    if sorted:
      break    
      
  return arr      

arr=[int(x) for x in input().split()]
bubbleSort(arr)
print(arr)
