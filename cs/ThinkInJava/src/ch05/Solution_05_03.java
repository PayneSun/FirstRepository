/**
 * 2017/09/10 SUN
 * ch05/Solution_05_03.java
 */

package ch05;


public class Solution_05_03 {
	public static void main(String[] args) {
		TestDefaultConstructor tdc = new TestDefaultConstructor();
		TestDefaultConstructor tdcp = new TestDefaultConstructor("java");
		
		Dog dog = new Dog();
		dog.bark();
		dog.bark(5);
		dog.bark("dog");
		dog.bark("dog", 5);
		dog.bark(5, "dog");
		
		NoConstructor nc = new NoConstructor();
		nc.printNoConstructor();
	}
}


class TestDefaultConstructor {
	/*
	 * Solution of exercise 3
	 */
	TestDefaultConstructor() {
		System.out.println("This message is from constructor!");
	}
	
	/*
	 * Solution of exercise 4
	 */
	TestDefaultConstructor(String str) {
		System.out.println("This message is from constructor!: " + str);
	}
}


/*
 * Solution of exercise 5
 */
class Dog {
	void bark() {
		System.out.println("method bark() called!");
	}
	
	void bark(int number) {
		System.out.println("method bark(int) called!");
	}
	
	void bark(String string) {
		System.out.println("method bark(String) called!");
	}

	/*
	 * Solution of exercise 6
	 */
	void bark(int number, String string) {
		System.out.println("method bark(int, String) called!");
	}
	
	/*
	 * Solution of exercise 6
	 */
	void bark(String string, int number) {
		System.out.println("method bark(String, int) called!");
	}
}


/*
 * Solution of exercise 7
 */
class NoConstructor {
	public void printNoConstructor() {
		System.out.println("No constructor class.");
	}
}