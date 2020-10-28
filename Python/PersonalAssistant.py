# Importing google Speech Recognition Module
import speech_recognition as sr
# Importing Wikipedia Module
import wikipedia

# get audio from the microphone
with sr.Microphone() as source:
    print("Hello! \nThis is Jarvis. \nHow can i help you?")
    audio = sr.Recognizer().listen(source)

query = sr.Recognizer().recognize_google(audio)
LCQ_list = [""]

while "thanks" not in LCQ_list:
    try:
        # get audio from the microphone
        with sr.Microphone() as src:
            ques = sr.Recognizer().listen(src)

        Qasked = sr.Recognizer().recognize_google(ques)
        print('Searching Wikipedia.....')
        results = wikipedia.summary(Qasked, sentences=1)
        print("According to Wikipedia,")
        print(results)
        print("Say thanks to stop searching.")

        LCquery = Qasked.lower()  # Converts the query in to lower case
        LCQ_list = list(LCquery.split())

    except sr.UnknownValueError:
        print("Sorry, I couldn't understand what you were trying to say. Please try again.")
    except sr.RequestError as error:
        print("Could not request results; {0}".format(error))

print("Hope I could help you. Bye!")
