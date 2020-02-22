package chapter10;

public class MyPoint {
	private double x;
	private double y;
	
	public MyPoint() {
		this(0, 0);
	} 
	
	public MyPoint(double newX, double newY) {
		this.x = newX;
		this.y = newY;
	}
	
	public double getX() {
		return x;
	}
	
	public double getY() {
		return y;
	}
	
	public double distance(MyPoint myPoint2) {
		double ptpOfDistance = Math.pow(Math.pow(x - myPoint2.x, 2) 
				+ Math.pow(y - myPoint2.y, 2), 0.5);
		return ptpOfDistance;
	}
	
	public double distance(double newX, double newY) {
		double ptpOfDistance = Math.pow(Math.pow(x - newX, 2) 
				+ Math.pow(y - newY, 2), 0.5);
		return ptpOfDistance;
	}
}
