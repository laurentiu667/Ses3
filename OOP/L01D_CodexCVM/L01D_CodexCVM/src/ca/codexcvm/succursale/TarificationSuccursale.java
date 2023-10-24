package ca.codexcvm.succursale;

public class TarificationSuccursale {
    public double calculerPrixVendant(double prixSuccursale){
        Succursale succursale = new Succursale();
        return prixSuccursale * (1 + succursale.getMargeProfit());
    }
}
