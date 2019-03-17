/** 
 * Chapter 9
 * WriteData.java
 * 2017.04.26
 */


package chapter09;


public class WriteData {
	public static void main(String[] args) throws Exception {
		java.io.File file = new java.io.File("score.txt");
		if (file.exists()) {
			System.out.println("File already exists.");
			System.exit(0);
		}
		
		java.io.PrintWriter output = new java.io.PrintWriter(file);		
		output.print("John T Smith ");
		output.println(90);
		output.print("Eric K Jones ");
		output.println(85);
		output.close();	
	}
}

