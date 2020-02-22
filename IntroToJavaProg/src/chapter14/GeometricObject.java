// Chapter 14
// GeometricObject.java
// August 17, 2016


package chapter14;


public abstract class GeometricObject implements Comparable {
	private String color = "white";
	private boolean filled;
	private java.util.Date dateCreated;
	
	protected GeometricObject() {
		dateCreated = new java.util.Date();
	}
	
	protected GeometricObject(String color, boolean filled) {
		dateCreated = new java.util.Date();
		this.color = color;
		this.filled = filled;
	}
	
	public String getColor() {
		return color;
	}
	
	public void setColor(String color) {
		this.color = color;
	}
	
	public boolean isFilled() {
		return filled;
	}
	
	public void setFilled(boolean filled) {
		this.filled = filled;
	}
	
	public java.util.Date getDateCreated() {
		return dateCreated;
	}
	
	public static Comparable max(Comparable obj1, Comparable obj2) {
		if (obj1.compareTo(obj2) > 0) {
			return obj1;
		} else {
			return obj2;
		}
	}
	
	public abstract double getArea();
	
	public abstract double getPerimeter();
	
	public abstract String toString();
}

