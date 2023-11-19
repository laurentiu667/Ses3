package personnages;

import items.*;     // Pour Capacite

public class EnnemiSorciere extends PersonnageEnnemi{
    public EnnemiSorciere(String nom) {
        super(nom, 350);
        Capacite capacite = new Capacite("Mauvais Sort", 1, 100);
        setCapacite(capacite);

    }


    // C’est dans cette méthode qu’on programmera la mécanique d’une attaque.
    @Override
    public int attaquer(Personnage personnage) {
        return getArme().getDommages() - personnage.getArmure().getDefense();
    }

    @Override
    public void recevoirDommages(int dommages){

    }

}
