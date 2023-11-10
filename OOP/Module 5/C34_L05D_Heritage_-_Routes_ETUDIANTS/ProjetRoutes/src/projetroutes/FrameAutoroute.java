package projetroutes;

import java.awt.Dimension;

import java.awt.Font;
import java.awt.Rectangle;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.text.DecimalFormat;

import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class FrameAutoroute
        extends JFrame
{
    private JPanel jPanel1 = new JPanel();
    private JRadioButton boutonRoute = new JRadioButton();
    private JRadioButton boutonAutoroute = new JRadioButton();
    private JPanel jPanel2 = new JPanel();
    private JLabel jLabel1 = new JLabel();
    private JLabel jLabel2 = new JLabel();
    private JLabel jLabel3 = new JLabel();
    private JLabel jLabel4 = new JLabel();
    private JTextField champNbKilometres = new JTextField();
    private JTextField champNbPonts = new JTextField();
    private JTextField champNbPassages = new JTextField();
    private JCheckBox caseACocher = new JCheckBox();
    private JPanel jPanel3 = new JPanel();
    private JTextField champCout = new JTextField();
    private JButton boutonCout = new JButton();
    private JLabel jLabel5 = new JLabel();
    private JTextField champNbEchangeurs = new JTextField();
    private JLabel jLabel6 = new JLabel();

    public FrameAutoroute()
    {
        try
        {
            jbInit();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    private void jbInit()
            throws Exception
    {
        this.getContentPane().setLayout( null );
        this.setSize(new Dimension(503, 482));
        this.setTitle( "Coûts de construction" );
        jPanel1.setBounds(new Rectangle(25, 40, 435, 70));
        jPanel1.setBorder(BorderFactory.createTitledBorder("Type de chantier :"));
        boutonRoute.setText("Route");
        boutonRoute.setFont(new Font("Tahoma", 0, 16));
        boutonAutoroute.setText("Autoroute");
        boutonAutoroute.setFont(new Font("Tahoma", 0, 16));
        jPanel2.setBounds(new Rectangle(30, 130, 425, 220));
        jPanel2.setBorder(BorderFactory.createTitledBorder("Informations"));
        jPanel2.setLayout(null);
        jLabel1.setText("nombre de ponts:");
        jLabel1.setBounds(new Rectangle(15, 65, 290, 15));
        jLabel1.setFont(new Font("Tahoma", 0, 16));
        jLabel2.setText("nombre de kilomètres:");
        jLabel2.setBounds(new Rectangle(15, 30, 290, 15));
        jLabel2.setFont(new Font("Tahoma", 0, 16));
        jLabel3.setText("nombre de passages fauniques:");
        jLabel3.setBounds(new Rectangle(15, 105, 290, 15));
        jLabel3.setFont(new Font("Tahoma", 0, 16));
        jLabel4.setText("présence d'un accotement asphalté:");
        jLabel4.setBounds(new Rectangle(15, 145, 290, 15));
        jLabel4.setFont(new Font("Tahoma", 0, 16));
        champNbKilometres.setBounds(new Rectangle(370, 30, 40, 20));
        champNbPonts.setBounds(new Rectangle(370, 65, 40, 20));
        champNbPassages.setBounds(new Rectangle(370, 105, 40, 20));
        caseACocher.setBounds(new Rectangle(370, 145, 40, 20));
        jPanel3.setBounds(new Rectangle(30, 360, 425, 60));
        jPanel3.setBorder(BorderFactory.createTitledBorder("Estimé du coût "));
        jPanel3.setLayout(null);
        champCout.setBounds(new Rectangle(190, 25, 90, 20));
        boutonCout.setText("Calculer le coût :");
        boutonCout.setBounds(new Rectangle(15, 25, 135, 20));
        jPanel1.add(boutonRoute, null);
        jPanel1.add(boutonAutoroute, null);
        jPanel2.add(champNbEchangeurs, null);
        jPanel2.add(jLabel5, null);
        jPanel2.add(caseACocher, null);
        jPanel2.add(champNbPassages, null);
        jPanel2.add(champNbPonts, null);
        jPanel2.add(champNbKilometres, null);
        jPanel2.add(jLabel4, null);
        jPanel2.add(jLabel3, null);
        jPanel2.add(jLabel2, null);
        jPanel2.add(jLabel1, null);
        jPanel3.add(jLabel6, null);
        jPanel3.add(boutonCout, null);
        jPanel3.add(champCout, null);
        this.getContentPane().add(jPanel3, null);
        this.getContentPane().add(jPanel2, null);
        this.getContentPane().add(jPanel1, null);
        Ecouteur e = new Ecouteur ();
        boutonCout.addActionListener(e);

        EcouteurSelection es = new EcouteurSelection();
        boutonRoute.addActionListener(es);
        boutonAutoroute.addActionListener ( es);
        jLabel5.setText("nombre d'échangeurs:");
        jLabel5.setBounds(new Rectangle(15, 180, 290, 15));
        jLabel5.setFont(new Font("Tahoma", 0, 16));
        champNbEchangeurs.setBounds(new Rectangle(370, 180, 40, 20));
        ButtonGroup bg = new ButtonGroup ();
        bg.add( boutonRoute);
        bg.add(boutonAutoroute);
        boutonRoute.setSelected(true);
        champNbEchangeurs.setEnabled(false);
        jLabel6.setText("millions");
        jLabel6.setBounds(new Rectangle(295, 25, 85, 15));
        jLabel6.setFont(new Font("Tahoma", 0, 16));
    }

    private class Ecouteur implements ActionListener
    {
        public void actionPerformed ( ActionEvent ae)
        {
            // Rechercher les informations
            String  nbKilo = champNbKilometres.getText();
            String nbPo = champNbPonts.getText();
            String nbPass = champNbPassages.getText();
            boolean acco = caseACocher.isSelected();
            String nbEchan = champNbEchangeurs.getText();

            DecimalFormat df = new DecimalFormat ( "0.00$");
            //  si c'est une route
            if ( boutonRoute.isSelected())
            {

                // Créer un objet Route
                Route r = new Route ( Double.parseDouble(nbKilo), Integer.parseInt ( nbPo), Integer.parseInt( nbPass), acco);
                // Afficher le coût

                champCout.setText ( df.format (  r.calculerCout()));


            }
            // si c'est une autoroute
            else
            {
                // Créer un objet Autoroute
                Autoroute a = new Autoroute (Double.parseDouble(nbKilo), Integer.parseInt ( nbPo), Integer.parseInt( nbPass), Integer.parseInt ( nbEchan) );
                // Afficher le cout
                champCout.setText (df.format ( a.calculerCout()));
            }

        }
    }

    private class EcouteurSelection implements ActionListener
    {
        public void actionPerformed ( ActionEvent ae )
        {
            if ( ae.getSource() == boutonRoute )
                champNbEchangeurs.setEnabled(false);
            else
                champNbEchangeurs.setEnabled(true);
        }
    }

    public static void main ( String [] args )
    {
        FrameAutoroute fa = new FrameAutoroute();
        fa.setVisible(true);
        fa.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
