package l03bgym;

public class TestConstructeur {
    public static void main(String[] args) {
        AbonnementGym a = new AbonnementGym ( "Martin Miron");
        AbonnementGym b = new AbonnementGym ( "Mylene Deschamps", 4);
        AbonnementGym c = new AbonnementGym ( "Marc Gauthier", 20, 78);

        System.out.println(a.getPrix());

    }
}
