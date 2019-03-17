// Chapter 14
// TestCalendar.java
// August 19, 2016


package chapter14;

import java.util.*;

public class TestCalendar {
	public static void main(String[] args) {
		Calendar calendar = new GregorianCalendar();
		
		System.out.println("Current time is " + new Date());
		System.out.println("Year:\t" + calendar.get(Calendar.YEAR));
		System.out.println("Month:\t" + calendar.get(Calendar.MONTH));
		System.out.println("Date:\t" + calendar.get(Calendar.DATE));
		System.out.println("Hour:\t" + calendar.get(Calendar.HOUR));
		System.out.println("Hour_Of_Day:\t" + calendar.get(Calendar.HOUR_OF_DAY));
		System.out.println("Minute:\t" + calendar.get(Calendar.MINUTE));
		System.out.println("Second:\t" + calendar.get(Calendar.SECOND));
		System.out.println("Day_Of_Week:\t" + calendar.get(Calendar.DAY_OF_WEEK));
		System.out.println("Day_Of_Month:\t" + calendar.get(Calendar.DAY_OF_MONTH));
		System.out.println("Day_Of_Year:\t" + calendar.get(Calendar.DAY_OF_YEAR));
		System.out.println("Week_Of_Month:\t" + calendar.get(Calendar.WEEK_OF_MONTH));
		System.out.println("Week_Of_Year:\t" + calendar.get(Calendar.WEEK_OF_YEAR));
		System.out.println("AM_PM:\t" + calendar.get(Calendar.AM_PM));
		
		Calendar calendar2 = new GregorianCalendar(2001, 8, 11);
		
		System.out.println("September 11, 2001 is a " + 
			dayNameOfWeek(calendar2.get(Calendar.DAY_OF_WEEK)));
	}
	
	public static String dayNameOfWeek(int dayOfWeek) {
		switch (dayOfWeek) {
			case 1: return "Sunday";
			case 2: return "Monday";
			case 3: return "Tuesday";
			case 4: return "Wednesday";
			case 5: return "Thursday";
			case 6: return "Friday";
			case 7: return "Saturday";
			default: return null;
		}
	}
}