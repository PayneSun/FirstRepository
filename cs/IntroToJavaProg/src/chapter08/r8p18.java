/**
 * Chapter 8
 * r8p18.java
 * 2017.04.26
 */


package chapter08;


public class r8p18 {
	public static void main(String[] args) {
		int[] a = {1, 2};
		swap(a[0], a[1]);
		System.out.println("a[0] = " + a[0]
				+ " a[1] = " + a[1]);
	}
	
	public static void swap(int x, int y) {
		int temp = x;
		x = y;
		y = temp;
	}
}
