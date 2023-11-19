package personnages;

import items.*;     // Pour Capacite

public class AvatarFee extends PeronnageAvatar {
    public AvatarFee(String nom, int sante) {
        super(nom, 200);
        Capacite echantement = new Capacite("Enchantement", 1, 40);
    }

    @Override
    public int attaquer(Personnage Personnage) {
        return 0;
    }

    @Override
    public void recevoirDommages(int dommages){

    }


}
