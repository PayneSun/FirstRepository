// Chapter 12
// TestImageIcon.java
// August 7, 2016


package chapter12;

import java.awt.*;
import javax.swing.*;


public class TestImageIcon extends JFrame {
	private ImageIcon cnIcon = new ImageIcon("input/c4.png");
	private ImageIcon jpIcon = new ImageIcon("input/c5.png");
	private ImageIcon krIcon = new ImageIcon("input/c6.png");
	
	public TestImageIcon() {
		setLayout(new GridLayout(1, 3, 10, 10));
		add(new JLabel(cnIcon));
		add(new JLabel(jpIcon));
		add(new JLabel(krIcon));
	}
	
	public static void main(String[] args) {
		TestImageIcon frame = new TestImageIcon();
		frame.setTitle("TestImageIcon");
		frame.setSize(1200, 600);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
