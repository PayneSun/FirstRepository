/**
 * 2017/09/10 SUN
 * ch02/Solution_02_01.java
 */

package ch02;


public class Solution_02_01 {
	public static void main(String[] args) {
		Test test = new Test();
		System.out.print("default value of int: ");
		System.out.println(test.mInt);
		System.out.print("default value of char: ");
		System.out.println(test.mChar);
	}
}


class Test {
	int mInt;
	char mChar;
}
