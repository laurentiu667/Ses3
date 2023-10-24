package utils_rh.acme_cvm.ca;

public class EchelleSalariale {

    private double Niv1Min = 20000.00;
    private double Niv1Max = 49999.99;
    private double Niv2Min = 50000.00;
    private double Niv2Max = 74999.99;

    public double salaireMaxParNiveau(int niveau) {
        switch (niveau) {
            case 1:
                return Niv1Max;
            case 2:
                return Niv2Max;
            default:
                return 0;
        }
    }
    public int trouveNiveau(double salaire) {
        if (salaire >= Niv1Min && salaire <= Niv1Max) {
            return 1;
        } else if (salaire >= Niv2Min && salaire <= Niv2Max) {
            return 2;
        } else {
            return 0;
        }
    }

    public double salaireMaxParSalaire(double salaire) {

        switch (trouveNiveau(salaire)){
            case 1:
                return Niv1Max;
            case 2:
                return Niv2Max;
            default:
                return 0;
        }
    }



}


