package items;

// Une trousse de santé fournit des points de vie (PV) qui sont restaurés à l'avatar
// Une trousse peu être utilisée un nombre prédéterminé de fois, après quoi, elle est vide
public class TrousseSante {
    // Champs
    private int nombrePV;                   // Nombre de Points de Vie restaurés par utilisation
    private int nbreUtilisationsRestantes;  // Nombre de fois que la trousse peut encore être utilisée

    // Constructeur


    // Méthodes d'accès (getters)
    public int getNombrePV() { return nombrePV; }
    public int getNbreUtilisationsRestantes() { return nbreUtilisationsRestantes; }


    // Méthode utiliser()
    // retourne les PV fournis par la trousse et réduit son nombre d'utilisation de 1


}
