from tkinter import *

from tkinter import messagebox

top = Tk()
top.geometry=("100x200")
# messagebox.showinfo("Geetansh's Greetings","Hey this is me, Geetansh")
# messagebox.showwarning("Geetansh's Greetings","Hey this is me, Geetansh")
# messagebox.showerror("Geetansh's Greetings","Hey this is me, Geetansh")
# messagebox.askquestion("Confirm","Are you sure?")
# messagebox.askokcancel("Redirect","Redirecting to Geetansh Atrey's GitHub")
messagebox.askretrycancel("Application","Try again?")

top.mainloop()
