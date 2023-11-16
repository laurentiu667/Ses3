package personnages;

public class PersonnageObservateur extends Personnage {
    public PersonnageObservateur(String nom, int sante) {
        super(nom, sante);
    }

    // Le personnage observateur peut interagir avec l'avatar en lui laissant des messages
    // mais ne peut pas attaquer ni être attaqué, c'est un personnage non attaquant

    // Constructeur


    // Méthode saluer afficher Bonjour, à développer plus tard dans le futur
    public void saluer(){
        System.out.println("Bonjour!");
    }


}
