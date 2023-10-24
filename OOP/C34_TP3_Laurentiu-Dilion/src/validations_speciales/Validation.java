package validations_speciales;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Validation {
   
    private static final String CODE_CLIENT_REGEX = "^[a-zA-Z]{3}\\d{8}[#*]{0,1}$";
    private static final String NUMERO_DE_SERIE_REGEX = "^[a-zA-Z]{3,8}\\d{6}-\\S$";
    private static final String TELEPHONE_REGEX = "^(\\[\\d{3}]|\\(\\d{3}\\)|\\d{3})[- ]?\\d{3}[- ]?\\d{4}$";

    public static boolean validerCodeClient(String chaine) {
        Pattern p = Pattern.compile(CODE_CLIENT_REGEX);
        Matcher m = p.matcher(chaine);
        return m.matches();
    }

    public static boolean validerNumeroDeSerie(String chaine) {
        Pattern p = Pattern.compile(NUMERO_DE_SERIE_REGEX);
        Matcher m = p.matcher(chaine);
        return m.matches();
    }

    public static boolean validerTelephone(String chaine) {
        Pattern p = Pattern.compile(TELEPHONE_REGEX);
        Matcher m = p.matcher(chaine);
        return m.matches();
    }
}