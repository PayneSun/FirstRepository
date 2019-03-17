package chapter10;
//import java.util.*;

public class Time {
	private long hour;
	private long minute;
	private long second;
	
	public Time() {
		this.second = (System.currentTimeMillis() / 1000) % 60;
	}
	
	public Time(long elapseTime) {
		long tempMinute = elapseTime / 60;
		
		second = elapseTime % 60;
		minute = tempMinute % 60;
		hour = (tempMinute / 60) % 24;		
	}
	
	public Time(long hour, long minute, long second) {
		this.hour = hour;
		this.minute = minute;
		this.second = second;
	}
	
	public long getHour() {
		return hour;
	}
	
	public long getMinute() {
		return minute;
	}
	
	public long getSecond() {
		return second;
	}
	
	public void setTime(long elapseTime) {
		long tempMinute = elapseTime / 60;
		
		second = elapseTime % 60;
		minute = tempMinute % 60;
		hour = (tempMinute / 60) % 24;		
	}
}
