/**
 * Chapter 12
 * Solution_03.java
 * 2016.08.11
 */


package chapter12;

import java.awt.*;
import javax.swing.*;


public class Solution_03 extends JFrame {
	public Solution_03() {
		setLayout(new GridLayout(2, 3, 10, 10));
		
		JButton jbt1 = new JButton("Button 1");
		JButton jbt2 = new JButton("Button 2");
		JButton jbt3 = new JButton("Button 3");
		JPanel jp1 = new JPanel();
		jp1.add(jbt1);
		jp1.add(jbt2);
		jp1.add(jbt3);
		
		JButton jbt4 = new JButton("Button 4");
		JButton jbt5 = new JButton("Button 5");
		JButton jbt6 = new JButton("Button 6");
		JPanel jp2 = new JPanel();
		jp2.add(jbt4);
		jp2.add(jbt5);
		jp2.add(jbt6);
		
		add(jp1);
		add(jp2);
	}
	
	public static void main(String[] args) {
		JFrame frame = new Solution_03();
		frame.setTitle("Exercise12_3");
		frame.setSize(350, 150);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

