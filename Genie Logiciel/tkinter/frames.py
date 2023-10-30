from tkinter import *
# frame c est un contenant div ou tu peux regrouper des buttons n importe quoi
root = Tk()

frame = Frame(root, bg='pink', bd=5, relief=SUNKEN) # c est comme un contenant un genre de div
frame.place(x=100, y=100)
Button(frame, text="W", width=10, height=3).pack(side=TOP)
Button(frame, text="A", width=10, height=3).pack(side=LEFT)
Button(frame, text="S", width=10, height=3).pack(side=LEFT)
Button(frame, text="D", width=10, height=3).pack(side=LEFT)
root.mainloop()