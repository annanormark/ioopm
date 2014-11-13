public class Lane {

    public static class OverflowException extends RuntimeException {
        // Undantag som kastas naer det inte gick att laegga 
        // in en ny bil paa vaegen
    }

    private Car[] theLane;
    /** 
	Make a lane and decides the length of it.
     */
    public Lane(int n) {
	this.theLane = new Car[n];
	// Konstruerar ett Lane-objekt med plats för n fordon
    }
    /**
       Step the cars on the lane.
     */
    public void step() {
	for(int i = 0; i < (theLane.length - 1); i++){
	    if(theLane[i] == null){
		theLane[i] = theLane[i+1];
		theLane[i+1] = null;
	    }
	}
	// Stega fram alla fordon (utom det paa plats 0) ett steg 
        // (om det gaar). (Fordonet paa plats 0 tas bort utifraan 
	// mm h a metoden nedan.)
    }
    /**
       Removes and return the car in the first place in the lane.
     */
    public Car getFirst() {
	Car temp = theLane[0];
	theLane[0] = null;
	return temp;
	// Returnera och tag bort bilen som staar först
    }
    /**
       Return the car in the first place in the lane.
     */
    public Car firstCar() {
	return theLane[0];
	// Returnera bilen som staar först utan att ta bort den
    }
    /**
       Returns true if the last place in the lane is free.
     */

    public boolean lastFree() {
	int i = theLane.length - 1;
	if(theLane[i] == null)
	    return true;
	return false;
	// Returnera true om sista platsen ledig, annars false
    }
    /**
       Puts a car in the last place in the lane.
     */
    public void putLast(Car c) throws OverflowException {
	int i = theLane.length -1;
	if(theLane[i] == null)
	    theLane[i] = c;
	else if(theLane[i] != null)
	    System.out.print("MIKKAN SAYS OVERFLOOOOOOOOOWWWWWW!!!!\n");
	// Staell en bil paa sista platsen paa vaegen
	// (om det gaar).
    }

    public String toString() {
	int n = 0;
	String temp = "";
	while(n < (theLane.length)){
	    if(theLane[n] != null){
		temp=(temp +theLane[n].toString());
		n++;
	    }
	    else{
		temp =(temp+ "----");
		n++;
	    }
	}
	return temp;
	    //return "Lane (First car; firstCar="+firstCar()+", The lane: Lane="+Lane()+")";
    }

}

