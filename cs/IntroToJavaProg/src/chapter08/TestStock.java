/**
 * Chapter 8
 * TestStock.java
 * 2017.04.26
 */


package chapter08;


public class TestStock {
	public static void main(String[] args) {
		Stock stock = new Stock("Java", "Sun Marcosystems Inc");	
		
		stock.previousClosingPrice = 4.5;
		stock.currentPrice = 4.35;
		System.out.printf("The change of price is %6.2f%%\n", 100 * stock.getChangePercent());		
	}
}
