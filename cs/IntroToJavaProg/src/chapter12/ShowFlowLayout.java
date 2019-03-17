// Chapter 12
// ShowFlowLayout.java
// August 5, 2016


package chapter12;

import java.awt.FlowLayout;
import javax.swing.*;


public class ShowFlowLayout extends JFrame {
	public ShowFlowLayout() {
		setLayout(new FlowLayout(FlowLayout.LEFT, 20, 20));
		
		add(new JLabel("First Name"));
		add(new JTextField(8));
		add(new JLabel("MI"));
		add(new JTextField(1));
		add(new JLabel("Last Name"));
		add(new JTextField(8));
	}
	
	public static void main(String[] args) {
		ShowFlowLayout frame = new ShowFlowLayout();
		frame.setTitle("ShowFlowLayout");
		frame.setSize(500, 200);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
