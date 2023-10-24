import tkinter as tk
from tkinter import simpledialog

# Fonction pour ouvrir la deuxième fenêtre pour entrer le nom d'utilisateur
def ouvrir_deuxieme_fenetre():
    user_name = simpledialog.askstring("Entrer le nom d'utilisateur", "Entrez votre nom d'utilisateur :")
    if user_name:
        username_input.delete(0, tk.END)  # Efface le contenu actuel du champ d'entrée
        username_input.insert(0, user_name)

# Création de la première fenêtre
fenetre_principale = tk.Tk()
fenetre_principale.title("Première fenêtre")

# Créez un Label et un champ d'entrée pour le nom d'utilisateur
username_label = tk.Label(fenetre_principale, text="Username:")
username_label.pack()
username_input = tk.Entry(fenetre_principale)
username_input.pack()

# Créez un bouton pour ouvrir la deuxième fenêtre
ouvrir_fenetre_button = tk.Button(fenetre_principale, text="Entrer le nom d'utilisateur", command=ouvrir_deuxieme_fenetre)
ouvrir_fenetre_button.pack()

# Fonction pour afficher la première fenêtre
def afficher_premiere_fenetre():
    fenetre_principale.deiconify()

# Création de la deuxième fenêtre
fenetre_secondaire = tk.Toplevel()
fenetre_secondaire.title("Deuxième fenêtre")
fenetre_secondaire.withdraw()  # Masquer la fenêtre au départ

# Fonction pour fermer la deuxième fenêtre
def fermer_deuxieme_fenetre():
    fenetre_secondaire.withdraw()
    afficher_premiere_fenetre()

# Créez un Label pour afficher le nom d'utilisateur de la première fenêtre
username_display_label = tk.Label(fenetre_secondaire, text="Nom d'utilisateur:")
username_display_label.pack()

# Créez un bouton pour fermer la deuxième fenêtre
fermer_fenetre_button = tk.Button(fenetre_secondaire, text="Fermer", command=fermer_deuxieme_fenetre)
fermer_fenetre_button.pack()

fenetre_principale.mainloop()
