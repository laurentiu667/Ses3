package gestion_banque.acme_cvm.ca;

import banque.acme_cvm.ca.Banque;
import banque.acme_cvm.ca.CompteBancaire;
import client.acme_cvm.ca.Client;

public class GestionBanque {
    public static void main(String[] args) {

        int     retrait1    = 600;
        int     retrait2    = 300;
        double  retrait3    = 150.25;
        int     depot1      = -200;
        int     depot2      = 300;

        Banque banque = new Banque();

        int nombre_de_client = 2;

        Client[] client = new Client[nombre_de_client];

        client[0] = new Client();
        client[1] = new Client();

        client[0].setNoClient(23432);
        client[0].setNomClient("Batman");

        client[1].setNoClient(94821);
        client[1].setNomClient("Arnold Schwarzenegger");

        int nombre_de_compte = 3;

        CompteBancaire[] compteBancaire = new CompteBancaire[nombre_de_compte];
        compteBancaire[0] = new CompteBancaire();
        compteBancaire[1] = new CompteBancaire();
        compteBancaire[2] = new CompteBancaire();

        compteBancaire[0].setCompte(34893, "Épargne", client[0].getNoClient(), 1000.00 , compteBancaire[0].getLimiteRetrait());
        compteBancaire[1].setCompte(84649, "Chéque" , client[0].getNoClient(), 200.00  , compteBancaire[1].getLimiteRetrait());
        compteBancaire[2].setCompte(29437, "Épargne", client[1].getNoClient(), 10000.00, compteBancaire[2].getLimiteRetrait());


        for (int i = 0; i < nombre_de_compte; i++){
            System.out.println(
                              "Le compte numéro "    + compteBancaire[i].getNoCompte()
                            + " du client "          + compteBancaire[i].getNoClient()
                            + " est un compte "      + compteBancaire[i].getTypeCompte()
                            + " et a un solde de $ " + compteBancaire[i].getSolde()
            );
        }

        System.out.println("\n");

        if (compteBancaire[0].retrait(retrait1) == -1){
            System.out.println("Transaction invalide, non complétée");
        }
        else if (compteBancaire[0].retrait(retrait1) == 0) {
            System.out.println("Transaction valide le nouveau solde est $ " + compteBancaire[0].getSolde());
        }

        if (compteBancaire[1].retrait(retrait2) == -1){
            System.out.println("Transaction invalide, non complétée");
        }
        else if (compteBancaire[1].retrait(retrait2) == 0) {
            System.out.println("Transaction valide le nouveau solde est $ " + compteBancaire[1].getSolde());
        }

        if ((compteBancaire[2].retrait(retrait3) == -1)){
            System.out.println("Transaction invalide, non complétée");
        }
        else if (compteBancaire[2].retrait(retrait3) == 0) {
            System.out.println("Transaction valide le nouveau solde est $ " + compteBancaire[2].getSolde());
        }

        if ((compteBancaire[0].depot(depot1)) == -1){
            System.out.println("Transaction invalide, non complétée");
        }
        else if (compteBancaire[0].depot(depot1) == 0) {
            System.out.println("Transaction valide le nouveau solde est $ " + compteBancaire[0].getSolde());
        }

        if (compteBancaire[1].depot(depot2) == -1){
            System.out.println("Transaction invalide, non complétée");
        }
        else if (compteBancaire[1].depot(depot2) == 0) {
            System.out.println("Transaction valide le nouveau solde est $ " + compteBancaire[1].getSolde());
        }

        System.out.println("\n");

        for (int i = 0; i < nombre_de_compte; i++){
            System.out.println(
                              "Le compte numéro "    + compteBancaire[i].getNoCompte()
                            + " du client "          + compteBancaire[i].getNoClient()
                            + " est un compte "     + compteBancaire[i].getTypeCompte()
                            + " et a un solde de $ " + compteBancaire[i].getSolde()
            );
        }

        System.out.println("\n");

        if (compteBancaire[0].versetInteret() == -1){
            System.out.println("Intérêt non versé sur compte chèque ");
        }
        else if (compteBancaire[0].versetInteret() == 0) {
            System.out.println("Intérêt versé, le nouveau solde est $ " + compteBancaire[0].getSolde());
        }

        if (compteBancaire[1].versetInteret() == -1){
            System.out.println("Intérêt non versé sur compte chèque");
        }
        else if (compteBancaire[1].versetInteret() == 0) {
            System.out.println("Intérêt versé, le nouveau solde est $ " + compteBancaire[1].getSolde());
        }

        if ((compteBancaire[2].versetInteret() == -1)){
            System.out.println("Intérêt non versé sur compte chèque ");
        }
        else if (compteBancaire[2].versetInteret() == 0) {
            System.out.println("Intérêt versé, le nouveau solde est $ " + compteBancaire[2].getSolde());
        }

        System.out.println("\n");
        for (int i = 0; i < nombre_de_compte; i++){
            System.out.println(
                              "Le compte numéro "    + compteBancaire[i].getNoCompte()
                            + " du client "          + compteBancaire[i].getNoClient()
                            + " est un compte "      + compteBancaire[i].getTypeCompte()
                            + " et a un solde de $ " + compteBancaire[i].getSolde()
            );
        }
    }
}

