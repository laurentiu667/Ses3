package personnages;

import items.*;     // Pour Arme et Armure

public class AvatarChevalier extends PeronnageAvatar{

    public AvatarChevalier(String nom) {
        super(nom, 500);

        Arme epee = new Arme("Épée ", 1, 100);
        Armure armure = new Armure("Plastron", 1, 15);
        setArme(epee);
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
