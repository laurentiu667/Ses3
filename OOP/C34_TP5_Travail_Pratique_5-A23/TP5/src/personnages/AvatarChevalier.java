package personnages;

import items.*;     // Pour Arme et Armure

public class AvatarChevalier extends PeronnageAvatar{

    public AvatarChevalier(String nom) {
        super(nom, 500);

        Arme epee = new Arme("Épée ", 1, 100);
        Armure armure = new Armure("Plastron", 1, 15);
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
