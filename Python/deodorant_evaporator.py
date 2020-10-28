'''
TEXTO DO EXERCICIO EXTRAIDO DO CODE WARS
This program tests the life of an evaporator containing a gas.

We know the content of the evaporator (content in ml), the percentage of foam or gas lost every day (evap_per_day)
 and the threshold (threshold) in percentage beyond which the evaporator is no longer useful. All numbers are strictly positive.

The program reports the nth day (as an integer) on which the evaporator will be out of use.

Note : Content is in fact not necessary in the body of the function "evaporator", you can use it or not use it, as you wish. 
Some people might prefer to reason with content, some other with percentages only. 
It's up to you but you must keep it as a parameter because the tests have it as an argument.


ENUNCIADO EM PT-BR
Este programa testa a duração do gas contido dentro de uma desodorante.

Nós sabemos o conteúdo do desodorante(conteúdo em ml), o percentual da espuma ou do gás perdido todos os dias (evap_por_dia)
 e o limite (limite) em porcentagem do qual o desodorante não é mais útil. Todos os números tem de ser positivos.

 O programa reporta o enésimo dia (como um numero inteiro) onde o desodorante não terá mais uso.

 Nota: O conteúdo é da função "dedosorante" não é necessário, voce pode usá-la ou não, conforme seu interesse.
 Algumas pessoas podem preferir usar o conteúdo somente com porcentagens.
 Lembrando que você deve manter o nome da função por conta dos testes.
'''


def desodorante(conteudo, evap_por_dia, limite):
    dias = 0
    limite = conteudo * limite/100
    #print(limite)

    while conteudo >= limite:
        conteudo -= conteudo * evap_por_dia/100
        print(conteudo)
        dias = dias + 1
    return dias


#teste
assert(desodorante(10, 10, 10), 22)

'''
Solução usando biblioteca math

import math

def desodorante(conteudo, evap_por_dia, limite):
    return math.ceil(math.log(limite / 100.0) / math.log(1.0 - evap_por_dia / 100.0))
'''