import java.awt.* ;
import javax.swing.*;
public class GoHorloge{
	public static void main(String [] args){
		Horloge horraire = new Horloge();
		JLabel label = new JLabel();
		JFrame fenHorloge = new JFrame("Horloge");
		fenHorloge.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fenHorloge.setSize(400,400);
		fenHorloge.setLocation(50,50);
		fenHorloge.setResizable(true);
		Container contHorloge = fenHorloge.getContentPane();
		contHorloge.setLayout(new FlowLayout());
		contHorloge.add(label);
		while(true){
			System.out.println("horraire = "+horraire);
			label.setText(horraire.toString());
			fenHorloge.setVisible(true);
			Horloge.pause(1000);
			horraire.update();
		}
	}
}