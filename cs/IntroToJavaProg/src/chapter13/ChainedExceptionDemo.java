// Chapter 13
// ChainedExceptionDemo.java
// August 13, 2016


package chapter13;


public class ChainedExceptionDemo {
	public static void main(String[] args) {
		try {
			method1();
		}
		catch (Exception ex) {
			ex.printStackTrace();
		}
	}
	
	public static void method1() throws Exception {
		try {
			method2();
		}
		catch (Exception ex) {
			throw new Exception("New info from method1", ex);
		}
	}
	
	public static void method2() throws Exception {
		throw new Exception("New info from method2");
	}
}