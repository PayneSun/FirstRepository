/**
 * Chapter 12
 * Solution_07.java
 * 2016.08.11
 */


package chapter12;

import java.awt.*;
import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.LineBorder;


public class Solution_07 extends JFrame {
	private ImageIcon iconO = new ImageIcon("input/c4.png");
	private ImageIcon iconX = new ImageIcon("input/c5.png");
	
	public Solution_07() {
		Border lineBorder = new LineBorder(Color.BLACK, 1);			
		JPanel jp = new JPanel(new GridLayout(3, 3));
		
		for (int i = 1; i <= 9; i++) {
			JLabel jl = new JLabel();
			int randNum = (int)(Math.random() * 10) % 3;
	
			if ( randNum == 0) {
				jl = new JLabel(iconO);
			} else if ( randNum == 1) {
				jl = new JLabel(iconX);
			} else {}
			
			jl.setBorder(lineBorder);
			jp.add(jl);
		}
				
		add(jp);
	}	

	public static void main(String[] args) {
		JFrame frame = new Solution_07();
		frame.setTitle("Solution_07");
		frame.setSize(650, 600);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}	
}

