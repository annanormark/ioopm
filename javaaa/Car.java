import java.util.Random;
public class Car {

    private int bornTime;
    private int dest; // 1 för rakt fram, 2 för vaenstersvaeng
    Random ran = new Random();

    public Car(int bornTime, int dest){
	this.bornTime = bornTime;
	this.dest = dest;
    }

    public int getDest(){
	return this.dest;
    }

    public int getBornTime(){
	return this.bornTime;
    }
    // konstruktor och get-metoder
   

    public String toString() {
	    return "(O]~";

	//return "Car (Borntime: bornTime="+getBornTime()+", Destination: dest="+getDest()+")";
    }
	
}

