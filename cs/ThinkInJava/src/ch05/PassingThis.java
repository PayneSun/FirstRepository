/**
 * ch05/PassingThis.java
 * 
 * 2017.11.08
 */

package ch05;

public class PassingThis {
	public void main(String[] args) {
		new Person().eat(new Apple());
	}
}


class Person {
	public void eat(Apple apple) {
		Apple peeled = apple.getPeeled();
		System.out.println("Yummy");
	}
}


class Peeler {
	static Apple peel(Apple apple) {
		return apple;
	}
}


class Apple {
	Apple getPeeled() {
		return Peeler.peel(this);
	}
}
