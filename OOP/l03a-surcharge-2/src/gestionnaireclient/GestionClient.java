package gestionnaireclient;

public class GestionClient {
    public static void main(String[] args) {
        Client client1 = new Client();

        client1.ajoutIndividu();
        client1.ajoutIndividu("244512");
        client1.ajoutIndividu("3245", "5789");
    }
}
