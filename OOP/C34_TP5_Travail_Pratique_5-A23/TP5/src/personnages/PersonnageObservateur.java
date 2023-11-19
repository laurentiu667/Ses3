package personnages;

public class PersonnageObservateur extends Personnage {
    public PersonnageObservateur(String nom, int sante) {
        super(nom, sante);
    }

    @Override
    public int attaquer(Personnage Personnage) {
        return 0;
    }


    public void saluer(){
        System.out.println("Bonjour!");
    }


}
