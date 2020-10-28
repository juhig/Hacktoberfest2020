#!/usr/bin/env python
##REVERSE A LIST

def swap(a, i, j):
    temp = a[i]
    a[i] = a[j]
    a[j] = temp
    return a

def reverse(a):
    i = 0
    while (i < len(a) / 2):
        swap(a, i, len(a) - i - 1)
        i += 1
    return a

list = [1,2,3,4]
print(reverse(list))
