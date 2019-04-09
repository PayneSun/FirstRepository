// Chapter 14
// TestEdible.java
// August 20, 2016


package chapter14;


public class TestEdible {
	public static void main(String[] args) {
		Object[] obj = {new Tiger(), new Chicken(), new Apple()};
		for (int i = 0; i < obj.length; i++) {
			if(obj[i] instanceof Edible)
				System.out.println(((Edible)(obj[i])).howToEat());
		}
	}
}


class Animal {
}


class Chicken extends Animal implements Edible {
	public String howToEat() {
		return "Chicken: Fry it";
	}
}


class Tiger extends Animal {
}


abstract class Fruit implements Edible {
}


class Apple extends Fruit {
	public String howToEat() {
		return "Apple: Make apple cider";
	}
}


class Orange extends Fruit {
	public String howToEat() {
		return "Orange: Make orange juice";
	}
}