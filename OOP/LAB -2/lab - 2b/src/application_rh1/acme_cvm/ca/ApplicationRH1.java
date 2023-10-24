package application_rh1.acme_cvm.ca;

import utils_rh.acme_cvm.ca.EchelleAugmentation;
import utils_rh.acme_cvm.ca.EchelleSalariale;
import employes.acme_cvm.ca.Employe;

public class ApplicationRH1 {
    public static void main(String[] args) {
        int compteEmployes = 0;
        int compteExperience  = 0;
        int anneeCible = 2023   ;
        int ancienneteRetraite  = 35;

        Employe employe1 = new Employe();
        Employe employe2 = new Employe();

        employe1.setNomComplet("Albert Einstein");
        employe1.setSalaire(45_000);
        employe1.setAnneeEmbauche(2000);

        employe2.setNomComplet("Marie Curie");
        employe2.setSalaire(74_000);
        employe2.setAnneeEmbauche(2010);

        compteEmployes += 2;
        compteExperience += employe1.ancienneteParAnneeCible(anneeCible) + employe2.ancienneteParAnneeCible(anneeCible);

        System.out.println("**********************");
        System.out.println("EMPLOYES ET ANCIENNETE");
        System.out.println("**********************\n");
        System.out.println("1. Salaire de " + employe1.getNomComplet() + " est de: " + employe1.getSalaire());
        System.out.println("2. Salaire de " + employe2.getNomComplet() + " est de: " + employe2.getSalaire());
        System.out.println("3. " + employe1.getNomComplet() + " a été embauché en " + employe1.getAnneeEmbauche());
        System.out.println("4. " + employe1.getNomComplet() + " aura " + employe1.ancienneteParAnneeCible(anneeCible) + " ans d'ancienneté en " + anneeCible);
        System.out.println("5. " + employe2.getNomComplet() + " a été embauché en " + employe2.getAnneeEmbauche());
        System.out.println("6. Lorsque " + employe2.getNomComplet() + " aura " + ancienneteRetraite + " ans d'ancienneté, nous serons en " + employe2.anneeCiblePourAnciennete(ancienneteRetraite));
        System.out.println("7. Le nombre total d'employés est de " + compteEmployes);
        System.out.println("8. Le nombre total d'années d'expérience des employés de l'entreprise est de " + compteExperience);

        EchelleSalariale echelleSalariale = new EchelleSalariale();
        EchelleAugmentation echelleAugmentation = new EchelleAugmentation();

        echelleAugmentation.setNiveaux(0.02, 0.03);

        System.out.println("\n******************************************");
        System.out.println(" ECHELLE SALARIALE ET TAUX D'AUGMENTATION");
        System.out.println("******************************************\n");
        System.out.println("1. Le salaire maximum pour le niveau 1 est de " + echelleSalariale.salaireMaxParSalaire(1));
        System.out.println("2. Le salaire maximum pour le niveau 2 est de " + echelleSalariale.salaireMaxParSalaire(2));
        System.out.println("3. Le salaire maximum pour un employe qui gagne $40 000.00 est de " + echelleSalariale.salaireMaxParSalaire(40000));
        System.out.println("4. Le salaire maximum pour un employe qui gagne $50 000.00 est de " + echelleSalariale.salaireMaxParSalaire(50000));
        System.out.println("5. Le salaire maximum pour " + employe1.getNomComplet() + " est de " + echelleSalariale.salaireMaxParSalaire(employe1.getSalaire()));
        System.out.println("6. Le salaire maximum pour " + employe2.getNomComplet() + " est de " + echelleSalariale.salaireMaxParSalaire(employe2.getSalaire()));
        System.out.println("7. Le taux d'augmentation annuelle pour un employé de niveau 1 est de " + echelleAugmentation.tauxAugmentationParNiveau(1));
        System.out.println("8. Le taux d'augmentation annuelle pour un employé de niveau 2 est de " + echelleAugmentation.tauxAugmentationParNiveau(2));
        System.out.println("9. Le taux d'augmentation annuelle d'un employé qui gagne $40,000.00 est de " + echelleAugmentation.tauxAugmentationParSalaire(40000));
        System.out.println("10. Le taux d'augmentation annuelle d'un employé qui gagne $50,000.00 est de " + echelleAugmentation.tauxAugmentationParSalaire(50000));
        System.out.println("11. Le taux d'augmentation annuelle de " + employe1.getNomComplet() + " est de " + echelleAugmentation.tauxAugmentationParSalaire(employe1.getSalaire()));
        System.out.println("12. Le taux d'augmentation annuelle de " + employe2.getNomComplet() + " est de " + echelleAugmentation.tauxAugmentationParSalaire(employe2.getSalaire()));

        System.out.println("\n*********************************");
        System.out.println("AUGMENTATION DE SALAIRE ANNUELLES");
        System.out.println("*********************************\n");

        double salaireAugmente1 = echelleAugmentation.salaireAugmente(employe1.getSalaire());
        double salaireAugmentePlafonne1 = echelleAugmentation.salaireAugmentePlafonne(employe1.getSalaire());
        double salaireAugmente2 = echelleAugmentation.salaireAugmente(employe2.getSalaire());
        double salaireAugmentePlafonne2 = echelleAugmentation.salaireAugmentePlafonne(employe2.getSalaire());

        System.out.println("1. Le salaire actuel de " + employe1.getNomComplet() + " est de " + employe1.getSalaire() + " et son salaire + augmentation serait de " + salaireAugmente1);
        System.out.println("2. Le salaire actuel de " + employe1.getNomComplet() + " est de " + employe1.getSalaire() + " et son salaire + augmentation plafonnée sera de " + salaireAugmentePlafonne1);
        System.out.println("3. Le salaire actuel de " + employe2.getNomComplet() + " est de " + employe2.getSalaire() + " et son salaire + augmentation serait de " + salaireAugmente2);
        System.out.println("4. Le salaire actuel de " + employe2.getNomComplet() + " est de " + employe2.getSalaire() + " et son salaire + augmentation plafonnée sera de " + salaireAugmentePlafonne2);



    }
}




