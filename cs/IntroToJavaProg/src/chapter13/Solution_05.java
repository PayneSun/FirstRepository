/**
 * Chapter 13
 * Solution_05.java
 * 2016.08.16
 */  


package chapter13;


public class Solution_05 {
	public static void main(String[] args) {
		try {
			Triangle tri = new Triangle(1, 1, 2);
		}
		catch (IllegalTriangleException ex) {
			System.out.println(ex + ":\n" + ex.getInfo());
		}
	}
}

class Triangle {
	private double side1;
	private double side2;
	private double side3;
	
	public Triangle(double side1, double side2, double side3)
		throws IllegalTriangleException {
		if (side1 < 0 || side2 < 0 || side3 < 0) {
			throw new IllegalTriangleException("Negative side!!");
		} else if (side1 + side2 <= side3 ||
				   side1 + side3 <= side2 ||	
			       side2 + side3 <= side1) {
			throw new IllegalTriangleException("Invalid side!!");
		} else {
			this.side1 = side1;
			this.side2 = side2;
			this.side3 = side3;
		}
	}
}


class IllegalTriangleException extends Exception {
	private String info;
	
	public IllegalTriangleException(String info) {
		this.info = info;
	}
	
	public String getInfo() {
		return info;
	}
}

