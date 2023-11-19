package personnages;

import items.*;     // Pour Capacite

public class EnnemiSorciere extends PersonnageEnnemi{
    public EnnemiSorciere(String nom) {
        super(nom, 350);
        Capacite capacite = new Capacite("Mauvais Sort", 1, 100);
        setCapacite(capacite);

    }

    

}
