package personnages;

import items.*;     // Pour Arme et Armure

public class EnnemiGolem extends PersonnageEnnemi{
    public EnnemiGolem(String nom, int sante) {
        super(nom, 800);
        Arme arme = new Arme("Poings", 1 , 50);
        Armure armure = new Armure("Carapace", 1, 40);

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
