package projetinterface;
import java.time.LocalDate;
import java.time.Period;
import java.util.*;
public class Motoneige extends Vehicule implements Assurable

{
    private int cylindree ; // 499, 599

    public Motoneige ( double valeur, int anneeModele, Proprietaire pr, String numeroPlaque, int cylindree )
    {
        super ( valeur, anneeModele, pr, numeroPlaque);
        this.cylindree = cylindree;
    }

    public int getCylindree ()
    {
        return cylindree;
    }


    public boolean estAssurable()
    {
        // pas les cylindrees de plus de 600 cc

        if ( cylindree > 600 )
            return false;
        else
            return true;
    }

    public double coutAssurance()
    {
        if ( estAssurable() )
        {
            LocalDate present = LocalDate.now();
            Period age = Period.between(getPr().getDate(), present);
            GregorianCalendar now = new GregorianCalendar ();
            return 500 - ( age.getYears() - getAnneeModele())*25;
        }
        else
            return -1;

    }

    public void setCylindree(int cylindree) {
        this.cylindree = cylindree;
    }
}
