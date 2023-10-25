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

    def collision_pions(self, pion_x1, pion_x2, pion_y1, pion_y2):
        x1 = self.x - self.largeur
        y1 = self.y - self.hauteur
        x2 = self.x + self.largeur
        y2 = self.y + self.hauteur

        return pion_x1 <= x2 and x1 <= pion_x2 and pion_y1 <= y2 and y1 <= pion_y2


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
        x = (self.x2 - self.x1) / 2 + self.x1
        y = (self.y2 - self.y1) / 2 + self.y1
        x1, y1 = hp.getAngledPoint(self.angle, self.vitesse, x, y)
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
        if self.modele.carre.collision(self.canvas.winfo_reqwidth(), self.canvas.winfo_reqheight()):
            self.modele.temp_fin = time.time()
            print(self.modele.temp_fin - self.modele.temps_debut)
            # self.root.quit()
        for pio in self.modele.pions:
            if self.modele.carre.collision_pions(pio.x1, pio.x2, pio.y1, pio.y2):
                self.modele.temp_fin = time.time()
                print(self.modele.temp_fin - self.modele.temps_debut)
                # self.root.quit()
        self.afficher_carre_rouge()
        self.afficher_pions()

    def creer_page_jeu(self):
        self.cadre_jeu = Frame(self.root, borderwidth=40, bg="black")
        self.cadre_jeu.pack()

        self.canvas = Canvas(self.cadre_jeu, width=450, height=450, bg="white")
        self.canvas.pack()

    def creer_interface_utilisateur(self):
        cadre_interface = Frame(self.root, bg="white")
        cadre_interface.pack(side=RIGHT)

        label_username = Label(cadre_interface, text="Username:")
        label_username.pack()

        self.username_entry = Entry(cadre_interface)
        self.username_entry.pack()

        bouton_valider = Button(cadre_interface, text="Valider", command=self.afficher_nom_joueur)
        bouton_valider.pack()

    def afficher_carre_rouge(self):
        x = (self.canvas.winfo_reqwidth() - self.modele.carre.largeur) / 2
        y = (self.canvas.winfo_reqheight() - self.modele.carre.hauteur) / 2

        self.carre = self.canvas.create_rectangle(self.modele.carre.x - self.modele.carre.largeur,
                                                  self.modele.carre.y - self.modele.carre.hauteur,
                                                  self.modele.carre.x + self.modele.carre.largeur,
                                                  self.modele.carre.y + self.modele.carre.hauteur,
                                                  fill=self.modele.carre.couleur,
                                                  tags="carre_rouge")

    def distance_souris_carre(self, event, x, y):

        dx = x - event.x
        dy = y - event.y
        return sqrt(dx ** 2 + dy ** 2)

    def deplacer_carre(self, event=None):
        x_centre_carre, y_centre_carre = self.canvas.coords("carre_rouge")[0] + self.modele.carre.largeur, \
                                         self.canvas.coords("carre_rouge")[1] + self.modele.carre.hauteur

        if event and self.distance_souris_carre(event, x_centre_carre, y_centre_carre) <= 25:
            self.canvas.delete("carre_rouge")
            self.modele.carre.x = event.x
            self.modele.carre.y = event.y
            self.afficher_carre_rouge()

    def afficher_pions(self):
        self.pions = []
        for pion in self.modele.pions:
            self.canvas.create_rectangle(pion.x1, pion.y1, pion.x2, pion.y2, fill=pion.couleur, tags=pion.tag)

    def creer_menu(self):
        self.menu = []

        canvas_width = 450
        canvas_height = 450

        x_center = canvas_width / 2
        y_center = canvas_height / 2

        background_width = 200
        background_height = 50

        y_offset = 50

        bold_font = ("Helvetica", 12, "bold")

        text_elements = ["Commencer la partie", "Score", "Difficulté"]

        for text in text_elements:
            x_background = x_center - background_width / 2
            y_background = y_center - background_height / 2
            background = self.canvas.create_rectangle(x_background, y_background, x_background + background_width,
                                                      y_background + background_height, fill="red")

            x_text = x_center
            y_text = y_center
            text_object = self.canvas.create_text(x_text, y_text, text=text, fill="white", font=bold_font)

            self.menu.append(background)
            self.menu.append(text_object)

            y_center += y_offset

    def menu_fin_jeux(self):
        self.canvas.create_rectangle(60, 70, 390, 300, fill="#A0A0A0")
        self.canvas.create_text(130, 190, fill="black", text="Score:", font=("Helvetica", 24))
        elapsed_time = self.modele.temp_fin - self.modele.temps_debut
        self.canvas.create_text(290, 190, fill="black", text=f"{elapsed_time:.2f} seconds", font=("Helvetica", 24))

        # Créer le bouton Réinitialiser
        reinitialiser_button = Button(self.canvas, text="Réinitialiser", command=self.reinitialiser_jeu, width=30, height=2, bg="black", fg="white")
        reinitialiser_button_window = self.canvas.create_window(220, 330, anchor='center', window=reinitialiser_button)

    def reinitialiser_jeu(self):
        pass

class Modele():
    def __init__(self, parent):
        self.modele = parent
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
        self.vue.creer_menu()
        self.vue.afficher_demarrage()
        self.choix_menu()
        self.vue.root.mainloop()

    def choix_menu(self):
        self.vue.canvas.tag_bind(self.vue.menu[0], '<Button-1>', self.lancer_jeu)
        self.vue.canvas.tag_bind(self.vue.menu[1], '<Button-1>', self.lancer_jeu)

    def lancer_jeu(self, event):
        for element in self.vue.menu:
            self.vue.canvas.delete(element)
        self.vue.afficher_bloc()
        self.vue.canvas.tag_bind(self.vue.carre, '<Button-1>', lambda event: self.boucle_de_jeu())

    def boucle_de_jeu(self):
        self.modele.jouer_coup()
        self.vue.afficher_bloc()
        if self.modele.temp_fin is None:
            self.vue.root.after(10, self.boucle_de_jeu)
        else:
            self.vue.canvas.unbind("<B1-Motion>")
            self.vue.menu_fin_jeux()

if __name__ == '__main__':
    c = Controleur()