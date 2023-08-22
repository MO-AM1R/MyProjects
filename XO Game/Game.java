import java.util.Scanner;
public class Game {
    private final BoardX_O board;
    private final Player[] players;

    public Game(Player[] players, BoardX_O board) {
        this.players = players;
        this.board = board;
    }
    public void play_game() {
        String p1_name, p2_name ;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the Name of the First Player\n==>");
        p1_name = in.nextLine();
        players[0] = new Player(p1_name, 'X');
        System.out.print("Enter the Name of the second Player\n==>");
        p2_name = in.nextLine();
        players[1] = new Player(p2_name, 'O');
        board.display_board();
        while (true) {
            Move m1 ;
            for (int i = 0; i < 2; i++) {
                m1 = players[i].get_move();

                while(!board.update_board(m1, players[i].getSymbol())) {
                    System.out.println("Invalid Coordinate :(");
                    m1 = players[i].get_move();
                }
                board.display_board();
                if(board.is_winner(players[i].getSymbol())) {
                    System.out.print("\n" + players[i].getName()+ " wins the game!\nCongratulation !");
                    return;
                }
                if(board.is_draw()) {
                    System.out.println("\nThe Game is draw");
                    return;
                }
            }
        }
    }
}