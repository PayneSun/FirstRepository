/**
 * Chapter 8
 * UseRandom.java
 * 2017.04.26
 */


package chapter08;
import java.util.*;


public class UseRandom {
	public static void main(String[] args) {	
		Random random = new Random(1000);
		
		for (int i = 0; i < 50; i++) {
			System.out.print(random.nextInt(100) % 50 + " ");
			if ((i + 1) % 10 == 0) {
				System.out.print("\n");
			}
		}
	}
}
