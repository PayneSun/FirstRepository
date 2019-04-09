/** 
 * Chapter 9
 * Solution_01.java
 * 2017.04.26
 */


package chapter09;
import java.util.Scanner;


public class Solution_01 {
	public static void main(String[] args) {
		System.out.println("Enter a SSN to check: ");
		
		Scanner input = new Scanner(System.in);
		String stringSSN = input.nextLine();
		
		if (stringSSN.length() == 11) {
			String stringDigit = stringSSN.substring(0, 3) 
					 + stringSSN.substring(4, 6) + stringSSN.substring(7, 11);
			if ((stringSSN.charAt(3) == '-') && (stringSSN.charAt(6) == '-')) {
				int isDigit = 0;
				for (int i = 0; i < stringDigit.length(); i++) {
					if (stringDigit.charAt(i) >= '0' && stringDigit.charAt(i) <= '9')
						isDigit++;
				}
				if (isDigit == 9) {
					System.out.println("Valid SSN.");
				}		
			} else {
				System.out.println("Invalid SSN.");
				System.exit(0);
			}			
		} else {
			System.out.println("Invalid SSN.");
			System.exit(0);
		}		
	}
}

