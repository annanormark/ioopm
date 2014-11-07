import java.util.*;
public class Simulation {

    public static void main(String [] args) {

	TrafficSystem T = new TrafficSystem();
	for(int i = 0; i < 20; i++){
	    try {
		Thread.sleep(1000);                 
	    } 
	    catch(InterruptedException ex) {
		Thread.currentThread().interrupt();
	    }
	    T.step();
	    T.print();
    }
}
}
