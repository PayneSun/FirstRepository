/**
 * Chapter 8
 * Stock.java
 * 2017.04.26
 */


package chapter08;


public class Stock {
	String symbol;
	String name;
	double previousClosingPrice;
	double currentPrice;
	
	public Stock(String specifiedSymbol, String specifiedName) {
		symbol = specifiedSymbol;
		name = specifiedName;	
	}
	
	public double getChangePercent() {
		return (currentPrice - previousClosingPrice) / previousClosingPrice;
	}	
}
