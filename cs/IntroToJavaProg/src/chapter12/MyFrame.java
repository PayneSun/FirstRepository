// Chapter 12
// MyFrame.java
// August 5, 2016


package chapter12;

import javax.swing.*;


public class MyFrame {
	public static void main(String[] args) {
		JFrame frame = new JFrame("MyFrame");
		frame.setSize(400, 300);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
