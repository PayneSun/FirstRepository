/**
 * Chapter 5
 * Solution_0.java
 * 2015.07.06
 */


package chapter05;
import java.util.Scanner;


public class Solution_0 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);		
		
		System.out.print("Enter full year (e.g., 2001): ");
		int year = input.nextInt();		
		
		System.out.print("Enter month in number between 1 and 12: ");		
		int month = input.nextInt();
		
		printCalender(year, month);		
	}

	//-- Function: printCalender
	public static void printCalender(int year, int month) {		
		printMonthTitle(year, month);		
		printMonthBody(year, month);		
	}
	
	//-- Function: printMonthTitle
	public static void printMonthTitle(int year, int month) {
		System.out.println("        " + getMonthName(month) + " " + year + "        ");
		System.out.println("----------------------------");
		System.out.println(" Sun Mon Tue Wed Thu Fri Sat");
	}
	
	//-- Function printMonthBody
	public static void printMonthBody(int year, int month) {
		String space = " ";
		
		for(int j = 0; j < getStartDay(year, month); j++)
			System.out.printf("%4s", space);
		
		for(int i = 1; i <= getNumberOfDaysInMonth(year, month); i++) {
			if ((i + getStartDay(year, month)) % 7 != 0)
				System.out.printf("%4d", i);
			else {
				System.out.printf("%4d", i);
				System.out.print("\n");
			}				
		}
	}
	
	//-- Function getTotalNumberOfDays
	public static int getTotalNumberOfDays(int year, int month) {
		int total = 0;
		
		for(int i = 1800; i < year; i++)
				total += isLeapYear(i) ? 366 : 365;
		
		for(int j = 1; j < month; j++)
			total += getNumberOfDaysInMonth(year, j);
		
		return total;
	}
	
	//-- Function getStartDay
	public static int getStartDay(int year, int month) {
		final int START_DAY_FOR_JAN_1_1800 = 3;
		
		int totalNumberOfDays = getTotalNumberOfDays(year, month);
		
		return (totalNumberOfDays + START_DAY_FOR_JAN_1_1800) % 7;		
	}
		
	//-- Function getMonthName
	public static String getMonthName(int month) {
		String nameOfMonth = "";
		switch (month) {
			case 1:  nameOfMonth = "January"; break;
			case 2:  nameOfMonth = "February"; break;
			case 3:  nameOfMonth = "March"; break;
			case 4:  nameOfMonth = "April"; break;
			case 5:  nameOfMonth = "May"; break;
			case 6:  nameOfMonth = "June"; break;
			case 7:  nameOfMonth = "July"; break;
			case 8:  nameOfMonth = "August"; break;
			case 9:  nameOfMonth = "September"; break;
			case 10: nameOfMonth = "October"; break;
			case 11: nameOfMonth = "November"; break;
			case 12: nameOfMonth = "December"; break;					
		}
		return nameOfMonth;
	}
	
	//-- Function getNumberOfDaysInMonth
	public static int getNumberOfDaysInMonth(int year, int month) {
		if (month == 2)
			return isLeapYear(year) ? 29 : 28;
		else if (month == 4 || month == 6 || month == 9 || month == 11)
			return 30;			
		else
			return 31;	
	}
	
	//-- Function isLeapYear
	public static boolean isLeapYear(int year) {
		return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));		
	}	
}
