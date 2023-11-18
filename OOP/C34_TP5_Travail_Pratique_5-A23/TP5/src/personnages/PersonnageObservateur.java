package personnages;

public class PersonnageObservateur extends Personnage {
    public PersonnageObservateur(String nom, int sante) {
        super(nom, sante);
    }


    public void saluer(){
        System.out.println("Bonjour!");
    }


}
