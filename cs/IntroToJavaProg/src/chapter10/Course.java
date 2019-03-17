package chapter10;

public class Course {
	private String courseName;
	private String[] students = new String[100];
	private int numberOfStudents;
	
	public Course(String courseName) {
		this.courseName = courseName;
	}
	
	public String getCourseName() {
		return courseName;
	}
	
	public void addStudent(String student) {
		students[numberOfStudents] = student;
		numberOfStudents++;
	}
	
	public void dropStudent(String student) {
		int index = 0;
		for (int i = 0; i < numberOfStudents; i++) {
			if (students[i] == student) {
				index = i;
				break;
			}
		}
		
		for (int j = index; j < numberOfStudents - 1; j++) {
			students[j] = students[j + 1];
		}
	}
	
	public String[] getStudents() {
		String[] students = this.students;
		return students;
	}

	public int getNumberOfStudents() {
		return numberOfStudents;
	}
}
