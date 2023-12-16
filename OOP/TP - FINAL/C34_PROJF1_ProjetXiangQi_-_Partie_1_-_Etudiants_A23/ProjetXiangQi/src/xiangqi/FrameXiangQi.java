package xiangqi;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class FrameXiangQi extends JFrame {

	private JPanel contentPane;
	JPanel panelConteneur;
	JLabel labelImage, labelCouleur;
	JLabel grille[][]; //90 JLabels transparents supperposés aux intersections
	JPanel panelNoirs, panelRouges, panelControle;
	JButton boutonDebuter, boutonRecommencer;
	Ecouteur ec;
	Echiquier echiquier; //Échiquier faisant le lien avec la logique du jeu

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		try {
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
		} catch (Throwable e) {
			e.printStackTrace();
		}
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					FrameXiangQi frame = new FrameXiangQi();
					frame.setVisible(true);
					frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 *constructeur
	 */
	public FrameXiangQi() {

		// Initialiser les variables (tableaux) pour conserver l'état du jeu (où sont les pièces) ET son affichage graphique
		echiquier = new Echiquier(); // État du jeu: création de l'échiquier et des 90 JLabels
		grille = new JLabel[10][9];  // État de l'affichage graphique du jeu: création d'une grille de JLabels pour afficher les pièces
		
		//  Fenêtre complète du jeu
		setTitle("XiangQi");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 936, 900);  //height original: 759
		contentPane = new JPanel();
		contentPane.setBackground(new Color(255, 228, 196));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		//  Panneau du plateau de jeu (Échiquier)
		panelConteneur= new JPanel();
		panelConteneur.setBackground(new Color(255, 228, 196));
		panelConteneur.setBounds(26, 77, 675, 750);  //Original witdh: 675, height 643
		panelConteneur.setLayout(new GridLayout(10, 9, 0, 0));
		panelConteneur.setOpaque(false);
		contentPane.add(panelConteneur);

		// Graphique de l'échiquier (la grille, lignes, colonnes, rivière, palais etc.)
		labelImage= new JLabel("");
		labelImage.setBounds(30, 105, 690, 700);  // Original width=690, height=627
		contentPane.add(labelImage);
		labelImage.setIcon(( new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/fond.png")));

		//  Panneau pour afficher les pièces noires qui ont été mangées
		panelNoirs = new JPanel();
		panelNoirs.setBackground(UIManager.getColor("CheckBox.darkShadow"));
		panelNoirs.setBorder(new LineBorder(new Color(0, 0, 0), 1, true));
		panelNoirs.setBounds(772, 77, 68, 751);
		contentPane.add(panelNoirs);

		//  Panneau pour afficher les pièces rouges qui ont été mangées
		panelRouges = new JPanel();
		panelRouges.setBackground(new Color(255, 102, 102));
		panelRouges.setBorder(new LineBorder(new Color(0, 0, 0), 1, true));
		panelRouges.setBounds(850, 77, 68, 751);
		contentPane.add(panelRouges);

		//  Panneau pour menu du haut avec texte et boutons Débuter et Recommencer
		panelControle = new JPanel();
		panelControle.setBackground(new Color(255, 228, 196));
		panelControle.setBorder(new LineBorder(new Color(0, 0, 0), 1, true));
		panelControle.setBounds(0, 11, 918, 58);
		contentPane.add(panelControle);
		panelControle.setLayout(null);

		//  Bouton Recommencer
		boutonRecommencer = new JButton("Recommencer");
		boutonRecommencer.setBounds(744, 22, 152, 23);
		boutonRecommencer.setBackground(new Color(255,239,213));
		boutonRecommencer.setContentAreaFilled(false);
		boutonRecommencer.setOpaque(true);
		panelControle.add(boutonRecommencer);
		boutonRecommencer.setFont(new Font("Tahoma", Font.BOLD, 15));

		// Bouton Débuter
		boutonDebuter = new JButton("D\u00E9buter");
		boutonDebuter.setBackground(new Color(255, 239, 213));
		boutonDebuter.setBounds(610, 22, 119, 23);
		boutonDebuter.setContentAreaFilled(false);
		boutonDebuter.setOpaque(true);
		panelControle.add(boutonDebuter);
		boutonDebuter.setFont(new Font("Tahoma", Font.BOLD, 15));
		labelCouleur = new JLabel("");
		labelCouleur.setBackground(new Color(255, 239, 213));
		labelCouleur.setOpaque(true);
		labelCouleur.setBounds(53, 11, 475, 41);
		
		panelControle.add(labelCouleur);
		labelCouleur.setFont(new Font("Tahoma", Font.BOLD, 20));

		//  Création de l'écouteur: c'est cet élément du Frame qui permet de détecter des clics de souris
		//  sur des éléments précis comme des boutons, des JLabels etc.
		//  C'est la gestion des événements
		ec = new Ecouteur();

		// C'est ici que les JLabels transparents de la grille sont initialisés
		//  On affichera les pièces sur les JLabels en leur associant un graphique
		//  On ajoute un écouteur pour détecter un clic de souris sur chaque JLabel de la grille
		for ( int i = 0 ; i < 10 ; i ++ )
			for ( int j = 0 ; j < 9 ; j ++ )
			{
				grille[i][j] = new JLabel();
				grille[i][j].addMouseListener( ec );
				panelConteneur.add( grille[i][j]);
				grille[i][j].setHorizontalAlignment(SwingConstants.CENTER);
			}

		// On ajouter aussi des écouteurs pour détecter des clics de souris sur chacun des 2 boutons
		boutonDebuter.addMouseListener(ec);
		boutonRecommencer.addMouseListener(ec);
	}

	// La classe écouteur contient tout le code qui traite les actions à entreprendre
	// lorsqu'un clic de souris est détecté sur un des éléments spécifiés
	private class Ecouteur extends MouseAdapter
	{
		int ligneClic, colonneClic;
		Piece pieceTampon, pieceEnlevee;
		ImageIcon iconeTampon, iconeTamponPieceManger;
		Position depart, arrivee;
		String couleurControle; //valeur rouge ou noir ;
		
		//  Cette méthode suit les tours de jeu pour s'assurer qu'un joueur ne peut jouer en dehors de son tour
		public void alterne ()
		{
		if (couleurControle == "rouge")
			couleurControle = "noir";
		else
			couleurControle = "rouge";
			labelCouleur.setText("C'est aux " + couleurControle + "s à jouer ");
		}

		// Enlève toutes les pièces de l'affichage graphique, sur l'échiqiuer et dans les panneaux de pièces mangées
		public void enleverToutesLesPieces()
		{
			// Vider les panneaux de pièces mangées
			panelRouges.removeAll();
			panelNoirs.removeAll();

			// Enlever toutes les pièces de l'affichage de l'échiquier
			for ( int i = 0; i < 10 ; i++ ) {
				for ( int j = 0; j < 9 ; j ++) {
					grille[i][j].setIcon (null);
				}
			}
		}

		public void afficherPiecesPourDebut()
		{
			grille[0][0].setIcon(new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/charNoir.png"));
			grille[0][1].setIcon( new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/cavalierNoir.png"));
			grille[0][2].setIcon( new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/elephantNoir.png"));
			grille[0][3].setIcon( new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/mandarinNoir.png"));
			grille[0][4].setIcon( new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/roiNoir.png"));
			grille[0][5].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/mandarinNoir.png"));
			grille[0][6].setIcon( new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/elephantNoir.png"));
			grille[0][7].setIcon( new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/cavalierNoir.png"));
			grille[0][8].setIcon(new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/charNoir.png"));
			grille[2][1].setIcon( new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/bombardeNoir.png"));
			grille[2][7].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/bombardeNoir.png"));
			grille[3][0].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionNoir.png"));
			grille[3][2].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionNoir.png"));
			grille[3][4].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionNoir.png"));
			grille[3][6].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionNoir.png"));
			grille[3][8].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionNoir.png"));

			grille[9][0].setIcon(new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/charRouge.png"));
			grille[9][1].setIcon( new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/cavalierRouge.png"));
			grille[9][2].setIcon( new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/elephantRouge.png"));
			grille[9][3].setIcon( new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/mandarinRouge.png"));
			grille[9][4].setIcon( new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/roiRouge.png"));
			grille[9][5].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/mandarinRouge.png"));
			grille[9][6].setIcon( new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/elephantRouge.png"));
			grille[9][7].setIcon( new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/cavalierRouge.png"));
			grille[9][8].setIcon(new ImageIcon ("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/charRouge.png"));
			grille[7][1].setIcon( new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/bombardeRouge.png"));
			grille[7][7].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/bombardeRouge.png"));
			grille[6][0].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionRouge.png"));
			grille[6][2].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionRouge.png"));
			grille[6][4].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionRouge.png"));
			grille[6][6].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionRouge.png"));
			grille[6][8].setIcon(new ImageIcon("C34_PROJF1_ProjetXiangQi_-_Partie_1_-_Etudiants_A23/ProjetXiangQi/icones/pionRouge.png"));
		}

		public void recommencer(){
			echiquier = new Echiquier ();
		    echiquier.debuter();

			enleverToutesLesPieces();
			afficherPiecesPourDebut();

		    couleurControle = "noir";
		    labelCouleur.setText("C'est aux " + couleurControle + "s à jouer ");

		    // Rafraichir l'affichage en fonction des desrniers changements
			repaint();
		    panelRouges.updateUI();
		    panelNoirs.updateUI();
		}

		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub

			if ( e.getSource() == boutonDebuter)
			{
				echiquier.debuter();
				//icones
				afficherPiecesPourDebut();

				couleurControle="rouge";  // rouges commencent en premier
				labelCouleur.setText("C'est aux " + couleurControle + "s à jouer ");
			}
			else if ( e.getSource() == boutonRecommencer)
			{
				recommencer();
			}
			else // il s'agit d'un label / intersection
			{
			    //trouver lequel
			    for ( int i = 0; i < 10 ; i++ )
			    {
			    	for ( int j = 0; j < 9; j++ )
			        {
			        	if (e.getSource() == grille[i][j])
			        	{
			        		ligneClic = i;  //  Numéro de la ligne de l'intersection qui a été cliquée
							colonneClic = j;  //  Numéro de la colonne de l'intersection qui a été cliquée
						}
					}
				}
				Piece piece = echiquier.getIntersection(ligneClic, colonneClic).getPiece();
				if (piece != null && couleurControle.equals(piece.getCouleur())) {
					depart = new Position(ligneClic, colonneClic);
					pieceTampon = echiquier.getIntersection(ligneClic, colonneClic).getPiece();
					iconeTampon = (ImageIcon) grille[ligneClic][colonneClic].getIcon();
					grille[ligneClic][colonneClic].setIcon(null);
				}

				// Cas coup d'arrivée (sans capture de pièces)
				else if (echiquier.getIntersection(ligneClic, colonneClic).getPiece() == null) {

					Position arrivee = new Position(ligneClic, colonneClic);

					if (echiquier.getIntersection(depart.getLigne(), depart.getColonne()).getPiece().estValide(depart, arrivee)) {

						if (echiquier.cheminPossible(depart, arrivee)) {

							if (echiquier.roisNePouvantPasEtreFaceAFace(depart, arrivee)) {

								echiquier.getIntersection(depart.getLigne(), arrivee.getColonne()).setPiece(null);

								echiquier.getIntersection(ligneClic, colonneClic).setPiece(pieceTampon);
								pieceTampon = null;

								grille[arrivee.getLigne()][arrivee.getColonne()].setIcon(iconeTampon);
								iconeTampon = null;

								ec.alterne();
							}
						}
					}
				}

				// Autre cas d'arrivée (avec capture de pièce)
				else if (echiquier.getIntersection(ligneClic, colonneClic).getPiece() != null) {
					depart = new Position(ligneClic, colonneClic);
					iconeTamponPieceManger = (ImageIcon) grille[ligneClic][colonneClic].getIcon();

					if (echiquier.getIntersection(depart.getLigne(), depart.getColonne()).getPiece().estValide(depart, arrivee)) {

						if (echiquier.cheminPossible(depart, arrivee)) {

							if (echiquier.roisNePouvantPasEtreFaceAFace(depart, arrivee)) {

								echiquier.getIntersection(depart.getLigne(), arrivee.getColonne()).setPiece(null);

								echiquier.getIntersection(ligneClic, colonneClic).setPiece(pieceTampon);
								System.out.println("test");
								if (pieceTampon.getCouleur() == "rouge"){
									panelRouges.add(new JLabel (iconeTamponPieceManger));
								} else if(pieceTampon.getCouleur() == "noir"){
									panelNoirs.add(new JLabel (iconeTamponPieceManger));
								}
								pieceTampon = null;

								grille[arrivee.getLigne()][arrivee.getColonne()].setIcon(iconeTampon);
								iconeTampon = null;

								ec.alterne();

							}
						}
					}
				}

				// Penser à ne pas permettre l'auto-capture de pièce


			}
		}
	}
}

