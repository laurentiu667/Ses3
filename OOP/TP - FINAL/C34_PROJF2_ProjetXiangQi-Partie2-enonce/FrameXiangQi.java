package xiangqi;

import xiangqiPartie2.Echiquier;

import java.awt.EventQueue;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;

import java.awt.Font;
import javax.swing.JButton;
import javax.swing.border.LineBorder;



import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.UIManager;

public class FrameXiangQi extends JFrame {

	private JPanel contentPane;
	JPanel panelConteneur;
	JLabel labelImage, labelCouleur;
	JLabel grille[][]; //90 JLabels transparents s'apparentant aux intersections
	JPanel panelControle;
	JButton boutonDebuter, boutonRecommencer;
	Ecouteur ec;
	Echiquier echiquier; //�chiquier faisant le lien avec la logique du jeu

	
	
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
		
		echiquier = new Echiquier(); //cr�ation de l'�chiquier et des 90 JLabels
		grille = new JLabel[10][9];
		
		
		setTitle("XiangQi");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 944, 878);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(255, 228, 196));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		
		
		panelConteneur= new JPanel();
		panelConteneur.setBackground(new Color(255, 228, 196));
		panelConteneur.setBounds(26, 77, 670, 765);
		panelConteneur.setLayout(new GridLayout(10, 9, 0, 0));
		panelConteneur.setOpaque(false);
		contentPane.add(panelConteneur);
		
		labelImage= new JLabel("");
		labelImage.setBounds(30, 85, 690, 627);
		contentPane.add(labelImage);
		labelImage.setIcon(( new ImageIcon("icones/fond.png")));
		
		panelControle = new JPanel();
		panelControle.setBackground(new Color(255, 228, 196));
		panelControle.setBorder(new LineBorder(new Color(0, 0, 0), 1, true));
		panelControle.setBounds(0, 11, 918, 58);
		contentPane.add(panelControle);
		panelControle.setLayout(null);
		
		boutonRecommencer = new JButton("Recommencer");
		boutonRecommencer.setBounds(744, 22, 152, 23);
		boutonRecommencer.setBackground(new Color(255,239,213));
		boutonRecommencer.setContentAreaFilled(false);
		boutonRecommencer.setOpaque(true);
		panelControle.add(boutonRecommencer);
		boutonRecommencer.setFont(new Font("Tahoma", Font.BOLD, 15));
		
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
		
		
		
		//gestion des �v�nements 
		ec = new Ecouteur();
		for ( int i = 0 ; i < 10 ; i ++ )
			for ( int j = 0 ; j < 9 ; j ++ )
			{
				grille[i][j] = new JLabel();
				grille[i][j].addMouseListener( ec );
				panelConteneur.add( grille[i][j]);
				grille[i][j].setHorizontalAlignment(SwingConstants.CENTER);
			}
		boutonDebuter.addMouseListener(ec);
		boutonRecommencer.addMouseListener(ec);
	
		
	

	}
	
	private class Ecouteur extends MouseAdapter
	{
		int ligneClic, colonneClic;
		Piece pieceTampon, pieceEnlevee;
		ImageIcon iconeTampon;
		Position depart, arrivee;
		String couleurControle; //valeur rouge ou noir ;
		
		
	
		  
		  
		
	

		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub
			
			if ( e.getSource() == boutonDebuter)
			{
			//CODER ICI #2	
			}
			else if ( e.getSource() == boutonRecommencer)
			{
			//CODER ICI #3
			}
			else // il s'agit d'un label / intersection
			{
			    //trouver lequel
			    for ( int i = 0; i < 10 ; i++ )
			      {
			      for ( int j = 0; j<9; j++ )
			        {
			        if (e.getSource() == grille[i][j])
			          {
			          ligneClic = i;
			          colonneClic = j;
			          }
			        }
			      }
			      
			// CODER ICI #4
			       
			            
			  }
			} // fin de la m�thode mouseReleased
			        
			      
	    }// fin de la classe Ecouteur
			
	}


			
		
		
	

