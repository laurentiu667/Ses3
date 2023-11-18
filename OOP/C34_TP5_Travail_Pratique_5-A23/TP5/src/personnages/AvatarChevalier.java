package personnages;

import items.*;     // Pour Arme et Armure

public class AvatarChevalier extends PeronnageAvatar{

    public AvatarChevalier(String nom) {
        super(nom, 500);
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
