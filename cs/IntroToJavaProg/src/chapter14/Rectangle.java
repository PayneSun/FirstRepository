// Chapter 14
// Rectangle.java
// August 17, 2016


package chapter14;


public class Rectangle extends GeometricObject {
	private double width; 
	public double height;
	
	public Rectangle() {
	}
	
	public Rectangle(double width, double height) {
		this.width = width;
		this.height = height;
	}
	
	public Rectangle(double width, double height, 
			String color, boolean filled) {
		this.width = width;
		this.height = height;
		setColor(color);
		setFilled(filled);
	}
	
	public double getWidth() {
		return width;
	}
	
	public void setWidth(double width) {
		this.width = width;
	}
	
	public double getHeight() {
		return height;
	}
	
	public void setHeight(double height) {
		this.height = height;
	}
	
	public double getArea() {
		return width * height;
	}
	
	public double getPerimeter() {
		return 2 * (width + height);
	}
	
	public int compareTo(Object obj) {
		if (getArea() > ((Rectangle)obj).getArea()) {
			return 1;
		} else if (getArea() < ((Rectangle)obj).getArea()) {
			return -1;
		} else {
			return 0;
		}
	}
	
	public String toString() { 
		return " width: " + width + "   heigth: " + height;
	}
}