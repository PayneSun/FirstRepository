/**
 * Solution_1119.java
 * 2020.03.26
 */

package Fundamentals;

public class Solution_1119 {

	public static void main(String[] args) {
		int n = 5;
		System.out.println(func(n));
	}

	public static double func(int n) {
		if (n <= 1) {
			return 0.0;
		}

		return func(n - 1) + Math.log(n - 1);
	}
}
