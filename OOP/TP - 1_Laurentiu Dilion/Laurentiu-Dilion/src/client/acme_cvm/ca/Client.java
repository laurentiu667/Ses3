package client.acme_cvm.ca;

public class Client {

    private int noClient;
    private String nomClient;

    public int getNoClient(){
        return noClient;
    }
    public String getNomClient(){
        return nomClient;
    }

    public void setNoClient(int noClient) {
        this.noClient = noClient;
    }

    public void setNomClient(String nomClient) {
        this.nomClient = nomClient;
    }
}
