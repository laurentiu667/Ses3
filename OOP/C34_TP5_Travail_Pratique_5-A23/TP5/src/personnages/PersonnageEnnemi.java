package personnages;

public class PersonnageEnnemi extends Personnage implements Attaquant {
    public PersonnageEnnemi(String nom, int sante) {
        super(nom, sante);
    }


    @Override
    public int attaquer(Personnage personnage) {
        return getArme().getDommages() - personnage.getArmure().getDefense();
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



}
