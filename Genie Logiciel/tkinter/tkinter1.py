from tkinter import *

window  = Tk() # Instance
window.geometry("420x420") # grandeur de la fenetre
window.title("J'essaie de codder") # changer le titre

# icon = PhotoImage(file='') # mettre le nom du logo
# window.iconphoto(True, icon) # changer l icone de la fenetre
window.config(bg="black") # tu peux utiliser hex 
if __name__ == '__main__':
    window.mainloop() # place la fenetre
