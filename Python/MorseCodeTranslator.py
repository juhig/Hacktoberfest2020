import winsound
import time

def morse_code():
        dictionary_morse = {
        "a": ".-",
        "b": "-...",
        "c": "-.-.",
        "d": "-..",
        "e": ".",
        "f": "..-.",
        "g": "--.",
        "h": "....",
        "i": "..",
        "j": ".---",
        "k": "-.-",
        "l": ".-..",
        "m": "--",
        "n": "-.",
        "o": "---",
        "p": ".--.",
        "q": "--.-",
        "r": ".-.",
        "s": "...",
        "t": "-",
        "u": "..-",
        "v": "...-",
        "w": ".--",
        "x": "-..-",
        "y": "-.--",
        "z": "--..",
        " ": " ",
        "1": ".----",
        "2": "..---",
        "3": "...--",
        "4": "....-",
        "5": ".....",
        "6": "-....",
        "7": "--...",
        "8": "---..",
        "9": "----.",
        "0": "-----",
        ".": ".-.-.-"
        }
        return dictionary_morse

def dot():
    winsound.Beep(1000, 100) 

def dash():
    winsound.Beep(1000, 500)


print("Press '*' to recieve a list of Morse Code translations")

while True:
  text = input("What phrase do you want in Morse Code?\n")

  dictionary = morse_code()

  while text == "*":
    for i in dictionary:
      print(i, dictionary[i])
    text = input("What phrase do you want in Morse Code?\n") 

  i = -1
  text = text.lower()
  while i != len(text) - 1:
    text = text.lower()
    try:
      i += 1
      z = dictionary[text[i]]
    except:
      text = input("Please enter a valid statement with only letters and numbers.\n")
      i = -1

  while bool(text) is False:
    text = input("Please enter a valid statement with only letters and numbers.\n")

  translation = ""
  
  for i in text:
    translation += str(dictionary[i])
    
  print(translation)
  
  for t in translation:
      if t == ".":
          dot()
      elif t == "-":
          dash()
      elif t == " ":
          time.sleep(1)
      time.sleep(0.5)

  repeat = input("\nWould you like to repeat this? (Y/N)\n")

  while repeat == "*":
      for i in dictionary:
        print(i, dictionary[i])
      repeat = input("Would you like to repeat this? (Y/N)\n")

  if repeat == "Y" or repeat == "y":
      continue
  else:
      break
