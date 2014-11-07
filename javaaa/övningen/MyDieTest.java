import java.util.Scanner;
import java.javaaa.Die.;

  public static void main(String [] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Number of sides: ");
      Die d = new Die(sc.nextInt());

      System.out.println("Alea iacta est: " + d.roll());
  } 

