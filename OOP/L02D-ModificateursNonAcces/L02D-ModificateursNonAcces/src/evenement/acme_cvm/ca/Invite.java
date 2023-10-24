package evenement.acme_cvm.ca;

public class Invite {
    // Champs
    private static int nbreInvites;
    private static int sequenceInvite;
    private String codeInvite;
    private String nomComplet;

    // Méthodes d'accès (getters)
    public static int getNbreInvites() {   // Si le champ est static, la éthode doit être static
        return nbreInvites;    }
    public static int getSequenceInvite() {   // Si le champ est static, la éthode doit être static
        return sequenceInvite;    }
    public String getCodeInvite() {
        return codeInvite;    }
    public String getNomComplet() {
        return nomComplet;    }

    // méthodes de mutation (setters)
    public static void setNbreInvites(int nbreInvites) {   // Si le champ est static, la éthode doit être static
        Invite.nbreInvites = nbreInvites;    }
    public static void setSequenceInvite(int sequenceInvite) {   // Si le champ est static, la éthode doit être static
        Invite.sequenceInvite = sequenceInvite;    }

    // Méthode pour initialiser un invité, reçoit le nom en paramètre
    public void setInvite(String nomComplet){
        this.nomComplet = nomComplet;
        this.codeInvite = nomComplet.substring(0,3) + Integer.toString(this.sequenceInvite);
        this.sequenceInvite++;
        this.nbreInvites++;
    }
}
