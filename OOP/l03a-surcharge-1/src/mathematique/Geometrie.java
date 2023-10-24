package mathematique;

public class Geometrie {
    public static void main(String[] args) {
        Perimetre perimetre = new Perimetre();

        perimetre.calculPerimetre(23);
        perimetre.calculPerimetre(23.3f, 23.6f, 74);
    }
}
