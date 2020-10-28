def calHCF(a,b):
     if a == 0:
        return b
     else:
        return calHCF(b % a, a)
    
if __name__ == '__main__':
    n = int(input())
    arr = list(map(int,input().split()))
    hcf = calHCF(arr[0],arr[1])
    lcm = arr[0]
    for i in range(2,n):
        hcf = calHCF(hcf,arr[i])
    for i in range(1,n):
        lcm = lcm*arr[i]/calHCF(lcm,arr[i])
    print(f"HCF is : {hcf}")
    print(f"LCM is : {int(lcm)}")



