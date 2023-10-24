from tkinter import *
from tkinter import ttk

from helper import Helper as hp

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
        self.largeur = (self.x2 - self.x1) / 2
        self.hauteur = (self.y2 - self.y1) / 2
        self.vitesse = 5
        self.angle = 45

        self.couleur = couleur

    def collision_carre_rouge(self, x, y, largeur):
        carre_x1 = x - largeur
        carre_x2 = x + largeur
        carre_y1 = y - largeur
        carre_y2 = y + largeur

        return self.x1 <= carre_x2 and carre_x1 <= self.x2 and self.y1 <= carre_y2 and carre_y1 <= self.y2

    def jouer_coup(self):
        x = (self.x2 - self.x1) / 2 + self.x1
        y = (self.y2 - self.y1) / 2 + self.y1
        x1, y1 = hp.getAngledPoint(self.angle, self.vitesse, x, y)
        self.x1 = x - self.largeur
        self.x2 = x + self.largeur
        self.y1 = x - self.hauteur
        self.y2 = x + self.hauteur

class Vue():
    def __init__(self, parent, modele):
        self.vue = parent
        self.modele = modele
        self.root = Tk()
        self.canevas = Canvas(self.root, width="450", height="450", bg="black")
        self.canevas.pack()

    #def creer_menu(self):
        #self.menu = []

        #self.canevas.create_rectangle(50, 100, 100, 150, fill="white")
        #self.menu.append(self.canevas.create_text(225, 125, text="Commencer la partie", fill="red"))
        #self.menu.append(self.canevas.create_text(225, 125, text="Commencer la partie", fill="red"))
        #self.menu.append(self.canevas.create_text(225, 125, text="Commencer la partie", fill="red"))

    def creer_page_jeu(self):
        self.canvas = Canvas(self.cadre_jeu, width=450, height=450, bg="white")
        self.canvas.pack()

        self.canvas.bind("<B1-Motion>", self.deplacer_carre)
        self.afficher_carre_rouge()
        self.afficher_pions()

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
    def jouer_coup(self):
        for i in self.pions:
            i.jouer_coup()


class Controleur():
    def __init__(self):
        self.modele = Modele(self)
        self.vue = Vue(self, self.modele)
        self.vue.creer_page_jeu()
        self.vue.root.mainloop()


    #def boucle_jeux(self):
        #self.modele.jouer_coup()
        #self.vue.afficher_bloc()
        #self.vue.root.after(50, self.boucle_jeux())


if __name__ == '__main__':
    c = Controleur()