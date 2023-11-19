package jeu;

import items.TrousseSante;
import jeu.Joueur;
import personnages.*;

public class AppJeu {
    public static void main(String[] args) {

        AvatarChevalier avatar1 = new AvatarChevalier("Chevalier1");

        AvatarFee avatar2 = new AvatarFee("Fee1");

        Joueur joueur1 = new Joueur("Joueur1", avatar1);

        EnnemiGolem ennemi1 = new EnnemiGolem("Golem1");

        EnnemiSorciere ennemi2 = new EnnemiSorciere("Sorciere1");

        Fermier figurant1 = new Fermier("Fermier1");

        TrousseSante ts1 = new TrousseSante("TrousseSante1", 400, 3);

        System.out.println("Commencement du combat entre le joueur : " + joueur1.getAlias() + " et l'ennemi : " + ennemi1.getNom());

        while (joueur1.getAvatar().estVivant() && ennemi1.estVivant()){
            // Avatar du joueur attaque ennemi (retourne des dommages)
            int dommageRetour = joueur1.getAvatar().attaquer(ennemi1);
            // Ennemi reçoit les dommages de l’attaque
            ennemi1.recevoirDommages(dommageRetour);
            // Affiche points de vie de avatar et ennemi
            System.out.println("Le nombre de points de vie de " + avatar1.getNom() +  " est de : " + avatar1.getSante() +
                               "\n Le nombre de points de vie de " + ennemi1.getNom() + " est de : " + ennemi1.getSante());
            // Si ennemi est vaincu (n’est plus vivant) - Affiche un message du genre Vous êtes vaincu! fin de la partie.
            if (!ennemi1.estVivant()){
                System.out.println("Vous avez vaincu " + ennemi1.getNom() + " ! fin de la partie");
            } else {
                // Ennemi attaque avatar (retourne des dommages)
                int dommageRetourEnnemi = ennemi1.attaquer(avatar1);
                // Avatar reçoit des dommages
                avatar1.recevoirDommages(dommageRetourEnnemi);
                // Affiche points de vie de avatar et de ennemi
                System.out.println("Le nombre de points de vie de " + ennemi1.getNom()  +  " est de : " + ennemi1.getSante() +
                        "\n Le nombre de points de vie de " + avatar1.getNom() + " est de : " + avatar1.getSante() );
                // Si avatar est vaincu (n’est plus vivant) - Affiche un message du genre Vous êtes vaincu! fin de la partie.
                if (!avatar1.estVivant()){
                    System.out.println("Vous avez vaincu " + avatar1.getNom() + " ! fin de la partie");
                }
            }


        }
    }
}
