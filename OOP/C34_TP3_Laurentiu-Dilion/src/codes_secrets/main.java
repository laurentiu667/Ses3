package codes_secrets;


public class main {

    public static void main(String[] args) {
        ChiffrementChaine chiffrement = new ChiffrementChaine();

        chiffrement.setCleChiffrement(5);
        chiffrement.setChaineAChiffrer("Bonjour, monde!");

        String chaineChiffree = chiffrement.chiffrer("Lapin", 3);
        System.out.println("Chaine chiffrée: " + chaineChiffree);

        String chaineChiffree2 = chiffrement.chiffrer("Lapin");
        System.out.println("Chaine chiffrée2: " + chaineChiffree2);

        // Appelez la méthode de déchiffrement
        String chaineDechiffree = chiffrement.dechiffrer("Odslq", 3);
        System.out.println("Chaine déchiffrée: " + chaineDechiffree);

        String chaineDechiffree2 = chiffrement.dechiffrer( 10, "Vkzsx");
        System.out.println("Chaine déchiffrée2: " + chaineDechiffree2);
    }


}
