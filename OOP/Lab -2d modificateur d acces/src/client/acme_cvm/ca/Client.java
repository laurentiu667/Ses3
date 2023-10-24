package client.acme_cvm.ca;

public class Client {

    private String nomComplet;
    private String nas;
    private int age;
    private String codePostal;
    public void setClient(String nomComplet, String nas, int age, String codePostal) {
        this.nomComplet = nomComplet;
        this.nas = nas;
        this.age = age;
        this.codePostal = codePostal;
    }
}
