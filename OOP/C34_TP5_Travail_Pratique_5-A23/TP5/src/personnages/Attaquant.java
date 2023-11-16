package personnages;

// Interface pour tous les types de personnages qui peuvent attaquer ou être attaqués
public interface Attaquant {

    // Méthodes attaquer() et recevoirDommanges seront obligatoires pour les classes d'attaquants

    public int attaquer(Personnage personnage);
    public void recevoirDommages(int dommages);

}
