package chapter10;

public class TestMyInteger {
	public static void main(String[] args) {
		int tempInt = 12;
		char[] charArray = {'0', '7', '1', '2', '3'};
		String myString = "00345";
		MyInteger myInteger1 = new MyInteger(5);
		MyInteger myInteger2 = new MyInteger(23);
		
		System.out.println("equals: " + myInteger1.equals(56));
		System.out.println("equals: " + myInteger1.equals(myInteger2));
		System.out.println("getValue: " + myInteger1.getValue());
		System.out.println("isEven: " + myInteger1.isEven());	
		System.out.println("isOdd: " + myInteger1.isOdd());
		System.out.println("isPrime: " + myInteger1.isPrime());
		System.out.println("isPrime: " + myInteger1.isPrime(33));
		System.out.println("isPrime: " + myInteger1.isPrime(myInteger2));
		System.out.println("parseInt: " + myInteger1.parseInt(charArray));
		System.out.println("parseInt: " + myInteger1.parseInt(myString));
	}
}
