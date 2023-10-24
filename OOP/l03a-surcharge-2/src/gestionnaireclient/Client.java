package gestionnaireclient;

public class Client {

    private String typeClient;
    private String noTaxe;
    private String noCompagnie;

    public void ajoutIndividu(){
        typeClient = "Individu";
        noTaxe = "";
        noCompagnie = "";

        System.out.println("Le client est un " + typeClient +" et n’a pas de numéro de taxes ou de numéro de compagnie.");

    }
    public void ajoutIndividu(String information){
        typeClient = "OSBL";
        noTaxe = information;
        noCompagnie = "";

        System.out.println("Le client est un " + typeClient +" et son numéro de taxes est " + noTaxe);

    }

    public void ajoutIndividu(String information1, String information2){
        typeClient = "Compagnie";
        noTaxe = information1;
        noCompagnie = information2;

        System.out.println("Le client est une " + typeClient +
                           " son numéro de taxes est " + noTaxe +
                           " et son numéro de compagnie est " + noCompagnie);

    }


}
