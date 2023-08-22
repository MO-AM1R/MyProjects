public class BoardX_O extends Board {
    private int n_times ;
    private final int n;
    public BoardX_O(int N) {
        n = N ;
        n_times = 0 ;
        grid = new char[][]{{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}} ;
    }
    public boolean update_board (Move m, char symbol) {
        if ((m.getX() <= 2 && m.getY() <= 2 && m.getX() >= 0 && m.getY() >= 0) && (symbol == 'X' || symbol == 'O') && grid[m.getX()][m.getY()] == '-') {
            grid[m.getX()][m.getY()] = symbol;
            n_times++;
            return true;
        } else {
            return false;
        }

    }
    public boolean is_winner(char symbol)
    {
        if(n_times == 9)
            return false;
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
                return true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == symbol && grid[1][j] == symbol && grid[2][j] == symbol) {
                return true;
            }
        }
        if(grid[0][0] == symbol&& grid[1][1] == symbol && grid[2][2] == symbol)
            return true;
        else return grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol;

    }
    public void display_board()
    {
        System.out.println("+---+---+---+");
        System.out.println("| " + grid[0][0] + " | " + grid[0][1] + " | " + grid[0][2] + " |");
        System.out.println("+---+---+---+");
        System.out.println("| " + grid[1][0] + " | " + grid[1][1] + " | " + grid[1][2] + " |");
        System.out.println("+---+---+---+");
        System.out.println("| " + grid[2][0] + " | " + grid[2][1] + " | " + grid[2][2] + " |");
        System.out.println("+---+---+---+");
    }
    public boolean is_draw()
    {
        return n_times == 9;
    }
}
