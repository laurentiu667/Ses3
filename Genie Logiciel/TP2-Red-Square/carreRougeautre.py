from tkinter import *

class Carre():
    def __init__(self):
        self.largeur = 25
        self.hauteur = 25
        self.couleur = "red"

class Pion():
    def __init__(self, x1, y1, x2, y2, couleur):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.couleur = couleur

class Vue():
    def __init__(self, parent, modele):
        self.vue = parent
        self.modele = modele
        self.root = Tk()
        self.creer_page_jeu()
        self.canvas.bind("<B1-Motion>", self.deplacer_carre)

    def afficher_demarrage(self):
        self.cadre_jeu.pack()

    def creer_page_jeu(self):
        self.cadre_jeu = Frame(self.root, width=800, height=800, borderwidth=50, bg="black")
        self.cadre_jeu.pack()

        self.canvas = Canvas(self.cadre_jeu, width=450, height=450, bg="white")
        self.canvas.pack()

    def afficher_carre_rouge(self):

        x = (self.canvas.winfo_reqwidth() - self.modele.carre.largeur) / 2
        y = (self.canvas.winfo_reqheight() - self.modele.carre.hauteur) / 2

        self.canvas.create_rectangle(x,
                                     y,
                                     x + (self.modele.carre.largeur * 2),
                                     y + (self.modele.carre.hauteur * 2),
                                     fill=self.modele.carre.couleur,
                                     tags="carre_rouge")

    def contact_carre_rouge_bordure(self):
        x1, y1, x2, y2 = self.canvas.coords("carre_rouge")
        canvas_width = self.canvas.winfo_reqwidth()
        canvas_height = self.canvas.winfo_reqheight()

        # contact avec bordure
        if x1 <= 0 or x2 >= canvas_width or y1 <= 0 or y2 >= canvas_height:
            self.root.quit()

    def contact_pions_carre_rouge(self):
        pass
    def deplacer_carre(self, event=None):
        self.canvas.delete("carre_rouge")
        if event:
            self.canvas.create_rectangle(event.x - self.modele.carre.largeur,
                                         event.y - self.modele.carre.hauteur,
                                         event.x + self.modele.carre.largeur,
                                         event.y + self.modele.carre.hauteur,
                                         fill=self.modele.carre.couleur,
                                         tags="carre_rouge")
            self.contact_carre_rouge_bordure()

    def afficher_pions(self):
        pions = [Pion(40, 40, 100, 100, "blue"), Pion(340, 35, 400, 85, "blue"),
                 Pion(35, 390, 65, 450, "blue"), Pion(350, 380, 450, 400, "blue")]

        for pion in pions:
            self.canvas.create_rectangle(pion.x1, pion.y1, pion.x2, pion.y2, fill=pion.couleur)

class Modele():
    def __init__(self, parent):
        self.modele = parent  # controleur
        self.largeur = 800
        self.hauteur = 800
        self.carre = Carre()

class Controleur():
    def __init__(self):
        self.modele = Modele(self)
        self.vue = Vue(self, self.modele)
        self.vue.afficher_demarrage()
        self.vue.afficher_carre_rouge()
        self.vue.afficher_pions()
        self.vue.root.mainloop()

if __name__ == '__main__':
    c = Controleur()
