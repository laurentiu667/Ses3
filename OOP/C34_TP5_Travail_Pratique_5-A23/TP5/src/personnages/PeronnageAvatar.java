package personnages;

public class PeronnageAvatar extends Personnage implements Attaquant {

    public PeronnageAvatar(String nom, int sante) {
        super(nom, sante);
    }


    @Override
    public int attaquer(Personnage Personnage) {
        return Personnage.getArme().getDommages() - Personnage.getArmure().getDefense();
    }

    @Override
    public void recevoirDommages(int dommages) {
        int sante = getSante() - dommages;
        if (sante < 0) {
            setSante(0);
        } else {
            setSante(sante);
        }
    }

    // Constructeur
    // L'Arme, Armure et Capacite sont laisées par défaut ici et définies ailleurs dans la classe de famille d'avatar



    //  Méthode recevoirDommages: Déduis les dommages de la santé, santé 0 minimum, si 0 = vaincu.



    // Méthode attaquer()
    // Calcul par défaut pour dommages en fonction de l'arme utilisée et de l'armure de l'ennemi
    // Surchagée dans la famille d'avatar seulement si un calcul différente est requis


}
