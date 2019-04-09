package chapter10;

public class TestMyPoint {
	public static void main(String[] args) {
		MyPoint point1 = new MyPoint(0, 0);
		MyPoint point2 = new MyPoint(10, 30.5);
		
		System.out.println("The distance between point(" + point1.getX() + ", " + point1.getY() + 
				") and " + "point(" + point2.getX() + ", " + point2.getY() + ") is " + point1.distance(point2));				
	}
}
