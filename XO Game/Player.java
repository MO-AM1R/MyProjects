import java.util.Scanner;
public class Player {
    private final String Name ;
    private final char Symbol ;
    public Player(String N, char S){
        Symbol = S ;
        Name = N ;
    }
    public String getName(){
        return Name ;
    }
    public char getSymbol(){
        return Symbol ;
    }
    public Move get_move(){
        Scanner in = new Scanner(System.in);
        System.out.print("Please Enter the coordinate of the your play\n==>") ;
        return new Move(in.nextInt(), in.nextInt());
    }
}