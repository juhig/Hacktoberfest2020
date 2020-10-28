def roman_to_int(s):

        d = [(1000,'M'), (900,'CM'), (500,'D'), (400, 'CD'), (100, 'C'), (90, 'XC'), \
        (50, 'L'), (40, 'XL'), (10, 'X'), (9, 'IX'), (5,'V'), (4, 'IV'), (1, 'I')]  
        
        dic = {k[1]:k[0] for k in d}
        
        n = len(s)
        res = 0
        i  = 0
        while i < n:
            if s[i]== 'I':
                if i+1 < n and s[i+1] in ['V', 'X']:
                    res += dic[s[i:i+2]]
                    i+= 1
                else:
                    res += dic[s[i]]
            elif s[i]=='X':
                if i+1 < n and s[i+1] in ['L', 'C']:
                    res += dic[s[i:i+2]]
                    i+= 1
                else:
                    res += dic[s[i]]
            elif s[i] == 'C':
                if i+1 < n and s[i+1] in ['D', 'M']:
                    res += dic[s[i:i+2]]
                    i+= 1
                else:
                    res += dic[s[i]]
            else:
                res +=  dic[s[i]]
            i+=1 
        
        return res

print(roman_to_int("MCMXCIV")) # should return 1994
print(roman_to_int("LIX")) # should return 59
        
