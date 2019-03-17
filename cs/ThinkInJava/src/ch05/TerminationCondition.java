/**
 * ch05/TerminationCondition.java
 * 
 * 2017.11.08
 */


package ch05;

public class TerminationCondition {
	public static void main(String[] args) {
		Book novel = new Book(true);
		novel.checkIn();
		
		new Book(true);
		System.gc();
	}
}


class Book {
	boolean checkedOut = false;
	
	Book(boolean checkOut) {
		checkedOut = checkOut;
	}
	
	void checkIn() {
		checkedOut = false;
	}
	
	protected void finalize() {
		if(checkedOut) {
			System.out.println("Error: checked out");
		}
	}
}