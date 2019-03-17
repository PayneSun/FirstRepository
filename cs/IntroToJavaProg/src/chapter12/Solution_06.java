/**
 * Chapter 12
 * Solution_06.java
 * 2016.08.11
 */


package chapter12;

import java.awt.*;
import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.LineBorder;


public class Solution_06 extends JFrame {
	private ImageIcon icon1 = new ImageIcon("input/c4.png");
	private ImageIcon icon2 = new ImageIcon("input/c5.png");
	private ImageIcon icon3 = new ImageIcon("input/c5.png");
	private ImageIcon icon4 = new ImageIcon("input/c4.png");
	
	public Solution_06() {
		Border lineBorder = new LineBorder(Color.BLACK, 1);			
		JPanel jp = new JPanel(new GridLayout(2, 2));
		JLabel jl1 = new JLabel(icon1);
		JLabel jl2 = new JLabel(icon2);
		JLabel jl3 = new JLabel(icon3);
		JLabel jl4 = new JLabel(icon4);
		
		jl1.setBorder(lineBorder);	
		jl2.setBorder(lineBorder);
		jl3.setBorder(lineBorder);
		jl4.setBorder(lineBorder);
		
		jp.add(jl1);
		jp.add(jl2);
		jp.add(jl3);
		jp.add(jl4);		
		
		add(jp);
	}	

	public static void main(String[] args) {
		JFrame frame = new Solution_06();
		frame.setTitle("Solution_06");
		frame.setSize(550, 450);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

