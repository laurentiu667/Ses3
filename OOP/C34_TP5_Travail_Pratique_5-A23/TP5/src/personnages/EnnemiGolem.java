package personnages;

import items.*;     // Pour Arme et Armure

public class EnnemiGolem extends PersonnageEnnemi{
    public EnnemiGolem(String nom, int sante) {
        super(nom, sante);
    }

    // C’est dans cette méthode qu’on programmera la mécanique d’une attaque.
    @Override
    public int attaquer(Personnage Personnage) {
        return 0;
    }

    @Override
    public void recevoirDommages(int dommages){

    }

}
