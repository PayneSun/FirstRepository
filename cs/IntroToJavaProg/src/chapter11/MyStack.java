// Chapter 11
// MyStack.java
// August 3, 2016

package chapter11;

public class MyStack {
	private java.util.ArrayList list = new java.util.ArrayList();
	
	public boolean isEmpty() {
		return list.isEmpty();
	}
	
	public int getSize() {
		return list.size();
	}
	
	public Object peek() {
		return list.get(getSize() - 1);
	}
	
	public Object pop() {
		Object obj = peek();
		list.remove(getSize() - 1);
		return obj;
	}
	
	public void push(Object obj) {
		list.add(obj);
	}
	
	public String toString() {
		return "stack: " + list.toString();
	}
}
