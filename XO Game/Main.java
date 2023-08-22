public class Main {
    public static void main(String[] args) {
        Player[] player = new Player[2];
        BoardX_O board = new BoardX_O(3);
        Game play = new Game(player, board);
        play.play_game();
    }
}