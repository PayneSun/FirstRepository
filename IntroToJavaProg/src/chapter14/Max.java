// Chapter 14
// Max.java
// August 22, 2016


package chapter14;

public class Max {
	public static Comparable max(Comparable co1, Comparable co2) {
		if (co1.compareTo(co2) > 0) {
			return co1;
		} else {
			return co2;
		}
	}
}