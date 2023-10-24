import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Controle {

    private static final String REGEX_NOM = "^[R][1-3][a-zA-Z]{5}[a-zA-Z]{2}$";
    private static final String REGEX_COURRIEL = "@";
    public static boolean verifNom(Enregistrement engregistrement){
        return engregistrement.getNomUsager().matches(REGEX_NOM);
    }

    public static boolean verifMdp(Enregistrement engregistrement){
         Pattern p = Pattern.compile("[A-Z]");
         Matcher m = p.matcher(engregistrement.getMdp());
         Pattern p2 = Pattern.compile("\\d");
         Matcher m2 = p2.matcher(engregistrement.getMdp());
         if (engregistrement.getMdp().length() >= 8) {
             if (m.find())
                 if (m2.find())
                     return true;
         }
         return false;
    }
    public static boolean verifCourriel(Enregistrement engregistrement){
        return engregistrement.getMdp().matches(REGEX_COURRIEL);
    }
}
