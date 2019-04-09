/**
 * Chapter 3
 * Solution_04.java
 * 2017.04.25
 */


package chapter03;
import java.util.Scanner;


public class Solution_04 {
	public static void main(String[] args) {
		int a = (int)(Math.random() * 100);
		int b = (int)(Math.random() * 100);
		int randomSum = a + b;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter an integer :");
		double inputSum = input.nextInt();
		
		if (inputSum == randomSum) {
			System.out.print("Right!");
		} else {
			System.out.print("Wrong!");	
		}
	}
}
