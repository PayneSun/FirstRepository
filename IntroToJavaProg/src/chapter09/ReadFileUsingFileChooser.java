/** 
 * Chapter 9
 * ReadFileUsingFileChooser.java
 * 2017.04.26
 */


package chapter09;
import java.util.Scanner;
import javax.swing.JFileChooser;


public class ReadFileUsingFileChooser {
	public static void main(String[] args) throws Exception {
		JFileChooser fileChooser = new JFileChooser();
		if (fileChooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
			java.io.File file = fileChooser.getSelectedFile();
			
			Scanner input = new Scanner(file);
			
			while (input.hasNext()) {
				System.out.println(input.nextLine());	
			}
			
			input.close();
		}
		else {
			System.out.println("No file selected.");
		}	
	}
}

