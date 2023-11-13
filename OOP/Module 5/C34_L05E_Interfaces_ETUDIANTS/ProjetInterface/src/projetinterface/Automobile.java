package projetinterface;
import java.time.*;
import java.util.*;
public class Automobile extends Vehicule implements Assurable
{
    public Automobile  ( double valeur, int anneeModele, Proprietaire pr, String numeroPlaque )
    {
        super ( valeur, anneeModele, pr, numeroPlaque);
    }


    @Override
    public boolean estAssurable ()
    {
        // personne plus que 21 ans
        LocalDate present = LocalDate.now();
        Period intervalle = Period.between(getPr().getDate(), present);
        int age = intervalle.getYears();
        if ( age < 21 )
            return false;
        else if (getNumeroPlaque().charAt(0) =='T') // n'assure pas les voitures taxis ( plaques commençant par T, TR, TS --> on peut réduire à T)
            return false;
        else
            return true;
    }

    public double coutAssurance()
    {
        if ( estAssurable())
        {
            double cout = POURCENT_TAXE * getValeur() ;

            if ( getPr().getVille().equals ( "Montréal"))
                cout += cout * 0.06;
            return cout;
        }
        else
            return 0;
    }
}
