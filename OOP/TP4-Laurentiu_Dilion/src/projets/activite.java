package projets;
import java.time.*;
public class activite {
    private String nom;
    private String description;
    private LocalDateTime heureDebut;
    private LocalDateTime heureFin;

    public activite(String nom, String description, LocalDateTime heureDebut, LocalDateTime heureFin) {
        this.nom = nom;
        this.description = description;
        this.heureDebut = heureDebut;
        this.heureFin = heureFin;
    }

    public long calculerMinutesActivite(){
        Duration duration = Duration.between(heureFin, heureDebut);
        return duration.toMinutes();
    }

    public void afficherInfoActivite(){
        System.out.println("Nom : " + nom + " | Description : " + description + " | Début : " + heureDebut + " | Fin : " + heureFin);
    }

    public String getNom() {
        return nom;
    }

    public String getDescription() {
        return description;
    }

    public LocalDateTime getHeureDebut() {
        return heureDebut;
    }

    public LocalDateTime getHeureFin() {
        return heureFin;
    }

    // Setters pour les attributs
    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setHeureDebut(LocalDateTime heureDebut) {
        this.heureDebut = heureDebut;
    }

    public void setHeureFin(LocalDateTime heureFin) {
        this.heureFin = heureFin;
    }


}
