from tkinter import *

count = 0
def click():
    global count
    count+=1
    print(count)

window = Tk()
image = PhotoImage(file='cycle7-kb.png')
button = Button(window,
                text="click me",
                command=click,
                font=("Comic Sans", 30),
                fg="red",
                bg="black",
                activeforeground="red",
                activebackground="black",
                state=ACTIVE,
                image=image,
                compound="top")
button.pack()
if __name__ == '__main__':
    window.mainloop()
