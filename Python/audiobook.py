import pyttsx3 as pts 
import PyPDF2 as pyPDF
from tkinter.filedialog import *

book = askopenfilename()    #reads the file to be read.

pdfREADER = pyPDF.PdfFileReader(book) 
pages = pdfREADER.numPages



for i in range(0, pages):       #reads the words
    page = pdfREADER.getPage(i)
    text = page.extractText()

    speaker = pyttsx3.init()
    speaker.say(text)
    speaker.runAndWait()
