package TS;

import static org.junit.Assert.*;

import org.junit.Test;

public class CarTest {

	@Test
	public void test1() {
		Car test = new Car(1, 1); 
		assertTrue(test.getBornTime() == 1);
		fail("Not yet implemented");
	}
	
	@Test
	public void test2(){
		Car test = new Car(2, 2);
		assertTrue(test.getDest() == 2);
	}

}
