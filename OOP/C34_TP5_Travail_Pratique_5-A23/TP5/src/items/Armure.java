package items;

public class Armure extends Item implements ItemAmeliorable {
    // Champs
    private int niveau;
    private int defense;

    public Armure(String nom, int niveau, int defense) {
        super(nom);
        this.niveau = niveau;
        this.defense = defense;
    }

    // Constructeur


    // Méthodes d'accès (getters)
    public int getNiveau() { return niveau; }
    public int getDefense() { return defense; }


    // Méthode améliorer
    // Une armure améliore sa défense de 15 par niveau

    @Override
    public void ameliorer() {
        this.niveau++;
        this.defense += 15;
    }
}
