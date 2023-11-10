import tkinter as tk

class Bille:
    def __init__(self, modele, vue):
        self.modele = modele
        self.vue = vue
        self.vitesse = 1 # pixel par pixel
        self.contact_chateau = False

class Modele:
    def __init__(self):
        self.cell_size = 40

        self.chemin = [
            [(5, 0, 7, 16), "white"],
            [(7, 14, 11, 16), "white"],
            [(11, 3, 13, 16), "white"],
            [(13, 3, 30, 5), "white"],
            [(28, 5, 30, 10), "white"],
            [(19, 8, 28, 10), "white"],
            [(19, 10, 21, 16), "white"],
            [(21, 14, 29, 16), "white"]
        ]

        self.chateau = [
            [(29, 13, 31, 16), "grey"],
            [(28, 12, 29, 13), "grey"],
            [(31, 12, 32, 13), "grey"]
        ]

class Vue:

    def __init__(self, root, modele):
        self.root = root
        self.root.title("Tower Defense")
        self.root.geometry("1920x1080")

        self.container = tk.Frame(root)
        self.container.pack()

        self.canvas = tk.Canvas(self.container, width=1320, height=960, bg="black")
        self.canvas.pack()

        self.modele = modele
        self.dessiner_jeu()

    def dessiner_jeu(self):
        for p in self.modele.chemin:
            coords, color = p
            x1, y1, x2, y2 = coords
            x1 *= self.modele.cell_size
            y1 *= self.modele.cell_size
            x2 *= self.modele.cell_size
            y2 *= self.modele.cell_size
            self.canvas.create_rectangle(x1, y1, x2, y2, fill=color, outline="")

        for c in self.modele.chateau:
            coords, color = c
            x1, y1, x2, y2 = coords
            x1 *= self.modele.cell_size
            y1 *= self.modele.cell_size
            x2 *= self.modele.cell_size
            y2 *= self.modele.cell_size
            self.canvas.create_rectangle(x1, y1, x2, y2, fill=color, outline="")

class Controleur:
    def __init__(self):
        self.modele = Modele()
        self.root = tk.Tk()
        self.vue = Vue(self.root, self.modele)
    def demarrer(self):
        self.root.mainloop()

def main():
    c = Controleur()
    c.demarrer()

if __name__ == "__main__":
    main()