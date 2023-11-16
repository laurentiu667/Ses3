package personnages;

import items.*;     // Pour Capacite

public class EnnemiSorciere extends PersonnageEnnemi{
    public EnnemiSorciere(String nom, int sante) {
        super(nom, sante);
    }

    @Override
    public int attaquer(Personnage Personnage) {
        return 0;
    }

    // Constructeur


    // Méthode attaquer redéfinie pour attaques magiques


}
