public class Light {
    private int period;
    private int time;  // Intern klocka: 0, 1, ... period-1, 0, 1 ...
    private int green; // Signalen groon naer time<green 
    /** 
	Decides how long a time period should be and how long of that period the light should be green.
     */
    public Light(int period, int green) {
	this.period = period;
	this.green = green;
    }
    /** 
	Step the time and resets it when the period is over.
     */
    public void    step() { 
	if(this.time < this.period)
	    this.time++;
	else
	    this.time = 0;
       // Stegar fram klocka ett steg
    }
    /** 
	Return true if the light is green.
     */
    public boolean isGreen()   {
	if((this.time < this.green) == true)
	    return true;
	return false;

	// Returnerar true om time<green, annars false
    }
    /** 
	Prints the light.
     */
    public String toString()  {
	if(this.isGreen()){
	    return "GO!";
	}
	return "STAPH!";
    }
	
}

