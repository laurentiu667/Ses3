package personnages;

public class Fermier extends PersonnageObservateur{
    public Fermier(String nom, int sante) {
        super(nom, sante);
    }

    @Override
    public void saluer() {
        super.saluer();
    }
}

