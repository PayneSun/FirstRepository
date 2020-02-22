/**
 * Chapter 12
 * Solution_10.java
 * 2016.08.11
 */


package chapter12;

import java.awt.*;
import javax.swing.*;


public class Solution_10 extends JFrame {
	public Solution_10(int dim) {	
		JPanel jp = new JPanel(new GridLayout(dim, dim));
		
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				JButton jbt = new JButton();
				if ((i % 2 == 1 && j % 2 == 0) ||
				    (i % 2 == 0 && j % 2 == 1)) {
					jbt.setBackground(Color.BLACK);
				}
				jp.add(jbt);
			}
		}
		add(jp);
	}
	
	public static void main(String[] args) {
		int dim = 10;
		JFrame frame = new Solution_10(dim);
		frame.setTitle("Solution_10");
		frame.setSize(50 * dim, 50 * dim);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

