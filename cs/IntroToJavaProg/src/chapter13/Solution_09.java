/**
 * Chapter 13
 * Solution_09.java
 * 2016.08.15
 */   


package chapter13;


public class Solution_09 {
	public static void main(String[] args) {
		try {
			String test = "13010";
			int result = binaryToDecimal(test);
			
			System.out.println(result);
		}
		catch (BinaryFormatException ex) {
			System.out.println(ex + ":\n" + ex.getBinaryString());
		}
	}
	
	public static int binaryToDecimal(String binaryString) 
		throws BinaryFormatException {
		int result = 0;
		for (int i = 0; i < binaryString.length(); i++) {
			if (binaryString.charAt(i) != '0' &&
				binaryString.charAt(i) != '1') {
			throw new BinaryFormatException(""
				+ "String contains non-binary character!");
			} else {
				result = result * 2 + binaryString.charAt(i) - '0';
			}			
		}
		return result;
	}
}


class BinaryFormatException extends Exception {
	private String binaryString;
	
	public BinaryFormatException(String binaryString) {
		this.binaryString = binaryString;
	}
	
	public String getBinaryString() {
		return binaryString;
	}
}

