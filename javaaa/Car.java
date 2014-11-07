import java.util.Random;
public class Car {

    private int bornTime;
    private int dest; // 1 för rakt fram, 2 för vaenstersvaeng
    Random ran = new Random();

    /** sets the start time and destination of the car by randomizing the path. 1 for straight ahead, 2 for turning left
     */
    public Car(int bornTime, int dest){
	this.bornTime = bornTime;
	this.dest = dest;
    }
    /** shows the destination of the car
     */
    public int getDest(){
	return this.dest;
    }
    /** returns the born time of the car
     */
    public int getBornTime(){
	return this.bornTime;
    }
    // konstruktor och get-metoder
   
    /** shows a car on the screen
     */
    public String toString() {
	    return "(O]~";

	//return "Car (Borntime: bornTime="+getBornTime()+", Destination: dest="+getDest()+")";
    }
	
}

