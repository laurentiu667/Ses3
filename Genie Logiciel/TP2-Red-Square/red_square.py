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

    def creer_menu(self):
        self.menu = []

        # Dimensions du canevas
        canvas_width = 450
        canvas_height = 450

        # Coordonnées du centre du canevas
        x_center = canvas_width / 2
        y_center = canvas_height / 2

        # Dimensions des arrière-plans
        background_width = 200
        background_height = 50

        # Espacement vertical entre les éléments du menu
        y_offset = 50

        # Police en gras (bold)
        bold_font = ("Helvetica", 12, "bold")

        # Liste des textes
        text_elements = ["Commencer la partie", "Score", "Difficulté"]

        for text in text_elements:

            x_background = x_center - background_width / 2
            y_background = y_center - background_height / 2
            background = self.canevas.create_rectangle(x_background, y_background, x_background + background_width, y_background + background_height, fill="red")


            x_text = x_center
            y_text = y_center
            text_object = self.canevas.create_text(x_text, y_text, text=text, fill="white", font=bold_font)

            self.menu.append(background)
            self.menu.append(text_object)

            # Ajustement pour le prochain élément du menu
            y_center += y_offset

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
        self.vue.creer_menu()  # Appel de la méthode pour créer le menu
        self.vue.root.mainloop()


    #def boucle_jeux(self):
        #self.modele.jouer_coup()
        #self.vue.afficher_bloc()
        #self.vue.root.after(50, self.boucle_jeux())


if __name__ == '__main__':
    c = Controleur()