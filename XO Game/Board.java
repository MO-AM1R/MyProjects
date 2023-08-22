public abstract class Board {
    protected char[][] grid ;
    public abstract boolean update_board (Move m, char symbol);
    public abstract boolean is_winner(char symbol);
    public abstract void display_board();
    public abstract boolean is_draw();
}