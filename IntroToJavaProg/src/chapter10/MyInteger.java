package chapter10;

public class MyInteger {
	private int value;
	
	public MyInteger(int newValue) {
		value = newValue;
	}
	
	public int getValue() {
		return value;
	}
	
	public boolean isEven() {
		return (value % 2) == 0;
	}
	
	public boolean isOdd() {
		return (value % 2) == 1;
	}
	
	public boolean isPrime() {
		for (int i = 2; i < Math.abs(value); i++) {
			if (Math.abs(value) / i == 0) {
				return true;
			}
		}
		return false;
	}
	
	public boolean isPrime(int newValue) {
		for (int i = 2; i < Math.abs(newValue); i++) {
			if (Math.abs(value) / i == 0) {
				return true;
			}
		}
		return false;
	}	

	public boolean isPrime(MyInteger myInteger) {
		for (int i = 2; i < Math.abs(myInteger.value); i++) {
			if (Math.abs(myInteger.value) / i == 0) {
				return true;
			}
		}
		return false;
	}
	
	public boolean equals(int newValue) {
		return value == newValue;
	}
	
	public boolean equals(MyInteger myInteger) {
		return value == myInteger.value;
	}

	public static int parseInt(char[] charArray) {
		int tempInt = 0;
		for (int i = 0; i < charArray.length; i++) {
			tempInt = tempInt * 10 + charArray[i] - '0';
		}
		
		return tempInt;
	}
	
	public static int parseInt(String myString) {
		int tempInt = 0;
		for (int i = 0; i < myString.length(); i++) {
			tempInt = tempInt * 10 + myString.charAt(i) - '0';
		}
		
		return tempInt;
	}	
}
