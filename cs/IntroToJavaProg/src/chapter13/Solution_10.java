/**
 * Chapter 13
 * Solution_10.java
 * 2016.08.15
 */   


package chapter13;


public class Solution_10 {
	public static void main(String[] args) {
		try {
	        int[] list = new int[2000000000];
	    }
	    catch (Error ex) {
	    	ex.printStackTrace();
		    System.out.println("You are running out of memory.");
		}
		      
		System.out.println("GO");
	}
}

