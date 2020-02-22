/**
 * Chapter 12
 * Solution_08.java
 * 2016.08.11
 */


package chapter12;

import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;


public class Solution_08 extends JFrame {
	public Solution_08() {
		Border border = new LineBorder(Color.YELLOW, 1);
		Font font = new Font("TimesRoman", Font.BOLD, 20);
		
		JPanel jp = new JPanel(new GridLayout(2, 3));
		JLabel jl1 = new JLabel("black");
		JLabel jl2 = new JLabel("blue");
		JLabel jl3 = new JLabel("cyan");
		JLabel jl4 = new JLabel("green");
		JLabel jl5 = new JLabel("magenta");
		JLabel jl6 = new JLabel("orange");
			
		jl1.setFont(font);
		jl1.setBorder(border);
		jl1.setForeground(Color.BLACK);
		jl1.setToolTipText("black");
		
		jl2.setFont(font);
		jl2.setBorder(border);
		jl2.setForeground(Color.BLUE);
		jl2.setToolTipText("blue");
		
		jl3.setFont(font);
		jl3.setBorder(border);
		jl3.setForeground(Color.CYAN);
		jl3.setToolTipText("cyan");
		
		jl4.setFont(font);
		jl4.setBorder(border);
		jl4.setForeground(Color.GREEN);
		jl4.setToolTipText("green");
		
		jl5.setFont(font);
		jl5.setBorder(border);
		jl5.setForeground(Color.MAGENTA);
		jl5.setToolTipText("magenta");
		
		jl6.setFont(font);
		jl6.setBorder(border);
		jl6.setForeground(Color.ORANGE);
		jl6.setToolTipText("orange");
		
		jp.add(jl1);
		jp.add(jl2);
		jp.add(jl3);
		jp.add(jl4);
		jp.add(jl5);
		jp.add(jl6);

		add(jp);
	}	
	
	public static void main(String[] args) {
		JFrame frame = new Solution_08();
		frame.setTitle("Exercise12_8");
		frame.setSize(300, 200);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

