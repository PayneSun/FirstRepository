/**
 * Chapter 8
 * UseDate.java
 * 2017.04.26
 */


package chapter08;
import java.util.*;


public class UseDate {
	public static void main(String[] args) {		
		Date date = new Date();
		long elapseTime = 10000;
		
		for (int i = 0; i < 8; i++) {
			date.setTime(elapseTime);
			System.out.println("The current time when elapse time is set for "
							   + elapseTime + " is " + date.toString());
			elapseTime *= 10;
		}
	}
}

