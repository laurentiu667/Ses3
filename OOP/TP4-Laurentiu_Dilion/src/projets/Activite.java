package projets;
import java.time.*;
public class Activite {
    private String nom;
    private String description;
    private LocalDateTime heureDebut;
    private LocalDateTime heureFin;

    public Activite(String nom, String description, LocalDateTime heureDebut, LocalDateTime heureFin) {
        this.nom = nom;
        this.description = description;
        this.heureDebut = heureDebut;
        this.heureFin = heureFin;
    }

    public long calculerMinutesActivite() {
        Duration duration;
        if (heureFin.isAfter(heureDebut)) {
            duration = Duration.between(heureDebut, heureFin);
        } else {
            duration = Duration.between(heureFin, heureDebut);
        }
        return duration.toMinutes();
    }



    public void afficherInfoActivite(){
        System.out.println("Nom : " + nom + " | Description : " + description + " | Début : " + heureDebut + " | Fin : " + heureFin);
    }

    public String getNom() {
        return nom;
    }


}
