
import java.time.*;
import java.util.Arrays;

public class main {

    public static void main(String[] args) {
        LocalDateTime maintenant = LocalDateTime.now();
        LocalDateTime dans3Jours = maintenant.plusDays(3);
        Duration intervalle = Duration.between(maintenant, dans3Jours);
        System.out.println("Temps écoulé en jours: " + intervalle.toDays());
        System.out.println("Temps écoulé en heures: " + intervalle.toHours());
        System.out.println("Temps écoulé en minutes: " + intervalle.toMinutes());

    }
}
