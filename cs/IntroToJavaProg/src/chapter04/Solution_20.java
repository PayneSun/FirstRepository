/**
 * Chapter 4
 * Solution_20.java
 * 2015.06.29
 */


package chapter04;


public class Solution_20 {
	public static void main(String[] args) {		
		// The scale of image want to print.
		final int SUM_OF_LINES = 8;
		String space = " ";
		for (int numberOfLine = 0; numberOfLine < SUM_OF_LINES; numberOfLine++) {
			for (int numberOfSpace = 0; numberOfSpace < 8 - numberOfLine; numberOfSpace++)
				System.out.printf("%4s", space);
			for(int i = 0; i < 2 * numberOfLine + 1; i++) {				
				if (i <= numberOfLine)
					System.out.printf("%4d" ,(int)Math.pow(2, i));
				else
					System.out.printf("%4d" ,(int)Math.pow(2, 14 - i));
			}			
			System.out.print("\n");			
		}
	}
}
