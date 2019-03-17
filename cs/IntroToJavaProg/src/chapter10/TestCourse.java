package chapter10;

public class TestCourse {
	public static void main(String[] args) {
		Course course1 = new Course("Data Structures");
		Course course2 = new Course("Database Systems");
		
		course1.addStudent("Peter Jones");
		course1.addStudent("Brian Smith");
		course1.addStudent("Anne Kenedy");
		course1.addStudent("Jack Jeason");
		
		course1.dropStudent("Anne Kenedy");
		
		course2.addStudent("Peter Jones");
		course2.addStudent("Steve Smith");
		
		String[] students = course1.getStudents();
		for (int i = 0; i < course1.getNumberOfStudents(); i++) {
			System.out.print(students[i] + ", ");
		}
		
		System.out.print("\nNumber of students in course2: " + course2.getNumberOfStudents());
	}
}
