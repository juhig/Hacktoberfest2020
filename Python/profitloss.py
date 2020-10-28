cp=int(input("Enter cost price:"))
sp=int(input("Enter Selling price:"))
if(cp<sp):
	print("Profit",end="")
elif(cp>sp):
	print("Loss",end="")
else:
	print("Neither",end="")
