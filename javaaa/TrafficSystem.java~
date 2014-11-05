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
    // Diverse attribut foor simuleringsparametrar (ankomstintensiteter,
    // destinationer...)

    // Diverse attribut foor statistiksamling
    
    private int time = 0;

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

    //  public readParameters() {
	// Laeser in parametrar foor simuleringen
	// Metoden kan laesa fraan terminalfoonster, dialogrutor
	// eller fraan en parameterfil. Det sista alternativet
	// aer att fooredra vid uttestning av programmet eftersom
	// man inte daa behoover mata in vaerdena vid varje koorning.
        // Standardklassen Properties aer anvaendbar foor detta. 
    //}

    public void step() {
	int i = rand.nextInt(chance);
	if(s1.isGreen()){
	    r1.getFirst();
	}
	r1.step();
	if(s2.isGreen()){
	    r2.getFirst();
	}
	r2.step();
	if(r0.firstCar() != null){
	    if((r0.firstCar().getDest() == 2) && r2.lastFree()){
		r2.putLast(r0.firstCar());
		r0.getFirst();
	    }
	    else if((r0.firstCar().getDest() == 1) && r1.lastFree()){
		r1.putLast(r0.firstCar());
		r0.getFirst();
	    }
	}
	r0.step();
	if(i == 0){
	    Car c = new Car(this.time, (rand.nextInt(2) + 1));
	    r0.putLast(c);
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

    public void print() {
	System.out.println("" +s1.toString()+"\t" +r1.toString()+ "" +r0.toString()+ "\n" +s2.toString()+ "\t" +r2.toString()+"/\n\n");
	// Skriv ut en grafisk representation av koosituationen
	// med hjaelp av klassernas toString-metoder
    }

}
