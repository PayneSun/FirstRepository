/**
 * Chapter 14
 * Solution_02.java
 * 2016.09.08
 */


package chapter14;

public class Solution_02 {
	public static void main(String[] args) {
		ComparableCircle cc1 = new ComparableCircle(15);
		ComparableCircle cc2 = new ComparableCircle(10);
		
		System.out.print("The bigger circle's information:");
		if (cc1.compareTo(cc2) >= 0) {
			System.out.println(cc1);
		} else {
			System.out.println(cc2);
		}
	}
}


class ComparableCircle extends Circle 
	implements Comparable {
	public ComparableCircle(double radius) {
		super(radius);
	}
	
	public int compareTo(Circle obj) {
		if (this.getArea() > obj.getArea()) {
			return 1;
		} else if (this.getArea() == obj.getArea()) {
			return 0;
		} else {
			return -1;
		}
	}
}

