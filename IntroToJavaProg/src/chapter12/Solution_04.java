/**
 * Chapter 12
 * Solution_04.java
 * 2016.08.11
 */


package chapter12;

import java.awt.*;
import javax.swing.*;


public class Solution_04 extends JFrame {
	public Solution_04() {
		
		JButton jbt1 = new JButton("Button 1");
		JButton jbt2 = new JButton("Button 2");
		JButton jbt3 = new JButton("Button 3");
		MyPanel jp1 = new MyPanel(jbt1, jbt2, jbt3);
		
		JButton jbt4 = new JButton("Button 4");
		JButton jbt5 = new JButton("Button 5");
		JButton jbt6 = new JButton("Button 6");
		MyPanel jp2 = new MyPanel(jbt4, jbt5, jbt6);
		
		add(jp1, BorderLayout.WEST);
		add(jp2, BorderLayout.EAST);
	}
	
	public static void main(String[] args) {
		JFrame frame = new Solution_04();
				
		frame.setTitle("Exercise12_4");
		frame.setSize(550, 100);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}


class MyPanel extends JPanel {
	public MyPanel(JButton jbt1, JButton jbt2, JButton jbt3) {
		this.add(jbt1);
		this.add(jbt2);
		this.add(jbt3);
	}
}

