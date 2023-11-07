package gestion_projet;

import projets.Activite;
import projets.Projets;
import projets.Taches;

import java.time.*;

public class main {

    public static void main(String[] args) {

        Projets monProjet = new Projets("Création d'une page web dynamique", 3000); // 600 minutes allouées
        // Ajout des taches
        Taches tache1 = new Taches("Créer le HTML, CSS et implémenter du JS");
        Taches tache2 = new Taches("Réseaux");
        Taches tache3 = new Taches("Conception de la base de données");
        Taches tache4 = new Taches("Développement du Backend");
        Taches tache5 = new Taches("Développement du Frontend");

        monProjet.ajouterTache(tache1);
        monProjet.ajouterTache(tache2);
        monProjet.ajouterTache(tache3);
        monProjet.ajouterTache(tache4);
        monProjet.ajouterTache(tache5);

        Activite activite1 = new Activite("HTML/CSS", "Conception de la structure de la page web", LocalDateTime.now(), LocalDateTime.now().plusHours(10));
        Activite activite2 = new Activite("JavaScript", "Implémentation des fonctionnalités JS", LocalDateTime.now(), LocalDateTime.now().plusHours(8));

        monProjet.ajouterActivitesProjet(tache1.getNom(), activite1);
        monProjet.ajouterActivitesProjet(tache2.getNom(), activite2);
        // Ajout des activités pour "Réseaux"
        Activite activite3 = new Activite("Définir le plan UML", "Élaboration du plan UML pour le projet", LocalDateTime.now(), LocalDateTime.now().plusMinutes(800));
        monProjet.ajouterActivitesProjet(tache2.getNom(), activite3);

        // Ajout des activités pour "Conception de la base de données"
        Activite activite4 = new Activite("Modélisation des données", "Conception des schémas de données", LocalDateTime.now(), LocalDateTime.now().plusHours(4));
        Activite activite5 = new Activite("Optimisation des requêtes", "Optimisation des requêtes pour les performances", LocalDateTime.now(), LocalDateTime.now().plusHours(5));
        monProjet.ajouterActivitesProjet(tache3.getNom(), activite4);
        monProjet.ajouterActivitesProjet(tache3.getNom(), activite5);

        // Ajout des activités pour "Développement du Backend"
        Activite activite6 = new Activite("API REST", "Mise en place des points d'accès", LocalDateTime.now(), LocalDateTime.now().plusHours(5));
        Activite activite7 = new Activite("Sécurité", "Implémentation des protocoles de sécurité", LocalDateTime.now(), LocalDateTime.now().plusHours(4));
        monProjet.ajouterActivitesProjet(tache4.getNom(), activite6);
        monProjet.ajouterActivitesProjet(tache4.getNom(), activite7);

        // Ajout des activités pour "Développement du Frontend"
        Activite activite8 = new Activite("UX/UI Design", "Création de l'interface utilisateur", LocalDateTime.now(), LocalDateTime.now().plusHours(6));
        Activite activite9 = new Activite("Intégration visuelle", "Intégration des éléments visuels", LocalDateTime.now(), LocalDateTime.now().plusHours(4));
        monProjet.ajouterActivitesProjet(tache5.getNom(), activite8);
        monProjet.ajouterActivitesProjet(tache5.getNom(), activite9);

        monProjet.RapportProjet();
    }

}
