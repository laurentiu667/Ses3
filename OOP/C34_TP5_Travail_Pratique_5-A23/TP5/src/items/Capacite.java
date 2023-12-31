package items;
import java.lang.Math;
public class Capacite extends Item implements ItemAmeliorable {
    // Champs
    private int niveau;
    private int dommages;

    // Constructeur
    public Capacite(String nom, int niveau, int dommages){
        super(nom);
        this.niveau = niveau;
        this.dommages = dommages;
    }


    // Méthodes d'accès (getters)
    public int getNiveau() { return niveau; }
    public int getDommages() { return dommages; }

    @Override
    public void ameliorer() {
        this.niveau++;
        this.dommages += 0.5 * Math.pow(niveau, 2);
    }
}
