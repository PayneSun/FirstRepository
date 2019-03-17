/**
 * Chapter 8
 * UseGregorianCalendar.java
 * 2017.04.26
 */


package chapter08;
import java.util.*;


public class UseGregorianCalendar {
	public static void main(String[] args) {		
		GregorianCalendar currentDate = new GregorianCalendar();		
		System.out.println("The current date is " + currentDate.get(GregorianCalendar.MONTH)
		                   + " " + currentDate.get(GregorianCalendar.DAY_OF_MONTH) + ", "
				           + currentDate.get(GregorianCalendar.YEAR));
		
		currentDate.setTimeInMillis(1234567898765L);
		System.out.println("The current date is " + currentDate.get(GregorianCalendar.MONTH)
		                   + " " + currentDate.get(GregorianCalendar.DAY_OF_MONTH) + ", "
				           + currentDate.get(GregorianCalendar.YEAR));		
	}	
}

