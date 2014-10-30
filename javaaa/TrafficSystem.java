public class TrafficSystem {
    // Definierar de vägar och signaler som ingår i det 
    // system som skall studeras.
    // Samlar statistik
    
    // Attribut som beskriver beståndsdelarna i systemet
    private Lane  r0;
    private Lane  r1;
    private Lane  r2;
    private Light s1;
    private Light s2;

    // Diverse attribut för simuleringsparametrar (ankomstintensiteter,
    // destinationer...)

    // Diverse attribut för statistiksamling
    ....    
    
    private int time = 0;

    public TrafficSystem() {
	this.s1 = new Light(6, 3);
	this.s2 = new Light(6, 2);
	this.r0 = new Lane(4);
	this.r1 = new Lane(2);
	this.r2 = new Lane(2);
    }

    public readParameters() {
	// Läser in parametrar för simuleringen
	// Metoden kan läsa från terminalfönster, dialogrutor
	// eller från en parameterfil. Det sista alternativet
	// är att föredra vid uttestning av programmet eftersom
	// man inte då behöver mata in värdena vid varje körning.
        // Standardklassen Properties är användbar för detta. 
    }

    public void step() {
	Car c1 = new Car(0, 1);
	Car c2 = new Car(2, 2);
	Car c3 = new Car(3, 1);
	if(s1.isGreen()){
	    r1.getFirst();
	    r1.step();
	}
	if(s2.isGreen){
	    r2.getFirst();
	    r2.step();
	}
	if((r0.firstCar().getDest() == 2) && r2.lastFree()){
	    r2.putLast(r0.firstCar());
	    r0.getFirst();
	    r0.step();
	}
	else if((r0.firstCar().getDest() == 1) && r1.lastFree()){
	    r1.putLast(r0.firstCar());
	    r0.getFirst();
	    r0.step();
	}
	r0.step();
	r1.step();
	r2.step();
	s1.step();
	s2.step();

	// Stega systemet ett tidssteg m h a komponenternas step-metoder
	// Skapa bilar, lägg in och ta ur på de olika Lane-kompenenterna
    }

    public void printStatistics() {
	// Skriv statistiken samlad så här långt
    }

    public void print() {
	// Skriv ut en grafisk representation av kösituationen
	// med hjälp av klassernas toString-metoder
    }

}
