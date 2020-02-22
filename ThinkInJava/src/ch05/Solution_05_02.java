/**
 * 2017/09/10 SUN
 * ch05/Solution_05_02.java
 */

package ch05;


public class Solution_05_02 {
	public static void main(String[] args) {
		TestStr1 test1 = new TestStr1();
		System.out.println(test1.str);
		
		TestStr2 test2 = new TestStr2("default-string");
		System.out.println(test2.str);
	}
}


class TestStr1 {
	String str = "default-string";
}


class TestStr2 {
	TestStr2(String str) {
		this.str = str;
	}
	
	String str = "default-string";
}
