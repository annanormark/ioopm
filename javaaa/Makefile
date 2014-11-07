
JC = javac

.SUFFIXES: .java .class

.java.class:
	$(JC) $*.java

CLASSES = \
	Car.java \
	Lane.java \
	Light.java \
	Simulation.java \
	TrafficSystem.java 

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class

test: 
	javac -cp /usr/share/java/junit4.jar CarTest.java Car.java LaneTest.java Lane.java LightTest.java Light.java TrafficSystemTest.java TrafficSystem.java JunitTestSuite.java

testrun:
	java -cp /usr/share/java/junit4.jar:. org.junit.runner.JUnitCore JunitTestSuite