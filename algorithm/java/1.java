import java.util.Scanner;
import java.util.Random;

public class Main {
  public static void main(String[] args){
    System.out.print("i like pizza!\n");
    System.out.print("It's really good!");
    System.out.print("Buy me a pizza\n");

    int age=10;
    System.out.println("am "+age+" year old");
    boolean isRight = true;
    System.out.println(isRight);
    String name1 = "so dawg";
    System.out.println(name1);

    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter ur name: ");
    //String name = scanner.nextLine();

    System.out.print("Enter ur age: ");
    //int age1 = scanner.nextInt(); 
    

    String user;
    //user = scanner.nextLine();
    /*if (user.isEmpty()){
      System.out.print("yes");
    }else{
      System.out.print("no");
    }*/

    //System.out.println("hello "+name);
    //System.out.println("hello "+age);

    Random random = new Random();

    int num;

    num = random.nextInt(1, 300);

    System.out.println(num);
    System.out.println(Math.PI);

    System.out.println(Math.E);
    int a = 10;
    int b = 12;

    double num2;
    num2 = Math.pow(2, 3);
    num2 = Math.abs(5);
    num2 = Math.sqrt(3.0);
    num2 = Math.max(a, b);

    System.out.println(num2);
    scanner.close();
  }
}
