package mathematique;

public class Perimetre {

    private float perimetreCalcule;

    public void calculPerimetre(float longeur_carrer){
        perimetreCalcule = 4 * longeur_carrer;

        System.out.println("Le perimetre du carrer est " +  perimetreCalcule);
    }

    public void calculPerimetre(float cote_1, float cote_2, float cote_3){
        perimetreCalcule = cote_1 + cote_2 + cote_3;

        System.out.println("Le perimetre du triangle est " +  perimetreCalcule);
    }

}
