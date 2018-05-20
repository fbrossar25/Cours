import java.awt.* ;
import javax.swing.*;
public class VoirFenetre{
	public static void main(String[] args){
		JFrame fen = new JFrame();
		ButtonGroup bg = new ButtonGroup();
		JRadioButton jrb1 = new JRadioButton("Je veut continuer la POO");
		JRadioButton jrb2 = new JRadioButton("Je ne veut pas continuer la POO");
		bg.add(jrb1);
		bg.add(jrb2);
		fen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fen.setSize(300,500);
		fen.setLocation(50,50);
		fen.setTitle("Premiere fenetre");
		fen.setVisible(true);
		Container contFen = fen.getContentPane();
		contFen.setLayout(new FlowLayout());
		JButton b = new JButton("Bouton qui ne fait rien (Attention : ne sert a rien !)");
		contFen.add(b);
		JButton troll = new JButton("Quitter (muhahaha!!!)");
		troll.setEnabled(false);
		contFen.add(troll);
		JCheckBox choix1 = new JCheckBox("- Java est genial !");
		contFen.add(choix1);
		JCheckBox choix2 = new JCheckBox("- J'aime la POO");
		choix2.doClick();
		contFen.add(choix2);
		JCheckBox choix3 = new JCheckBox("- J'aime les jeux videos");
		choix3.doClick();
		contFen.add(choix3);
		JCheckBox choix4 = new JCheckBox("- Je n'aime pas les vacances");
		contFen.add(choix4);
		fen.setVisible(true);
		contFen.add(jrb1);
		contFen.add(jrb2);
		fen.setVisible(true);
	}
}