def check_balanced(input):
    s = []
    for index in range(len(input)):
        if input[index] == '(':
            s.append('(')
        elif input[index] == '{':
            s.append('{')
        else:
            if len(s) == 0: return False
            popped = s.pop()
            if input[index] == ')' and popped != '(':
                return False
            elif input[index] == '}' and popped != '{':
                return False
    if len(s) > 0: return False
    return True

balanced = check_balanced(input('Enter a string to check: '))
print('Balanced' if balanced else 'Not balanced')