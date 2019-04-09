/**
 * Chapter 2
 * Solution_6.java
 * 2017.04.25
 */


package chapter02;
import java.util.Scanner;


public class Solution_6 {
	public static void main(String[] args) {
		System.out.print("Enter a number between 0 and 1000: ");
		Scanner input = new Scanner(System.in);
		int tempByte = input.nextInt();
		int sumOfDigits = tempByte%10 + tempByte/10%10 + tempByte/100;
		System.out.print("The sum of the digits is " + sumOfDigits);
	}
}
