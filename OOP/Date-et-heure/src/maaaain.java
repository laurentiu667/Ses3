
import java.time.*;
import java.time.format.DateTimeFormatter;

public class maaaain {

    public static void main(String[] args) {
        String modele = "yyyy-MM-dd HH-mm-ss";
        LocalDateTime aujourdhui = LocalDateTime.now();
        LocalDateTime date = DateTimeFormatter.ofPattern(modele);

        System.out.println(date.format(aujourdhui));

        LocalDate quebec =  LocalDate.of(1608, 7,3);
        System.out.println("le quebec a ete fonder en : " + quebec.getDayOfMonth() + quebec.getMonth() + quebec.getYear());


        System.out.println(aujourdhui.plusMonths(1));

        LocalDateTime aujourdhuiSemaineHeure = LocalDateTime.now().plusWeeks(1).minusHours(1);
        System.out.println(aujourdhuiSemaineHeure);

        LocalDate mortBeet = LocalDate.of(1827, 4, 26);

        Period dif = Period.between(mortBeet, LocalDate.from(aujourdhui));

        System.out.println("Nombre de jours d annee: " + dif.getYears());


        LocalTime commencer = LocalTime.of(9,0,0);
        LocalTime fin = LocalTime.of(10,27,26);
        Duration total = Duration.between(commencer, fin);
        System.out.println(total);
        LocalTime apres = LocalTime.of(13,25,1);
        apres = apres.plus(total);
        System.out.println(apres.getHour() + " heures " + apres.getMinute() + " minutes " + apres.getSecond() + " secondes");


    }
}
