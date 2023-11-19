package personnages;

import items.*;     // Pour Arme et Armure

public class EnnemiGolem extends PersonnageEnnemi{
    public EnnemiGolem(String nom) {
        super(nom, 800);
        Arme arme = new Arme("Poings", 1 , 50);
        Armure armure = new Armure("Carapace", 1, 40);
        setArme(arme);
        setArmure(armure);
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
