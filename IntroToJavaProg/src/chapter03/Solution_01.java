/**
 * Chapter 3
 * Solution_01.java
 * 2017.04.25
 */


package chapter03;
import java.util.Scanner;


public class Solution_01 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a, b, c:");
		double a = input.nextDouble();
		double b = input.nextDouble();
		double c = input.nextDouble();
		double delta = b * b - 4 * a * c;
		
		if(delta > 0) {
			System.out.print("The root is " + (-Math.pow(delta, 0.5) - b)/2/a +
							 " and " + (Math.pow(delta, 0.5) - b)/2/a);
		} else if(delta == 0) {
			System.out.print("The root is " + (Math.pow(delta, 0.5) - b)/2/a);
		} else {
			System.out.print("The equation has no real roots");
		}
	}
}
