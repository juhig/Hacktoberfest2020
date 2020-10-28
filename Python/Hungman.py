ANIMALS=['ant','cow','cat','deer','dog','bat','crow','camel','bear','tiger','lion','monkey','giraffe','yak','goat','deer']
FLOWERS=['lily','daisy','tulip','lotus','rose','sunflower','marigold']
COUNTRIES=['afghanistan','australia','ameriac','argentina','bangladesh','brazil','bhutan','china','france','india','italy','russia']
BODYPART=['head','hair','eyes','ear','lips','nose','teeth','neck','hand','finger','leg','chest']
from random import *
import string

#block for selecting random word

x = randint(1,4)
if(x==1):
	k="ANIMALS"
	y = randint(0,len(ANIMALS)-1)
	n=ANIMALS[y]
	
if(x==2):
	k="FLOWERS"
	y = randint(0,len(FLOWERS)-1)
	n=FLOWERS[y]

if(x==3):
	k="COUNTRIES"
	y = randint(0,len(COUNTRIES)-1)
	n=COUNTRIES[y]
		
if(x==4):
	k="BODYPART"
	y = randint(0,len(BODYPART)-1)
	n=BODYPART[y]


#block ends here

Options=list(string.ascii_lowercase) # to make list of alphabets



name=input("What is your name? ")                                 #user interaction
print("Hello, " + name, "Time to play hangman!")
#klaus_908



def game(n,k):                                                    #game function
	print(k)
	print("The Secret Word is: \n")
	l=[]                                  #list for user interaction


	i=0
	while(i<len(n)):
		l.append('_')                     #appending underscores equal to length of secret string
		i=i+1


	for j in range(0,len(n)):              #print frame
		print(l[j],end=" ")
	print("\n")


	live=5        
	choise=1
	while(live>0 and choise<=len(n)):

		print("\nChoose From:")               #display Options
		print("\n")
		for i in range(0,len(Options)):
			print(Options[i],end=" ",)        #printing uderscore in a line
		print("\n")


		z=input("\nEnter your guess:")         #take input
		if(not z in Options):
			print("Invalid choice")                        #no decrease in life    

		if(not z in n and z in Options):                    #choise not in n and if input not in option 
			live=live-1                                     #decrease life only if valid and incorrect choice
			print('Oops! Wrong guess \n Try again\n',live,"More lives left")
			
		if z in Options:
			Options.remove(z)              #remove input from options



		if(z in n):                        #choise in n
			
			for m in range(0,len(n)):
				if(n[m]==z):
					l[m]=z
					choise=choise+1        #increase length of input string by 1 for each append

			for j in range(0,len(n)):      #print output
				print(l[j],end=" ")

					                      
	if(live==0):                           #discission
		print("\nYou Lose")

	else:
		print("\nYou Win")
	print("Secret word:",n)
game(n,k)                                   #calling game function
