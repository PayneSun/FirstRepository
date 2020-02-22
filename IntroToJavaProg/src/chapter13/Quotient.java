// Chapter 13
// Quotient.java
// August 12, 2016


package chapter13;

import java.util.Scanner;


public class Quotient {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter two integers: ");
		int number1 = input.nextInt();
		int number2 = input.nextInt();
		
		System.out.println(number1 + " / " + number2 +
				" is " + (number1 / number2));
	}
}
