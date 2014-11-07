import java.util.*;
public class Simulation {

    /**
       Make the trafficsystem and simulation.
     */
    public static void main(String [] args) {
	Scanner ob = new Scanner(System.in);
	System.out.println("Length of simulation");
	int n = ob.nextInt();
	TrafficSystem T = new TrafficSystem();
	for(int i = 0; i < n; i++){
	    try {
		Thread.sleep(350);                 
	    } 
	    catch(InterruptedException ex) {
		Thread.currentThread().interrupt();
	    }
	    T.step();
	    T.print();
	}
	T.printstat();
    }
}
