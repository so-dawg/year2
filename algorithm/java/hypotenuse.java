import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter length A: ");
    double num = scanner.nextDouble();
    
    System.out.print("Enter length B: ");
    double num2 = scanner.nextDouble();

    double c = Math.sqrt(Math.pow(num, 2) + Math.pow(num2, 2));
    System.out.println("The result is "+c);
    scanner.close();
  }
}
