# Input is any string. The idea is to find the first non-repeating character in it, and return its position
# Input is lowercase. If it doesn't exist, it will return -1.

# First solution
def character(s):
    freq = {}
    for i in s:
        if i not in freq:
            freq[i] = 1
        else:
            freq[i] +=1
    for i in range(len(s)):
        if freq[s[i]] == 1:
            return i
    return -1

# Second solution
import collections

def character(s):
    # Build a dict with words and occurrence
    count = collections.Counter(s) # <-- returns a dict with words occurrence

    # Finds the index
    for idx, ch in enumerate(s):
        if count[ch] == 1:
            return idx     
    return -1
