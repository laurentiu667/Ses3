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


    // Méhodes d'accès (getters)
    public int getNiveau() { return niveau; }
    public int getDommages() { return dommages; }


    @Override
    public void ameliorer() {
        this.niveau++;
        this.dommages += 5;
    }
}
