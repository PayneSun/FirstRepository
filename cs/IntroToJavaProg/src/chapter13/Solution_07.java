/**
 * Chapter 13
 * Solution_07.java
 * 2016.08.15
 */  


package chapter13;


public class Solution_07 {
	public static void main(String[] args) {
		try {
			String test = "100010";
			int result = binaryToDecimal(test);
			System.out.println(test + " in hex is " + result);
		}
		catch (Exception ex) {
			System.out.println(ex);
		}
	}
	
	public static int binaryToDecimal(String binaryString) 
		throws NumberFormatException {
		int result = 0;
		for (int i = 0; i < binaryString.length(); i++) {
			if (binaryString.charAt(i) != '0' &&
				binaryString.charAt(i) != '1') {
				throw new NumberFormatException(""
						+ "String contains non-binary character!");
			} else {
				result = result * 2 + binaryString.charAt(i) - '0';
			}			
		}
		return result;
	}	
}

