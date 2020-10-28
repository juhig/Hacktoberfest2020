import random
import time
import sys


option = input("Enter e for encryption, d for decryption : ")
if (option == 'e' or option == 'E'):
    letters = 'abcdefghijklmnopqrstuvwxyz'
    random.seed(time.time)
    rstring = "".join(random.choice(letters) for x in range(6))
    key = random.randint(5,10)
    plaintxt = input("Enter plaintext : ")
    plaintxt.lower()
    plaintxt = rstring + plaintxt
    print("cipher = ",end = '') 
    for ch in plaintxt:
        if(ch == ' '):
            print(' ' , end = '')
        elif(ord(ch)+key > 122):
            print(chr(ord(ch)+key-122),end = '')
        else:
            print(chr(ord(ch)+key),end = '')
    print("\n Key = ",key)
elif (option == 'd' or option =='D'):
    key = int(input("Enter key : "))
    code = input("Enter cipher : ")
    print("plaintext = ",end = '')
    for ch in code[6:]:
        if(ch == ' '):
            print(' ',end = '')
        elif(ord(ch)-key < 97):
            print(chr(ord(ch)-key+122),end = '')
        else:
            print(chr(ord(ch)-key),end = '')
else:
    print("Error!! exiting...")
    time.sleep(5)
    sys.exit()
