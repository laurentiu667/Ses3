package ca.codexcvm.succursale;

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

    protected double getMargeProfit() {
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


