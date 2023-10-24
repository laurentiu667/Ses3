from tkinter import *
from tkinter import ttk
class Carre():
    def __init__(self):
        self.largeur = 25
        self.hauteur = 25
        self.variation = 0
        self.couleur = "red"

    def collision_bordure(self, canvas_width, canvas_height, x, y):
        x1 = x - self.largeur
        y1 = y - self.hauteur
        x2 = x + self.largeur
        y2 = y + self.hauteur

        return x1 < 0 or x2 > canvas_width or y1 < 0 or y2 > canvas_height

class Pion():
    def __init__(self, x1, y1, x2, y2, couleur):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.couleur = couleur

    def collision_carre_rouge(self, x, y, largeur):
        carre_x1 = x - largeur
        carre_x2 = x + largeur
        carre_y1 = y - largeur
        carre_y2 = y + largeur

        return self.x1 <= carre_x2 and carre_x1 <= self.x2 and self.y1 <= carre_y2 and carre_y1 <= self.y2


class Vue():
    def __init__(self, parent, modele):
        self.vue = parent
        self.modele = modele
        self.root = Tk()
        self.creer_page_jeu()
        self.creer_page_menu()
        

    def afficher_demarrage(self):
        self.cadre_jeu.pack()
        
        
    def creer_page_jeu(self):
        win= Tk()

        #Set the geometry of Tkinter frame
        win.geometry("750x250")

        def display_text():
            global entry
            string= entry.get()
            label.configure(text=string)

        #Initialize a Label to display the User Input
        label=Label(win, text="", font=("Courier 22 bold"))
        label.pack()

        #Create an Entry widget to accept User Input
        entry= Entry(win, width= 40)
        entry.focus_set()
        entry.pack()

        #Create a Button to validate Entry Widget
        ttk.Button(win, text= "Okay",width= 20, command= display_text).pack(pady=20)

        win.mainloop()
       
    #def creer_page_jeu(self):
        #self.cadre_jeu = Frame(self.root, borderwidth=40, bg="black")
        #self.cadre_jeu.pack()

        #self.canvas = Canvas(self.cadre_jeu, width=450, height=450, bg="white")
        #self.canvas.pack()

        #self.canvas.bind("<B1-Motion>", self.deplacer_carre)
        #self.afficher_carre_rouge()
        #self.afficher_pions()
        #self.root.mainloop()
        

    def afficher_carre_rouge(self):
        x = (self.canvas.winfo_reqwidth() - self.modele.carre.largeur) / 2
        y = (self.canvas.winfo_reqheight() - self.modele.carre.hauteur) / 2

        self.canvas.create_rectangle(x,
                                     y,
                                     x + (self.modele.carre.largeur * 2),
                                     y + (self.modele.carre.hauteur * 2),
                                     fill=self.modele.carre.couleur,
                                     tags="carre_rouge")

    def deplacer_carre(self, event=None):
        self.canvas.delete("carre_rouge")
        if event:
            x = event.x
            y = event.y

            if self.modele.carre.collision_bordure(self.canvas.winfo_reqwidth(), self.canvas.winfo_reqheight(), x, y):
                self.root.quit()

            for pion in self.modele.pions:
                if pion.collision_carre_rouge(x, y, self.modele.carre.largeur):
                    self.root.quit()

            self.canvas.create_rectangle(x - self.modele.carre.largeur,
                                         y - self.modele.carre.hauteur,
                                         x + self.modele.carre.largeur,
                                         y + self.modele.carre.hauteur,
                                         fill=self.modele.carre.couleur,
                                         tags="carre_rouge")

    def afficher_pions(self):
        for pion in self.modele.pions:
            self.canvas.create_rectangle(pion.x1, pion.y1, pion.x2, pion.y2, fill=pion.couleur)


class Modele():
    def __init__(self, parent):
        self.modele = parent  # Contrôleur
        self.largeur = 800
        self.hauteur = 800
        self.carre = Carre()
        self.pions = [Pion(40, 40, 100, 100, "blue"), Pion(340, 35, 400, 85, "blue"),
                     Pion(35, 390, 65, 450, "blue"), Pion(360, 380, 400, 400, "blue")]

class Controleur():
    def __init__(self):
        self.modele = Modele(self)
        self.vue = Vue(self, self.modele)
        self.vue.afficher_demarrage()

if __name__ == '__main__':
    c = Controleur()