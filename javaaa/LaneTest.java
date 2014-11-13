package TS;

import static org.junit.Assert.*;

import org.junit.Test;

public class LaneTest {

	@Test
	public void test1() {
		Lane testlane = new Lane(3);
		Car testcar = new Car(2, 2);
		testlane.putLast(testcar);
		assertTrue(testlane.lastFree() == false);
		fail("Not yet implemented");
	}
	
	@Test
	public void test2(){
		Lane testlane = new Lane(2);
		Car testcar1 = new Car(1,2);
		testlane.putLast(testcar1);
		testlane.step();
		assertTrue(testlane.getFirst() == testcar1);
		fail("Nope");
	}
	
	@Test
	public void test3(){
		Lane testlane = new Lane(2);
		Car testcar = new Car(1,2);
		testlane.putLast(testcar);
		testlane.step();
		testlane.getFirst();
		assertTrue(testlane.firstCar() == null);
		fail("noooooo");
	}

}
