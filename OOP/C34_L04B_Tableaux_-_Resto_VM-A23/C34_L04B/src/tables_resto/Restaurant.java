package tables_resto;

import java.util.regex.Pattern;

public class Restaurant{

    private final int NB_TABLE = 75;
    Table[] tableRestaurant = new Table[NB_TABLE];

    public Restaurant() {
        for (int i = 0; i < NB_TABLE; i++) {
            if (i < 30) {
                tableRestaurant[i] = new Table(i + 1, 2, true);
            } else if (i < 35) {
                tableRestaurant[i] = new Table(i + 1, 2, false);
            } else if (i < 65) {
                tableRestaurant[i] = new Table(i + 1, 4, true);
            } else {
                tableRestaurant[i] = new Table(i + 1, 4, false);
            }
        }
    }

    public int nbTableOccupees(){
        int nombreOccupees = 0;
        for (Table table : tableRestaurant){
            if (table.isOccupe())
                nombreOccupees++;
        }
        return nombreOccupees;
    }
    public Table assignerTableDispo(int nombrePersonne, boolean banquettePreferee) {
        for (Table table : tableRestaurant) {
            if (!table.isOccupe() && table.getNbPlaces() >= nombrePersonne) {
                if (banquettePreferee) {
                    if (table.isBanquette()) {
                        table.setOccupe(true);
                        return table;
                    }
                } else {
                    table.setOccupe(true);
                    return table;
                }
            }
        }
        return null; // Aucune table disponible pour le groupe.
    }

    public boolean verifierSiTableOccupe(Table table){
        return table.isOccupe();
    }

}
