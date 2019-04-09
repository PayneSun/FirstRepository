/**
 * Chapter 3
 * Solution_21.java
 * 2017.04.25
 */


package chapter03;
import java.util.Scanner;


public class Solution_21 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter year: (e.g., 2008): ");
		int iYear = input.nextInt();
		
		System.out.print("Enter month:1-12: ");
		int iMonth = input.nextInt();
		
		System.out.print("Enter the day of the month:1-31: ");
		int iDay = input.nextInt();
		
		if (iMonth == 1 && iMonth == 2) {
			iMonth += 12;
			iYear -= 1;
		}
		
		int resultInt = (iDay + (int)(26*(iMonth + 1)/10) + iYear%100
							  + (int)(iYear%100/4) + (int)(iYear/100/4) 
							  + 5*iYear/100) % 7;
		
		String result = "";	
		switch (resultInt) {
			case 0: result = "Saturday"; break;
			case 1: result = "Sunday"; break;
			case 2: result = "Monday"; break;
			case 3: result = "Tuesday";	break;
			case 4: result = "Wednesday"; break;
			case 5: result = "Thursday"; break;
			case 6: result = "Friday"; break;
			default: System.out.print("Invalid status!");
				System.exit(0);	
		}		
		System.out.print("Day of the week is " + result);
	}
}
