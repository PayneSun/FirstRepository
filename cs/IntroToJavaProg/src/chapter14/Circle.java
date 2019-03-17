// Chapter 14
// Circle.java
// August 17, 2016


package chapter14;


public class Circle extends GeometricObject {
	private double radius;
	
	public Circle() {
	}
	
	public Circle(double radius) {
		this.radius = radius;
	}
	
	public Circle(double radius, String color, boolean filled) {
		this.radius = radius;
		setColor(color);
		setFilled(filled);
	}
	
	public double getRadius() {
		return radius;
	}
	
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public double getDiameter() {
		return 2 * radius;
	}
	
	public void printCircle() {
		System.out.println("The circle is created " + getDateCreated() +
				" and the radius is " + radius);
	}
	
	public double getArea() {
		return radius * radius * Math.PI;
	}

	public double getPerimeter() {
		return 2 * radius * Math.PI;
	}
	
	public int compareTo(Object obj) {
		if (getArea() > ((Circle)obj).getArea()) {
			return 1;
		} else if (getArea() < ((Circle)obj).getArea()) {
			return -1;
		} else {
			return 0;
		}
	}

	public String toString() { 
		return " radius: " + radius;
	}
}