// Chapter 12
// MyFrameWithComponents.java
// August 5, 2016


package chapter12;

import javax.swing.*;

public class MyFrameWithComponents {
	public static void main(String[] args) {
		JFrame frame = new JFrame("MyFrameWithComponents");
		JButton jbtOK = new JButton("OK");

		frame.add(jbtOK);
		frame.setSize(500, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);
	}
}
