package items;

public class Arme extends Item implements ItemAmeliorable {
    // Champs
    private int niveau;
    private int dommages;

    public Arme(String nom, int niveau, int dommages){
        super(nom);
        this.niveau = niveau;
        this.dommages = dommages;
    }

    // Constructeur



    // Méhodes d'accès (getters)
    public int getNiveau() { return niveau; }
    public int getDommages() { return dommages; }


    // Méthode améliorer
    // Une arme améliore ses dommages de 10 par niveau


    @Override
    public void ameliorer() {
        this.niveau++;
        this.dommages += 5;
    }
}
