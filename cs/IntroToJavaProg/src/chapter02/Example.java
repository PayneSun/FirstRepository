// Chapter 2
// WriteData.java


package chapter02;
import javax.swing.JOptionPane;

public class Example {

	public static void main(String[] args) {
/*		Scanner input = new Scanner(System.in);
		System.out.print("Enter yearly interest rate, for example 8.35: ");
		double annualInterestRate = input.nextDouble();
		double monthlyInterestRate = annualInterestRate / 1200;
		System.out.print("Enter number of years as an integer, for example 5: ");
		int numberOfYears = input.nextInt();
		System.out.print("Enter loan mount, for example 120000.00: ");
		double loanAmount = input.nextDouble();
		double monthlyPayment = loanAmount * monthlyInterestRate / 
				(1 - 1 / Math.pow(1 + monthlyInterestRate, numberOfYears * 12));
		double totalPayment = monthlyPayment * numberOfYears * 12;
		System.out.println("The monthly payment is " + 
		                 (int)(monthlyPayment * 100) / 100.0);
		System.out.println("The total payment is " + 
                         (int)(totalPayment * 100) / 100.0);  
*/
		char x = 'a';
		System.out.print(++x);
	}
}
