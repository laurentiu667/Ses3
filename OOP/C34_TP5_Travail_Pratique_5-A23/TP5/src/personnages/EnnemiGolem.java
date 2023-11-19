package personnages;

import items.*;     // Pour Arme et Armure

public class EnnemiGolem extends PersonnageEnnemi{
    public EnnemiGolem(String nom) {
        super(nom, 800);
        Arme arme = new Arme("Poings", 1 , 50);
        Armure armure = new Armure("Carapace", 1, 40);
        setArme(arme);
        setArmure(armure);
    }



}
