public class Light {
    private int period;
    private int time;  // Intern klocka: 0, 1, ... period-1, 0, 1 ...
    private int green; // Signalen groon naer time<green 

    public Light(int period, int green) {
	this.period = period;
	this.green = green;
    }

    public void    step() { 
	if(this.time < this.period)
	    this.time++;
	else
	    this.time = 0;
       // Stegar fram klocka ett steg
    }

    public boolean isGreen()   {
	if((this.time < this.green) == true)
	    return true;
	return false;

	// Returnerar true om time<green, annars false
    }

    public String toString()  {
	if(this.isGreen()){
	    return "[•]";
	}
	return "[o]";
    }
	
}

