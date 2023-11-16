package personnages;

import items.*;     // Pour Arme et Armure

public class EnnemiGolem extends PersonnageEnnemi{
    public EnnemiGolem(String nom, int sante) {
        super(nom, sante);
    }

    @Override
    public int attaquer(Personnage Personnage) {
        return 0;
    }

    // Constructeur


}
