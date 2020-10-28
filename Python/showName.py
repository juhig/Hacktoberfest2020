#program that prints the users name
def main():
    name = input('Enter your name: ')
    age = int(input('Enter your age: '))
    if age < 0:
        print('Interesting')
    else:
        print('Your name is ' + name + " and you are " + str(age) + ' years old!')

main()