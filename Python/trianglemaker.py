def triangle(n): 
    for i in range(n):
        print(f"{' ' * (n-i)}{'*' * (i)}")
    for i in range(n):
        print(f"{' ' * i}{'*' * (n-i)}")

triangle(13)