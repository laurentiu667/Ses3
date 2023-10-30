from tkinter import *
def create_window():
    new_window = Tk() # new window on top of other windows #tl() new independent window
    old_root.destroy() # close out of old window

old_root = Tk()

Button(old_root, text="create a new window", command=create_window).pack()

old_root.mainloop()