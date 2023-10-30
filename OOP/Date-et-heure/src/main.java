
import javax.swing.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.Arrays;

public class main {

    public static void main(String[] args) {
        String modele = "yyyy-MM-dd HH-mm-ss";
        LocalDateTime aujourdhui = LocalDateTime.now();
        DateTimeFormatter date = DateTimeFormatter.ofPattern(modele);

        System.out.println(date.format(aujourdhui));

        LocalDate quebec =  LocalDate.of(1608, 7,3);
        System.out.println("le quebec a ete fonder en : " + quebec.getDayOfMonth() + quebec.getMonth() + quebec.getYear());


        System.out.println(aujourdhui.plusMonths(1));

        LocalDateTime aujourdhuiSemaineHeure = LocalDateTime.now().plusWeeks(1).minusHours(1);
        System.out.println(aujourdhuiSemaineHeure);

        


    }
}
