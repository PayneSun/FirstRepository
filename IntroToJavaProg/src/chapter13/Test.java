package chapter13;

public class Test {
	public static void main(String[] args) {
		
	}
	
	public void m(int value) throws Exception {
		if (value < 40)
			throw new Exception("asdas");
	}
	
	public static boolean isNumeric(String token) {
		try {
			Double.parseDouble(token);
			return true;
		}
		catch (java.lang.NumberFormatException ex) {
			return false;
		}
	}
}
