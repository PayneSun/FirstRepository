// Chapter 14
// TestGeometricObject.java
// August 17, 2016


package chapter14;


public class TestGeometricObject {
	public static void main(String[] args) {
		GeometricObject go1 = new Circle(5);
		GeometricObject go2 = new Rectangle(5, 3);
		
		System.out.println("The two objects have the sanme area? " +
			equalArea(go1, go2));
		
		displayGeometricObject(go1);
		displayGeometricObject(go2);
	}
	
	public static boolean equalArea(GeometricObject go1, 
		GeometricObject go2) {
		return go1.getArea() == go2.getArea();
	}
	
	public static void displayGeometricObject(GeometricObject go1) {
		System.out.println("\n" + "The area is " + go1.getArea());
		System.out.println("The perimeter is " + go1.getPerimeter());
	}
}
