// Chapter 11
// ExPerson.java
// August 4, 2016


package chapter11;


public class ExPerson {
	protected String name;
	protected String address;
	protected String phone;
	protected String email;
	
	public ExPerson() {
	}
	
	public ExPerson(String name, String address, 
					String phone, String email) {
		this.name = name;
		this.address = address;
		this.phone = phone;
		this.email = email;
	}
	
	public String toString() {
		return "ExPerson: " + name;
	}
}

class Student extends ExPerson {
	static enum GRADE {freshman, sophomore, junior, senior};
	GRADE grade;
	
	public Student() {
	}
	
	public Student(GRADE grade) {
		this.grade = grade;
	}
	
	public void setGrade(GRADE grade) {
		this.grade = grade;
	}
	
	public GRADE getGrade() {
		return grade;
	}
	
	public String toString() {
		return "Student: " + name;
	}
}


class Employee extends ExPerson {
	private String office;
	private int salary;
	private MyDate hiredDate;
	
	public Employee() {
	}
	
	public Employee(String office, int salary, MyDate hiredDate) {
		this.office = office;
		this.salary = salary;
		this.hiredDate = hiredDate;
	}
	
	public String getOffice() {
		return office;
	}
	
	public int getSalary() {
		return salary;
	}
	
	public MyDate getHiredDate() {
		return hiredDate;
	}
	
	public String toString() {
		return "Employee: " + name;
	}
}


class MyDate {
	private int year;
	private int month;
	private int day;
	
	public MyDate() {
	}
	
	public MyDate(int year, int month, int day) {
		this.year = year;
		this.month = month;
		this.day = day;
	}
	
	public int getYear() {
		return year;
	}
	
	public void setYear(int year) {
		this.year = year;
	}
	
	public int getMonth() {
		return month;
	}
	
	public void setMonth(int month) {
		this.month = month;
	}
	
	public int getDay() {
		return day;
	}
	
	public void setDay(int day) {
		this.day = day;
	}
}


class Faculty extends Employee {
	private String workTime;
	
	public Faculty() {
	}
	
	public Faculty(String workTime) {
		this.workTime = workTime;
	}
	public String getWorkTime() {
		return workTime;
	}
	
	public void setWorkTime(String workTime) {
		this.workTime = workTime;
	}
	
	public String toString() {
		return "Faculty: " + name;
	}
}


class Staff extends Employee {
	private String title = "Director";
	
	public Staff() {
	}
	
	public Staff(String title) {
		this.title = title;
	}
	
	public String getTitle() {
		return title;
	}
	
	public void setTitle(String title) {
		this.title = title;
	}
	
	public String toString() {
		return "Staff: " + name;
	}
}