/**
 * Chapter 14
 * Solution_01.java
 * 2016.09.06
 */


package chapter14;


public class Solution_01 {
	public static void main(String[] args) {
		GeometricObject circle1 = new Circle(5);
		GeometricObject circle2 = new Circle(8);
		GeometricObject rectangle1 = new Rectangle(1, 2);
		GeometricObject rectangle2 = new Rectangle(3, 2);
		
		System.out.println("The bigger circle between circle1 and circle2 is \n" +
				GeometricObject.max(circle1, circle2));
		System.out.println("The bigger rectangle between rectangle1 and rectangle2 is \n" +
				GeometricObject.max(rectangle1, rectangle2));
	}
}
