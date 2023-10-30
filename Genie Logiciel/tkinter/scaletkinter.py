from tkinter import *


def submit():
    print("The temperature is : " + str(scale.get()) + " degree C")
root = Tk()

scale = Scale(root,from_=100,
              to=0,
              length=600,
              orient=VERTICAL, # orientation
              font = ('Consolas', 20),
              tickinterval=10,
              #showvalue = 1,
              resolution=5,
              troughcolor= 'black',
              fg="#FF1C00",
              bg="black")
scale.set(((scale['from']-scale['to'])/2)+scale['to'])
button = Button(root, text="submit", command=submit)
scale.pack()
button.pack()
root.mainloop()