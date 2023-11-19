package personnages;

import items.*;     // Pour Capacite

public class AvatarFee extends PeronnageAvatar {
    public AvatarFee(String nom) {
        super(nom, 200);
        Capacite echantement = new Capacite("Enchantement", 1, 40);
        setCapacite(echantement);
    }

    @Override
    public int attaquer(Personnage personnage) {
        return getArme().getDommages() - personnage.getArmure().getDefense();
    }
    @Override
    public void recevoirDommages(int dommages){

    }


}
