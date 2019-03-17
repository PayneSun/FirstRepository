/**
 * ch05/Solution_05_08.java 
 * 
 * 2017.11.08
 */


package ch05;

public class Solution_05_08 {
	public static void main(String[] args) {
		new Class0508().method1();
	}
}


class Class0508 {
	public void method1() {
		method2();
		this.method2();
	}
	
	public void method2() {
		System.out.println("method1 called!");
	}
}