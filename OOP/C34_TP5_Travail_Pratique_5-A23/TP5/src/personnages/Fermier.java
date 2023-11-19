package personnages;

public class Fermier extends PersonnageObservateur{
    public Fermier(String nom, int sante) {
        super(nom, 0);
    }

    @Override
    public void saluer() {
        super.saluer();
    }
}

