import tkinter as tk
import time

class Joueur:
    def __init__(self, argent_initial):
        self.argent = argent_initial

class Modele:
    def __init__(self, root=None):
        self.cell_size = 40
        self.temps_avant_vague = 5000
        self.timer_id = None
        self.root = root
        self.vies_chateau = 20
        self.joueur = Joueur(argent_initial=100)

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

        self.container_palette_infos = tk.Frame(root)
        self.canvas = tk.Canvas(self.container, width=1320, height=960, bg="black")
        self.canvas.pack()

        self.modele = modele
        self.dessiner_jeu()

        self.timer_running = True
        self.start_time = time.time()
        self.update_timer()

        self.vies_label = tk.Label(self.container, text=f"Vies restantes : {self.modele.vies_chateau}",
                                   font=("Helvetica", 16),
                                   fg="white", bg="black")
        self.vies_label.pack(side=tk.RIGHT)

        self.root.bind("<space>", self.ignore_timer)

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

    def update_timer(self):
        if self.timer_running:
            elapsed_time = int(time.time() - self.start_time)
            remaining_time = max(5 - elapsed_time, 0)

            self.canvas.delete("timer")

            minutes = remaining_time // 60
            seconds = remaining_time % 60

            self.canvas.create_text(100, 700,
                                    text=f"Chrono:\n {minutes:02d}:{seconds:02d}",
                                    font=("Helvetica", 16),
                                    fill="white", tags="timer")

            self.root.after(1000, self.update_timer)

    def ignore_timer(self, event):
        self.timer_running = False
        self.canvas.delete("timer")

    def update_vies_label(self):
        self.vies_label.config(text=f"Vies restantes : {self.modele.vies_chateau}")

class Controleur:
    def __init__(self):
        self.root = tk.Tk()
        self.modele = Modele(self.root)
        self.vue = Vue(self.root, self.modele)

    def demarrer(self):
        self.root.mainloop()

def main():
    c = Controleur()
    c.demarrer()

if __name__ == "__main__":
    main()