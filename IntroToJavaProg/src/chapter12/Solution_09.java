/**
 * Chapter 12
 * Solution_09.java
 * 2016.08.11
 */


package chapter12;

import java.awt.*;
import javax.swing.*;
import java.util.Random;


public class Solution_09 extends JFrame {
	private ImageIcon icon1 = new ImageIcon("input/1.jpg");
	private ImageIcon icon2 = new ImageIcon("input/2.jpg");
	private ImageIcon icon3 = new ImageIcon("input/3.jpg");
	private ImageIcon icon4 = new ImageIcon("input/4.jpg");
	private ImageIcon icon5 = new ImageIcon("input/5.jpg");
	private ImageIcon icon6 = new ImageIcon("input/6.jpg");
	
	public ImageIcon selectIcon(int iconNum) {
		switch(iconNum) {
			case 1: return icon1; 
			case 2: return icon2;
			case 3: return icon3;
			case 4: return icon4;
			case 5: return icon5;
			case 6: return icon6;
			default: return new ImageIcon();
		}
	}
	
	public Solution_09() {
		int randNum1 = (int)(Math.random() * 10) % 6 + 1;
		int randNum2 = (int)(Math.random() * 10) % 6 + 1;
		while (randNum2 == randNum1) {
			randNum2 = (int)(Math.random() * 10) % 6 + 1;
		}
		int randNum3 = (int)(Math.random() * 10) % 6 + 1;
		while (randNum3 == randNum1 || randNum3 == randNum1) {
			randNum3 = (int)(Math.random() * 10) % 6 + 1;
		}
		
		
		JLabel jl1 = new JLabel(selectIcon(randNum1));
		JLabel jl2 = new JLabel(selectIcon(randNum2));
		JLabel jl3 = new JLabel(selectIcon(randNum3));
		JPanel jp = new JPanel(new GridLayout(1, 3));
		
		jp.add(jl1);
		jp.add(jl2);
		jp.add(jl3);
		
		add(jp);
	}
	
	public static void main(String[] args) {
		JFrame frame = new Solution_09();
		frame.setTitle("Exercise12_9");
		frame.setSize(900, 600);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}	
}