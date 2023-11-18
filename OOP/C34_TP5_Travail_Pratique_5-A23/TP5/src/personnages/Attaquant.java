package personnages;

// Interface pour tous les types de personnages qui peuvent attaquer ou être attaqués
public interface Attaquant {


    public int attaquer(Personnage personnage);
    public void recevoirDommages(int dommages);

}
