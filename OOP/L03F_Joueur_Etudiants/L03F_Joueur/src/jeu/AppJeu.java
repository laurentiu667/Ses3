package jeu;

public class AppJeu {
    public static void main(String[] args) {

        // Créer le joueur 1
        Joueur joueur1 = new Joueur("Skywalker42", 1000, 1000, "Épée", 40, "Plastron Vibranium", 60);

        // Tentative d'amélioration de l'arme
        System.out.println(joueur1.getAlias() + ", vous avez " + joueur1.getCredits() + " crédits.");
        System.out.println("Améliorer l'arme \"" + joueur1.getNomArme() + "\" coûte " + joueur1.coutAmeliorerArme(joueur1.getNiveauArme()) + " crédits");
        if (joueur1.ameliorerArme()){
            System.out.println("Arme améliorée.  Vous avez maintenant " + joueur1.getCredits() + " crédits");
        }
        else {
            System.out.println("Crédits insuffisants, amélioration rejetée.");
        }
        System.out.println("\n"); // saute un ligne...

        // Tentative d'amélioration de l'armure
        System.out.println(joueur1.getAlias() + ", vous avez " + joueur1.getGemmes() + " gemmes.");
        System.out.println("Améliorer l'armure \"" + joueur1.getNomArmure() + "\" coûte " + joueur1.coutAmeliorerArmure(joueur1.getNiveauArmure()) + " gemmes");
        if (joueur1.ameliorerArmure()){
            System.out.println("Armure améliorée.  Vous avez maintenant " + joueur1.getGemmes() + " gemmes");
        }
        else {
            System.out.println("Quantité de gemmes insuffisante, amélioration rejetée.");
        }


    }
}
