package types.acme_cvm.ca;

public class L02C {
    public static void main(String[] args) {
        Operation operation = new Operation();
        OutilsTexte outilsTexte = new OutilsTexte();
        int i1 = 2;
        int i2 = 3;

        Integer wi1 = 12;
        Integer wi2 = 4;

        double d1 = 2.0;
        double d2 = 3.0;

        Double wd1 = 12.1;
        Double wd2 = 6.0;

        System.out.println(operation.addition(wd1.intValue(), wd2.intValue()));
        System.out.println(operation.soustraction(wd1.intValue(), wd2.intValue()));
        System.out.println(operation.multiplication(wd1, wd2));
        System.out.println(operation.division(wd1, wd2));
        System.out.println(outilsTexte.isPalindrome());
        System.out.println(outilsTexte.stringToInt("2312"));

    }


}
