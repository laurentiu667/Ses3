package projetheritagemaison;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class MaisonMobile extends Chalet{

    private int anneeFabrication;

    public MaisonMobile ( int nbrePieces, double prixVente, boolean electricite, boolean accesLac, int anneefabrication)

    {
        super ( nbrePieces, 0 , null, "", prixVente, electricite, accesLac);
        this.anneeFabrication = anneeFabrication;
    }

    public int getAnneeFabrication() {
        return anneeFabrication;
    }

    public void setAnneeFabrication(int anneeFabrication) {
        this.anneeFabrication = anneeFabrication;
    }

    public double valeur()
    {
        GregorianCalendar aujourdhui = new GregorianCalendar();

        int age = aujourdhui.get(Calendar.YEAR)-anneeFabrication;
        double val = super.valeur();
        if ( age < 10)
            return val;
        else if ( age < 20 )
            return val*0.6;
        else
            return val*0.5;

    }
}
