// Chapter 13
// FinallyDemo.java
// August 13, 2016


package chapter13;


public class FinallyDemo {
	public static void main(String[] args) {
		java.io.PrintWriter output = null;
		
		try {
			output = new java.io.PrintWriter("text.txt");
			output.println("Welcome to Java!");
		}
		catch (java.io.IOException ex) {
			ex.printStackTrace();
		}
		finally {
			if (output != null) {
				output.close();
			}
		}
		
		System.out.println("End of program!");
	}
}
