/**
 * Chapter 4
 * Solution_01.java
 * 2015.06.29
 */


package chapter04;
import java.util.Scanner;


public class Solution_01 {
	public static void main(String[] args) {		
		Scanner input = new Scanner(System.in);
		System.out.println("Enter an int value, the pragram exits if the input is 0:");
		
		int inputValue = input.nextInt();
		int countPositive = 0;
		int	countNegative = 0;
		int countInputSum = 0;
		int total = 0;
		
		while (inputValue != 0) {
			if (inputValue > 0) countPositive++;
			if (inputValue < 0) countNegative++;
			total += inputValue;
			countInputSum++;
			inputValue = input.nextInt();
		}
		
		System.out.println("The number of positives is " + countPositive);
		System.out.println("The number of negatives is " + countNegative);
		System.out.println("The total is " + total);
		System.out.println("The average is " + (double)total/countInputSum);	
	}	
}
