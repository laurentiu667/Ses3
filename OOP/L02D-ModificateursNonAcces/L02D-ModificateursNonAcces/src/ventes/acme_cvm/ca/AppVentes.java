package ventes.acme_cvm.ca;

public class AppVentes {
    public static void main(String[] args) {
        Magasin magasin = new Magasin();
        Facture.setNbreClients(0);
        Facture.setNoFactureCourant(1);
        Facture.setVentesCourantes(0);

        Facture facture1 = new Facture();
        facture1.setFacture(9.99);

        Facture facture2 = new Facture();
        facture2.setFacture(19.99);

        Facture facture3 = new Facture();
        facture3.setFacture(29.99);

        System.out.println("Facture: " + facture3.getNoFacture());
        System.out.println("Sous-total: " + facture3.getSousTotal());
        System.out.println("TPS: " + facture3.getTaxeFed());
        System.out.println("TVQ: " + facture3.getTaxeProv());
        System.out.println("Total: " + facture3.getTotal());

        System.out.println("Le nombre de cients est: " + Facture.getNbreClients());
        System.out.println("Les ventes totales courantes sont de: " + Facture.getVentesCourantes());
        System.out.println("Le prochain numéro de facture sera: " + Facture.getNoFactureCourant());

        System.out.println("Pour l'objet facture avec le numéro " + facture1.getNoFacture() + ", la valeur de noFactureCourant est " + facture1.getNoFactureCourant());
        System.out.println("Pour l'objet facture avec le numéro " + facture3.getNoFacture() + ", la valeur de noFactureCourant est " + facture3.getNoFactureCourant());
    }
}
