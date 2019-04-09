/**
 * Chapter 8
 * Rectangle.java
 * 2017.04.26
 */


package chapter08;


public class Rectangle {
	
	double width;
	double length;
	
	public Rectangle() {
		width = 1;
		length = 1;
	}
	
	public Rectangle(double newWidth, double newLength) {
		width = newWidth;
		length = newLength;
	}
	
	public double getArea() {
		return  width * length;
	}
	
	public double getPerimeter() {
		return 2 * (width + length);
	}
}
