from tkinter import *
from math import sqrt
from helper import Helper as hp
import time

class Carre():
    def __init__(self):
        self.largeur = 25
        self.hauteur = 25
        self.variation = 0
        self.couleur = "red"
        self.x = (450 - self.largeur) / 2
        self.y = (450 - self.hauteur) / 2

    def collision(self, canvas_width, canvas_height):
        x1 = self.x - self.largeur
        y1 = self.y - self.hauteur
        x2 = self.x + self.largeur
        y2 = self.y + self.hauteur
        return x1 < 0 or x2 > canvas_width or y1 < 0 or y2 > canvas_height

    def collision_pions(self,pion_x1,pion_x2,pion_y1,pion_y2):
        x1 = self.x - self.largeur
        y1 = self.y - self.hauteur
        x2 = self.x + self.largeur
        y2 = self.y + self.hauteur

        return pion_x1 <= x2 and x1 <= pion_x2 and pion_y1 <= y2 and y1 <=pion_y2

class Pion():
    def __init__(self, x1, y1, x2, y2, couleur, tag):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.largeur = (self.x2 - self.x1) / 2
        self.hauteur = (self.y2 - self.y1) / 2
        self.tag = tag
        self.couleur = couleur
        self.vitesse = 5
        self.angle = 45

    def jouer_coup(self):
        x = (self.x2 - self.x1) / 2 +self.x1
        y = (self.y2 - self.y1) / 2 + self.y1
        x1, y1 = hp.getAngledPoint(self.angle,self.vitesse,x,y)
        self.x1 = x1 - self.largeur
        self.x2 = x1 + self.largeur
        self.y1 = y1 - self.hauteur
        self.y2 = y1 + self.hauteur

    def collision_mur(self, canvas_width, canvas_height):
        if self.x1 <= 0 or self.x2 >= canvas_width:
            self.vitesse = -self.vitesse
            self.angle = -self.angle
        if self.y1 <= 0 or self.y2 >= canvas_height:
            self.angle = -self.angle

class Vue():
    def __init__(self, parent, modele):
        self.vue = parent
        self.modele = modele
        self.root = Tk()
        self.creer_page_jeu()

    def afficher_demarrage(self):
        self.cadre_jeu.pack()

    def afficher_bloc(self):
        for eff in self.modele.pions:
            self.canvas.delete(eff.tag)
        self.canvas.bind("<B1-Motion>", self.deplacer_carre)
        for col in self.modele.pions:
            col.collision_mur(self.canvas.winfo_reqwidth(), self.canvas.winfo_reqheight())
        self.afficher_carre_rouge()
        self.afficher_pions()

    def score(self):
        if self.modele.carre.collision(self.canvas.winfo_reqwidth(), self.canvas.winfo_reqheight()):
            self.modele.temp_fin = time.time()
            print(self.modele.temp_fin - self.modele.temps_debut)
            self.root.quit()
        for pio in self.modele.pions:
            if self.modele.carre.collision_pions(pio.x1, pio.x2, pio.y1, pio.y2) and self.modele.carre.collision:
                self.modele.temp_fin = time.time()
                print(self.modele.temp_fin - self.modele.temps_debut)
                self.root.quit()


    def creer_page_jeu(self):
        self.cadre_jeu = Frame(self.root, borderwidth=40, bg="black")
        self.cadre_jeu.pack()

        self.canvas = Canvas(self.cadre_jeu, width=450, height=450, bg="white")
        self.canvas.pack()

    def afficher_carre_rouge(self):
        x = (self.canvas.winfo_reqwidth() - self.modele.carre.largeur) / 2
        y = (self.canvas.winfo_reqheight() - self.modele.carre.hauteur) / 2

        self.canvas.create_rectangle(self.modele.carre.x - self.modele.carre.largeur,
                                         self.modele.carre.y - self.modele.carre.hauteur,
                                         self.modele.carre.x + self.modele.carre.largeur,
                                         self.modele.carre.y + self.modele.carre.hauteur,
                                         fill=self.modele.carre.couleur,
                                         tags="carre_rouge")

    def distance_souris_carre(self, event, x, y):
        # Calculez la distance entre la position de la souris (event.x, event.y) et le centre du carré (x, y)
        dx = x - event.x
        dy = y - event.y
        return sqrt(dx**2 + dy**2)

    def deplacer_carre(self, event=None):
        x_centre_carre, y_centre_carre = self.canvas.coords("carre_rouge")[0] + self.modele.carre.largeur, \
                                         self.canvas.coords("carre_rouge")[1] + self.modele.carre.hauteur

        if event and self.distance_souris_carre(event, x_centre_carre, y_centre_carre) <= 25:
            self.canvas.delete("carre_rouge")
            self.modele.carre.x = event.x
            self.modele.carre.y = event.y
            self.afficher_carre_rouge()

    def afficher_pions(self):
        for pion in self.modele.pions:
            self.canvas.create_rectangle(pion.x1, pion.y1, pion.x2, pion.y2, fill=pion.couleur, tags=pion.tag)

    def score(self):
        if self.modele.carre.collision(self.canvas.winfo_reqwidth(), self.canvas.winfo_reqheight()):
            self.modele.temp_fin = time.time()
            print(self.modele.temp_fin - self.modele.temps_debut)
            self.root.quit()
        for pio in self.modele.pions:
            if self.modele.carre.collision_pions(pio.x1, pio.x2, pio.y1, pio.y2) and self.modele.carre.collision:
                self.modele.temp_fin = time.time()
                print(self.modele.temp_fin - self.modele.temps_debut)
                self.root.quit()

class Score():
    def __init__(self):
        self.modele = modele

class Modele():
    def __init__(self, parent):
        self.modele = parent  # Contrôleur
        self.largeur = 800
        self.hauteur = 800
        self.carre = Carre()
        self.pions = [Pion(40, 40, 100, 100, "blue", "pion1"), Pion(340, 35, 400, 85, "blue", "pion2"),
                      Pion(35, 390, 65, 450, "blue", "pion3"), Pion(360, 380, 400, 400, "blue", "pion4")]
        self.temps_debut = time.time()
        self.temp_fin = None

    def jouer_coup(self):
        for i in self.pions:
            i.jouer_coup()

class Controleur():
    def __init__(self):
        self.modele = Modele(self)
        self.vue = Vue(self, self.modele)
        self.vue.afficher_demarrage()
        self.boucle_de_jeu()
        self.vue.root.mainloop()

    def boucle_de_jeu (self):
        self.modele.jouer_coup()
        self.vue.afficher_bloc()
        self.vue.score()
        self.vue.root.after(20, self.boucle_de_jeu)

if __name__ == '__main__':
    c = Controleur()