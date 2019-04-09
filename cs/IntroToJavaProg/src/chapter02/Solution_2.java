/**
 * Chapter 2
 * Solution_2.java
 * 2017.04.25
 */


package chapter02;
import java.util.Scanner;


public class Solution_2 {
	public static void main(String[] args) {
		final double PI = 3.1415926;
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter the radius and length of a cylinder: ");
		double radius = input.nextDouble();
		double length = input.nextDouble();
		
		double area = (int)(radius * radius * PI * 10000) / 10000.0000;
		double volume = (int)(area * length * 10) / 10.0;
		System.out.print("The area is " + area + 
				         "\nThe volume is " + volume);
	}
}
