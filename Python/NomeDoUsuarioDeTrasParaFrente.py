
print('O nome pode ser digitado com letras maiúsculas, minúsculas ou mistas.')

nome = input('Digite o nome do usúario: ').upper()

invNome = nome[::-1]

print('{} ---> {}'.format(nome, invNome))
