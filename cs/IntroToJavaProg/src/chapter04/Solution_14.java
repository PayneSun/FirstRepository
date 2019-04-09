/**
 * Chapter 4
 * Solution_14.java
 * 2015.06.29
 */


package chapter04;


public class Solution_14 {
	public static void main(String[] args) {
		int countLine = 0;
		for (char printChar = 33; printChar < 127; printChar++ ) {
			System.out.print("  " + printChar);
			countLine++;
			if (countLine % 10 == 0) System.out.print("\n");
		}
	}
}
