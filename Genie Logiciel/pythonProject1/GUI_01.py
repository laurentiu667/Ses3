import tkinter
from tkinter import *

# Tk son travail est de initialiser le parametre graphique
root = Tk()

def identifier_usager():
    txt = ent1.get()
    ent2.insert(END, txt)
    ent2.insert(END, txt)
    print(txt)
def effacer_donneer():
    ent2.delete(0, END)

btn1 = Button(root, text="Identifier", command=identifier_usager)
ent1 = Entry(root)
lab1 = Label(root, text="Inscire vitre nom SVP ")
ent2 = Entry(root)

btn2 = Button(root, text="Effacer", command=effacer_donneer)

lab1.pack()
ent1.pack()
btn1.pack()
ent2.pack()
btn2.pack()

# mainloop sert a garder la fenetre ouverte en boucle
root.mainloop()