package jeu;

import items.Arme;
import items.Armure;
import items.Capacite;
import items.TrousseSante;
import personnages.*;

public class AppJeu {
    public static void main(String[] args) {

        // Création des objets
        Arme arme1 = new Arme("Kalash", 10, 34);
        arme1.ameliorer();

        Armure armure1 = new Armure("Gants du combatant", 5, 30);
        armure1.ameliorer();

        Capacite inventaire = new Capacite("Coffre", 2, 30);
        inventaire.ameliorer();

        TrousseSante trousse1 = new TrousseSante("trousse", 30, 5);
        trousse1.utiliser();

        System.out.println("Nouvelle arme niveau " + arme1.getNiveau());
        System.out.println("Nouvelle arme dommage " + arme1.getDommages());
        System.out.println("Nouvelle arme nom " + arme1.getNom());

        System.out.println("Nouvelle armure niveau  " + armure1.getNiveau());
        System.out.println("Nouvelle arme defense " + armure1.getDefense());
        System.out.println("Nouvelle arme nom " + armure1.getNom());

        System.out.println("Nouvelle inventaire niveau " + inventaire.getNiveau());
        System.out.println("Nouvelle inventaire dommage " + inventaire.getDommages());
        System.out.println("Nouvelle inventaire nom " + inventaire.getNom());

        System.out.println("Nouvelle trousse1 PV " + trousse1.getNombrePV());
        System.out.println("Nouvelle trousse1 nombre d utilisation " + trousse1.getNbreUtilisationsRestantes());
        System.out.println("Nouvelle trousse1 nom " + trousse1.getNom());
        // Simulation d'un combat



    }
}
