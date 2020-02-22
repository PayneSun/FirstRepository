// Chapter 13
// FileNotFoundExceptionDemo.java
// August 12, 2016


package chapter13;

import java.io.*;
import java.util.Scanner;


public class FileNotFoundExceptionDemo {
	public static void main(String[] args) {
		Scanner console = new Scanner(System.in);
		System.out.print("Enter a file name: ");
		String filename = console.nextLine();
		
		try {
			Scanner input = new Scanner(new File(filename));
			System.out.println("File " + filename + " exists.");
		} 
		catch (FileNotFoundException ex) {
			System.out.println("Exception: " + filename + " not found.");
		}
	}
}
