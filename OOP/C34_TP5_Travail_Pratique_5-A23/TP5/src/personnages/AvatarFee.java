package personnages;

import items.*;     // Pour Capacite

public class AvatarFee extends PeronnageAvatar {
    public AvatarFee(String nom, int sante) {
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
