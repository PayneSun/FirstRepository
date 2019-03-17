/** 
 * Chapter 9
 * Solution_02.java
 * 2017.04.26
 */


package chapter09;
import java.util.Scanner;


public class Solution_02 {
	public static void main(String[] args) {
		System.out.println("Please enter two strings: ");
		Scanner input1 = new Scanner(System.in);
		Scanner input2 = new Scanner(System.in);
		
		System.out.print("First String:");
		String string1 = input1.nextLine();
		System.out.print("Second String:");
		String string2 = input2.nextLine();
		
		if (isSubString(string1, string2)) {
			System.out.println(string2 + " is sub-string of " + string1);
		}
		else {
			System.out.println(string2 + " isn't sub-string of " + string1);
		}		
	}
	
	public static boolean isSubString(String aString, String bString) {		
		boolean isSubString = false;
		
		int index = aString.indexOf(bString.charAt(0));
		if (aString.length() < bString.length()) {
			return isSubString;
		}
		else if(index < 0) {
			return isSubString;
		}
		else {					
			while(index + bString.length() <= aString.length()) {
				isSubString = bString.equals(aString.substring(index, index + bString.length()));					
				if (isSubString) {
					return isSubString;
				}
				else {
					int indexTemp = index + 1;
					index = aString.indexOf(bString.charAt(0), indexTemp);
					if (index < 0) {
						isSubString = false;
						return isSubString;
					}
				}
			}			
		}
		
		return isSubString;
	}
}

