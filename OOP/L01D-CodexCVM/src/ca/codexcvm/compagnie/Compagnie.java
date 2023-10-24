package ca.codexcvm.compagnie;

public class Compagnie {
    private String nomCompagnie = "Codex CVM";
    private double margeProfit = 0.1;

    public String getNomCompagnie() {
        return nomCompagnie;  }
    //  protected parce que on veut que ca reste priver mais qu on puissent calculer dans l autre package
    protected double getMargeProfit() {
        return margeProfit;  }

}
