// Chapter 13
// InvalidRadiusException.java
// August 13, 2016


package chapter13;


public class InvalidRadiusException extends Exception {
	private double radius;
	
	public InvalidRadiusException(double radius) {
		super("Invalid radius " + radius);
		this.radius = radius;
	}
	
	public double getRadius() {
		return radius;
	}
}