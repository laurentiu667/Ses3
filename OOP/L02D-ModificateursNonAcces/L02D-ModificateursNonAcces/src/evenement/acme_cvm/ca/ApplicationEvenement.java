package evenement.acme_cvm.ca;



public class ApplicationEvenement {
    public static void main(String[] args) {
        // Initialisation des champs static
        Invite.setNbreInvites(0);
        Invite.setSequenceInvite(12300000);

        // Création de 3 invités
        Invite invite1 = new Invite();
        invite1.setInvite("Cric");

        Invite invite2 = new Invite();
        invite2.setInvite("Crac");

        Invite invite3 = new Invite();
        invite3.setInvite("Croc");

        // Affichage des valeurs
        System.out.println("Le code de " + invite1.getNomComplet() + " est" + invite1.getCodeInvite() );
        System.out.println("Le code de " + invite2.getNomComplet() + " est" + invite2.getCodeInvite() );
        System.out.println("Le code de " + invite3.getNomComplet() + " est" + invite3.getCodeInvite() );

        System.out.println("Le nombre d'invités est de " + Invite.getNbreInvites());
        System.out.println("La prochaine valeur de sequenceInvite est: " + Invite.getSequenceInvite());



    }
}
