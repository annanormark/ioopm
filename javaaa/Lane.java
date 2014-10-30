public class Lane {

    public static class OverflowException extends RuntimeException {
        // Undantag som kastas när det inte gick att lägga 
        // in en ny bil på vägen
    }

    private Car[] theLane;

    public Lane(int n) {
	this.theLane = new Car[n];
	// Konstruerar ett Lane-objekt med plats för n fordon
    }

    public void step() {
	for(int i = 0; i < (theLane.length - 1); i++){
	    if(theLane[i] == null){
		theLane[i] = TheLane[i+1];
		theLane[i+1] = null;
	    }
	}
	// Stega fram alla fordon (utom det på plats 0) ett steg 
        // (om det går). (Fordonet på plats 0 tas bort utifrån 
	// mm h a metoden nedan.)
    }

    public Car getFirst() {
	car temp = theLane[0];
	theLane[0] = null;
	return temp;
	// Returnera och tag bort bilen som står först
    }

    public Car firstCar() {
	return theLane[0];
	// Returnera bilen som står först utan att ta bort den
    }


    public boolean lastFree() {
	int i = theLane.length;
	if(theLane[i] == null)
	    return true;
	return false;
	// Returnera true om sista platsen ledig, annars false
    }

    public void putLast(Car c) throws OverflowException {
	int i = theLane.length;
	if(theLane[i] == null)
	    theLane[i] = c;
	// Ställ en bil på sista platsen på vägen
	// (om det går).
    }

    public String toString() {
	return "Lane (First car; firstCar="+firstCar()+", The lane: Lane="+Lane()+")";
    }

}
