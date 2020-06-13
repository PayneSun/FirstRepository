/**
 * Solution_1120.java
 * 2020.03.27
 */

package Fundamentals;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Solution_1120 {

	public static void main(String[] args) {
		String str;
		int a, b;
		double c = 0.0;

		while (!StdIn.isEmpty()) {
			str = StdIn.readString();
			a = StdIn.readInt();
			b = StdIn.readInt();
			c = 1.0 * a / b;

			StdOut.printf("%s: %d %d %.3f\n", str, a, b, c);
		}
	}
}
