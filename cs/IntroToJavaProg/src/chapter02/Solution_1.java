/**
 * Chapter 2
 * Solution_2.java
 * 2017.04.25
 */


package chapter02;
import java.util.Scanner;


public class Solution_1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a degree in Celsuis: ");
		double celsuis = input.nextDouble();
		double fahrenheit = 9.0 / 5 * celsuis + 32;
		System.out.print(celsuis + " Celsuis is " + fahrenheit + " Fahrenheit");
	}
}
