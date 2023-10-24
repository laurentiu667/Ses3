package ca.codexcvm.succursale;

import ca.codexcvm.compagnie.TarificationCompagnie;

public class Succursale {

    private int noSuccursale;
    private String nomSuccursale;

    private double margeProfit = 0.25;

    public int getNoSuccursale() {
        return noSuccursale;
    }
    public String getNomSuccursale() {
        return nomSuccursale;
    }
    public double getMargeProfit() {
        return margeProfit;
    }

    public void setNoSuccursale(int noSuccursale) {
        this.noSuccursale = noSuccursale;
    }

    public void setNomSuccursale(String nomSuccursale) {
        this.nomSuccursale = nomSuccursale;
    }
    public void setMargeProfit(double margeProfit) {
        this.margeProfit = margeProfit;
    }

}
