// Chapter 14
// HandleEvent.java
// August 22, 2016


package chapter14;

import javax.swing.*;
import java.awt.event.*;


public class HandleEvent extends JFrame {
	public HandleEvent() {
		JButton jbtOK = new JButton("OK");
		JButton jbtCancel = new JButton("Cancel");
		
		JPanel panel = new JPanel();
		panel.add(jbtOK);
		panel.add(jbtCancel);
		
		add(panel);
		
		OKListenerClass okl = new OKListenerClass();
		CancelListenerClass ccl = new CancelListenerClass();
		
		jbtOK.addActionListener(okl);
		jbtCancel.addActionListener(ccl);
	}
	
	public static void main(String[] args) {
		JFrame frame = new HandleEvent();
		frame.setTitle("Handle Event");
		frame.setSize(300, 150);
		frame.setLocation(200, 100);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}


class OKListenerClass implements ActionListener {
	public void actionPerformed(ActionEvent ae) {
		System.out.println("OK button clicked!");
	}
}


class CancelListenerClass implements ActionListener {
	public void actionPerformed(ActionEvent ae) {
		System.out.println("Cancel button clicked!");
	}
}