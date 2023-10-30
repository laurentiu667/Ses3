from tkinter import *

window = Tk()
image = PhotoImage(file='cycle7-kb.png')
label = Label(window,
              text="Cycle7asdfvdfgvesfefdsfdsfsdfsdf",
              font=('Arial', 40, 'bold'),
              fg="green",
              bg="black",
              bd=10,
              padx=20,
              pady=20,
              image=image,
              compound="bottom"
              )

label.pack()
if __name__ == '__main__':
    window.mainloop()
