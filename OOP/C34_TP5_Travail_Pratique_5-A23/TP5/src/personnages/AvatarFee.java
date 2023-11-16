package personnages;

import items.*;     // Pour Capacite

public class AvatarFee extends PeronnageAvatar {
    public AvatarFee(String nom, int sante) {
        super(nom, sante);
    }

    @Override
    public int attaquer(Personnage Personnage) {
        return 0;
    }

    // Constructeur


    // Méthode attaquer redéfinie pour attaques magiques


}
