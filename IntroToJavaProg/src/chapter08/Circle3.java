/**
 * Chapter 8
 * Circle3.java
 * 2017.04.26
 */


package chapter08;


public class Circle3 {

	private double radius = 1;
	private static int numberOfObjects = 0;
	
	public Circle3() {
		numberOfObjects++;
	}
	
	public Circle3(double radius) {
		this.radius = radius;
		numberOfObjects++;
	}
	
	public double getRadius() {
		return radius;
	}
	
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public double getArea() {
		return Math.PI * radius * radius;
	}
	
	public static int getNumberOfObjects() {
		return numberOfObjects;
	}

}
