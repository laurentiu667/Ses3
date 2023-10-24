package application;

import plats_prepares.Plat;

public class AppPlats {
    public static void main(String[] args) {
        Plat plat1 = new Plat("Lasagne", 430, 350, 40, 7.92, 9.99);
        Plat plat2 = new Plat("Pizza Garnie", 270, 400, 20, 5.92, 6.95);
        double objectifProfit = 0.25;

        plat1.AfficherFichePlat();
        System.out.println("Pour atteindre un profit de " + objectifProfit + "%, le prix doit être d'au moins $" + String.format("%.2f", plat1.calculerPrixPourProfit(objectifProfit)));
        System.out.println("\n");
        plat2.AfficherFichePlat();
        System.out.println("Pour atteindre un profit de " + objectifProfit + "%, le prix doit être d'au moins $" + String.format("%.2f", plat2.calculerPrixPourProfit(objectifProfit)));
    }
}