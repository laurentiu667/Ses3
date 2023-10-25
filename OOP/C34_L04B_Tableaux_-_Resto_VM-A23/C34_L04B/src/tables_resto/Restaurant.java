package tables_resto;

import javax.swing.text.TableView;

public class Restaurant{

    private final int NB_TABLE = 75;
    Table[] tableRestaurant = new Table[NB_TABLE]; // Utilisez la constante pour la taille du tableau

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
        for (int i = 1; i <= tableRestaurant.length; i++){
            if (tableRestaurant[i].isOccupe() == true) {
                nombreOccupees++;
            }
        }
        return nombreOccupees;
    }
    public int assignerTableDispo(int nombrePersonne){
        int tableDispo = NB_TABLE - nbTableOccupees();
        if (tableDispo > 0){
            for (Table table: tableRestaurant){
                if (table.isOccupe() ==  false && nombrePersonne <= 2){

                }
            }
        }

    }

}
