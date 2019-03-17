// Chapter 14
// Rational.java
// August 31, 2016


package chapter14;

public class Rational extends Number implements Comparable {
	private long numerator = 0;
	private long denominator = 1;
	
	Rational() {
		this(0, 1);
	}
	
	Rational(long numerator, long denominator) {
		long gcd = gcd(numerator, denominator);
		this.numerator = ((denominator > 0) ? 1 : -1) * numerator / gcd;
		this.denominator = Math.abs(denominator) / gcd;
	}
	
	public long getNumerator() {
		return numerator;
	}
	
	public long getDenominator() {
		return denominator;
	}
	
	public Rational add(Rational secondRational) {
		long n = numerator * secondRational.getDenominator() +
				denominator * secondRational.getNumerator();
		long d = denominator * secondRational.getDenominator();
		
		return new Rational(n, d);
	}
	
	public Rational subtract(Rational secondRational) {
		long n = numerator * secondRational.getDenominator() -
				denominator * secondRational.getNumerator();
		long d = denominator * secondRational.getDenominator();
		
		return new Rational(n, d);
	}
	
	public Rational multiply(Rational secondRational) {
		long n = numerator * secondRational.getNumerator();
		long d = denominator * secondRational.getDenominator();
		
		return new Rational(n, d);
	}
	
	public Rational divide(Rational secondRational) {
		long n = numerator * secondRational.getDenominator();
		long d = denominator * secondRational.getNumerator();
		
		return new Rational(n, d);
	}
	
	public String toString() {
		if (denominator == 1) {
			return numerator + "";
		} else {
			return numerator + "/" + denominator;
		}
	}
	
	private static long gcd(long n, long d) {
		long n1 = Math.abs(n);
		long d1 = Math.abs(d);
		int gcd = 1;
		
		for (int k = 1; k <= n1 && k <= d1; k++) {
			if (n1 % k == 0 && 
				d1 % k == 0) {
				gcd = k;
			}
		}
		
		return gcd;
	}
	
	public boolean equals(Object param1) {
		if ((this.subtract(((Rational)param1))).getNumerator() == 0) {
			return true;
		} else {
			return false;
		}
	}
	
	public int intValue() {
		return (int)doubleValue();
	}
	
	public float floatValue() {
		return (float)doubleValue();
	}
	
	public double doubleValue() {
		return numerator * 1.0 / denominator;
	}
	
	public long longValue() {
		return (long)doubleValue();
	}
	
	public int compareTo(Object obj) {
		if ((this.subtract((Rational)obj)).getNumerator() > 0) {
			return 1;
		} else if ((this.subtract((Rational)obj)).getNumerator() < 0) {
			return -1;
		} else {
			return 0;
		}
	}
}