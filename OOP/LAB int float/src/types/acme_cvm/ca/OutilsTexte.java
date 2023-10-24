package types.acme_cvm.ca;

public class OutilsTexte {

    public boolean isPalindrome(){
        String word = "laval", inverser = "";
        for (int charPali = word.length(); charPali > 0; charPali--){
            inverser += word.charAt(charPali - 1);
        }
        if (word.equals(inverser)){
            return true;
        }
        return false;
    }

    public int stringToInt (String string){
        Integer var = Integer.valueOf(string);

        return var;
    }
}
