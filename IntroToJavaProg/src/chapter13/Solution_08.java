/**
 * Chapter 13
 * Solution_08.java
 * 2016.08.16
 */  


package chapter13;


public class Solution_08 {
	public static void main(String[] args) {
		try {
			String test = "1axc";
			int result = hexToDecimal(test);
			
			System.out.println(test + " in deciaml is " + result);
		}
		catch (HexFormatException ex) {
			System.out.println(ex + ":\n" + ex.getHexString());
		}		
	}
	
	public static int hexToDecimal(String hexString) 
		throws HexFormatException {
		int result = 0;
		for (int i = 0; i < hexString.length(); i++) {
			char ch = Character.toUpperCase(hexString.charAt(i));
			if (Character.isDigit(ch)) {
				result = result * 16 + ch - '0';
			} else if (ch >= 'A' && ch <= 'F') {
				result = result * 16 + ch - 'A' + 10;
			} else {
				throw new HexFormatException("" +
					"String contains non-hex character!");
			}
		}
		return result;
	}

}


class HexFormatException extends Exception {
	private String hexString;
	
	public HexFormatException(String hexString) {
		this.hexString = hexString;
	}
	
	public String getHexString() {
		return hexString;
	}
}

