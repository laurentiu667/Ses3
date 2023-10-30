from tkinter import *


def display():
    if(x.get()):
        print("You agree!")
    else:
        print("You dont agree")
root = Tk()

x = BooleanVar()
check_button = Checkbutton(root, text="I agree",
                           variable=x,
                           onvalue=True,
                           offvalue=False,
                           command=display,
                           font=('Arial', 20),
                           fg='#00FF00',
                           bg='black',
                           activebackground="black",
                           activeforeground="#00FF00")
check_button.pack()
root.mainloop()