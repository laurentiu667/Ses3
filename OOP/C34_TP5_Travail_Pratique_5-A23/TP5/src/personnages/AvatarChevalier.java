package personnages;

import items.*;     // Pour Arme et Armure

public class AvatarChevalier extends PeronnageAvatar{

    public AvatarChevalier(String nom) {
        super(nom, 500);
    }

   

    @Override
    public int attaquer(Personnage Personnage) {
        return 0;
    }

}
