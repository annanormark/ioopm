import java.util.Scanner;
import java.util.Random;
public class TrafficSystem {
    // Definierar de vaegar och signaler som ingaar i det 
    // system som skall studeras.
    // Samlar statistik
    
    // Attribut som beskriver bestaandsdelarna i systemet
    private Lane  r0;
    private Lane  r1;
    private Lane  r2;
    private Light s1;
    private Light s2;
    Scanner ob = new Scanner(System.in);
    int chance; 
    Random rand = new Random();
    private int left = 0;
    private int forward = 0;
    private int carsin = 0;
    private int carsout = 0;
    // Diverse attribut foor simuleringsparametrar (ankomstintensiteter,
    // destinationer...)

    // Diverse attribut foor statistiksamling
    
    private int time = 0;
    /** Prints out the choices for the user and takes in the users input on the right traffic components
     */
    public TrafficSystem() {
	System.out.println("The length of in-lane:");
	this.r0 = new Lane(ob.nextInt());
	System.out.println("The length of the turn-lane and the forward-lane:");
	int temp = ob.nextInt();
	this.r1 = new Lane(temp);
	this.r2 = new Lane(temp);
	System.out.println("The period of the forward light:");
	temp = ob.nextInt();
	this.s1 = new Light(temp, (temp/2));
	System.out.println("The period of the turning light:");
	temp = ob.nextInt();	
	this.s2 = new Light(temp, (temp/2));
	System.out.println("The chance of a car arriving:");
	this.chance = ob.nextInt();
    }

    /** steps the car forward in the array(road) aswell as the lights and the time. It also makes new cars to put in on the array(road) and takes out the old ones at the light. It does everything.
     */
    public void step() {
	int i = rand.nextInt(chance);
	if(s1.isGreen()){
	    if(r1.firstCar() != null){
		r1.getFirst();
		this.carsout++;
	    }
	}
	r1.step();
	if(s2.isGreen()){
	    if(r2.firstCar() != null){
		r2.getFirst();
		this.carsout++;
	    }
	}
	r2.step();
	if(r0.firstCar() != null){
	    if((r0.firstCar().getDest() == 2) && r2.lastFree()){
		r2.putLast(r0.firstCar());
		r0.getFirst();
		this.left++;
	    }
	    else if((r0.firstCar().getDest() == 1) && r1.lastFree()){
		r1.putLast(r0.firstCar());
		r0.getFirst();
		this.forward++;
	    }
	}
	r0.step();
	if(i == 0){
	    Car c = new Car(this.time, (rand.nextInt(2) + 1));
	    r0.putLast(c);
	    this.carsin++;
	}
	s1.step();
	s2.step();
	this.time ++;

	// Stega systemet ett tidssteg m h a komponenternas step-metoder
	// Skapa bilar, laegg in och ta ur paa de olika Lane-kompenenterna
    }

	//   public void printStatistics() {
	// Skriv statistiken samlad saa haer laangt
	//    }
    /**Prints out the simulation of the traffic system which includes lights and road
     */
    public void print() {
	System.out.println("" +s1.toString()+"\t" +r1.toString()+ "" +r0.toString()+ "\n" +s2.toString()+ "\t" +r2.toString()+"/\n\n");
	// Skriv ut en grafisk representation av koosituationen
	// med hjaelp av klassernas toString-metoder
    }

    public int getcarsin(){
	return this.carsin;
    }

    public int getcarsout(){
	return this.carsout;
    }

    public int getleft(){
	return this.left;
    }

    public int getforward(){
	return this.forward;
    }

    /** Prints the statics of the traffic system 
     */

    public void printstat(){
	System.out.print("Number of cars in:" +getcarsin()+ "\nNumber of cars going left:" +getleft()+ "\nNumber of cars driving forward:" +getforward()+ "\nNumber of cars out:" +getcarsout()+ "\n");
    }

}
