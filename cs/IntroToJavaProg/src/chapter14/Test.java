// Chapter 14
// Test.java
// September 2, 2016

package chapter14;

public class Test {
	public static void main(String[] args) {
		/**
		java.util.ArrayList list = new java.util.ArrayList();
		list.add("Tokyo");
		java.util.ArrayList list1 = list;
		java.util.ArrayList list2 = (java.util.ArrayList)(list.clone());
		list.add("Peking");
		
		System.out.println(list == list1);
		System.out.println(list == list2);
		System.out.println(list);
		System.out.println(list1);
		System.out.println(list2.get(0));
		System.out.println(list2.size());
		*/
		
		/**
		GeometricObject go1 = new Circle(3);
		GeometricObject go2 = go1.clone();
		*/
		
		/**
		Integer i1 = new Integer("23");
		Integer i2 = new Integer(23);
		Integer i3 = Integer.valueOf("23");
		Integer i4 = Integer.parseInt("23", 8);
		Double d1 = new Double();
		Double d2 = Double.valueOf("23.45");
		int i5 = (Integer.valueOf("23")).intValue();
		double d3 = (Double.valueOf("23.4")).doubleValue();
		int i6 = (Double.valueOf("23.4")).intValue();
		String str = (Double.valueOf("23.4")).toString();
		*/
		
		/**
		Number numberRef = new Integer(0);
		Double doubleRef = (Double)numberRef;
		*/
		
		/**
		Number[] numberArray = new Integer[2];
		numberArray[0] = new Double(1.5);
		*/
		
		/**
		Number x = new Integer(3);
		System.out.println(x.intValue());
		System.out.println((Integer) x.compareTo(new Integer(4)));
		*/
		
		/**
		System.out.println(Integer.parseInt("10"));
		System.out.println(Integer.parseInt("10", 10));
		System.out.println(Integer.parseInt("10", 16));
		System.out.println(Integer.parseInt("11"));
		System.out.println(Integer.parseInt("11", 10));
		System.out.println(Integer.parseInt("11", 16));
		*/
		
		/**
		java.math.BigInteger x = new java.math.BigInteger("3");
		java.math.BigInteger y = new java.math.BigInteger("7");
		java.math.BigInteger z = x.add(y);
		System.out.println(x);
		System.out.println(z);
		*/
	}
}
