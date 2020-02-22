// Chapter 11
// ExTriangle.java
// August 4, 2016


package chapter11;


public class ExTriangle extends GeometricObject1 {
	private double side1 = 1.0;
	private double side2 = 1.0;
	private double side3 = 1.0;
	
	public ExTriangle() {
	}
	
	public ExTriangle(double side1, double side2, double side3,
			String color, boolean filled) {
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
		setColor(color);
		setFilled(filled);
	}
	
	public double getSide1() {
		return side1;
	}
	
	public double getSide2() {
		return side2;
	}
	
	public double getSide3() {
		return side3;
	}
	
	public double getArea() { 
		return Math.pow(getPerimeter() * 
					(getPerimeter() - side1) *
					(getPerimeter() - side2) *
					(getPerimeter() - side3), 0.5);
	}
	
	public double getPerimeter() {
		return side1 + side2 + side3;
	}
	
	public String toString() {
		return "Triangle: side1 = " + side1 + " side2 = " +
				side2 + " side3 = " + side3;
	}
}
