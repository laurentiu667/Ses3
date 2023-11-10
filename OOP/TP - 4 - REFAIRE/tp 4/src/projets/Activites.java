package projets;
import java.time.*;
public class Activites {
    private String nom;
    private String description;
    private LocalDateTime heureDebut;
    private LocalDateTime heureFin;

    public Activites(String nom, String description, LocalDateTime heureDebut, LocalDateTime heureFin) {
        this.nom = nom;
        this.description = description;
        this.heureDebut = heureDebut;
        this.heureFin = heureFin;
    }

    public long minuteDepenser(){
        return Duration.between(heureDebut, heureFin).toMinutes();
    }

    public void afficherInfo(){
        System.out.println("Nom : " + this.nom + "Description : " + this.description + "L'heure de debut : " + heureDebut + "L'heure de fin : " + heureFin);
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

}
