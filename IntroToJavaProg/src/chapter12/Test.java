// Chapter 12
// Test.java
// August 9, 2016


package chapter12;

import java.awt.*;
import javax.swing.*;


public class Test extends JFrame {
	public static void main(String[] args) {
		JFrame frame = new Test();
		frame.setTitle("ButtonIcons");
		frame.setSize(200, 100);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	
	public Test() {
		ImageIcon iicon = new ImageIcon("input/c4.png");
		JButton jbt1 = new JButton(iicon);
		JButton jbt2 = new JButton(iicon);
		
		JPanel p1 = new JPanel();
		p1.add(jbt1);
		
		JPanel p2 = new JPanel();
		p2.add(jbt2);
		
		JPanel p3 = new JPanel();
		p3.add(jbt1);
		
		add(p1, BorderLayout.NORTH);
		add(p2, BorderLayout.SOUTH);
		add(p3, BorderLayout.CENTER);
	}
}
