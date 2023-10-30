from tkinter import *

def submit():
    username = entry.get()
    print(username)
    entry.config(state=DISABLED) # si tu clique sur submit tu ne peux plus ecrire
def delete():
    entry.delete(0, END)
def backspace():
    entry.delete(len(entry.get())-1, END) # retirer caractere par caractere
window = Tk()

entry = Entry(window, font=("Arial", 50),
              fg="#00FF00",
              bg="black",
              show="*")
#entry.insert(0, "Spongebob")
entry.pack(side=LEFT)
submit_button = Button(window, text="submit", command=submit)
submit_button.pack(side=RIGHT)

delete_button = Button(window, text="delete", command=delete)
delete_button.pack(side=RIGHT)

backspace_button = Button(window, text="backspace", command=backspace)
backspace_button.pack(side=RIGHT)


if __name__ == '__main__':
    window.mainloop()
