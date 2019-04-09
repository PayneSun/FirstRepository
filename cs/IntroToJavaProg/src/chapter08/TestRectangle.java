/**
 * Chapter 8
 * TestRectangle.java
 * 2017.04.26
 */


package chapter08;


public class TestRectangle {
	public static void main(String[] args) {
		Rectangle rectangle1 = new Rectangle(4, 40);
		Rectangle rectangle2 = new Rectangle(3.5, 35.9);
		
		System.out.println("rectangle1: " + "width is " + rectangle1.width 
						   + " length is " + rectangle1.length + " area is "
				           + rectangle1.getArea() + " perimeter is " + rectangle1.getPerimeter());
		System.out.println("rectangle2: " + "width is " + rectangle2.width
				           + " length is " + rectangle2.length + " area is "
				           + rectangle2.getArea() + " perimeter is " + rectangle2.getPerimeter());
	}
}
