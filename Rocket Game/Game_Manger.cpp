# include "A_M_Game.h"

Game_Manger::Game_Manger(int n){
    Board.Set(n) ;
}

void Game_Manger::run() {

    int Option;
    cout << "What you want\n1 - Player vs Player\n2 - Player vs Computer\n===>";
    cin >> Option;

    if (Option == 1) {
        Player players[2] = {Player("Player 1", '>'), Player("Player 2", 'v')};
        string Name;
        for (int i = 0; i < 2; ++i) {
            cout << "Player " << i + 1 << " / Enter Your Name\n->";
            cin >> Name;
            players[i].Set_Name(Name);
        }

        players[0].Information();
        players[1].Information();

        Board.Display();

        while (true) {
            for (int i: {1, 2}) {
                cout << "===================\n";
                int row, col;

                if (!Board.If_Exist_Moves(players[i - 1].Get_Side())){
                    cout << "There isn't Moves :(\n" ;
                    Board.Display() ;
                    continue ;
                }

                players[i - 1].Get_Move(row, col);
                while (!Board.If_Valid_Move(row, col, players[i - 1].Get_Side())) {
                    cout << "Wrong Coordinate :(\n";
                    players[i - 1].Get_Move(row, col);
                }
                Board.Update(row, col, players[i - 1].Get_Side()) ;
                Board.Display();

                if (Board.isWinner() == 1) {
                    cout << "===================\n";
                    cout << players[0].Get_Name() << " Won :)\n";
                    return;
                }
                else if (Board.isWinner() == -1) {
                    cout << "===================\n";
                    cout << players[1].Get_Name() << " Won :)\n";
                    return;
                }
            }
        }
    }
    else {
        Player player_1("Player 1", '>') ;
        ComputerPlayer Comp ;

        string Name;
        cout << "Player " << 1 << " / Enter Your Name\n->";
        cin >> Name;
        player_1.Set_Name(Name);

        player_1.Information();
        Comp.Information();

        Board.Display();

        while (true) {
            for (int i: {1, 2}) {
                if (i == 1) {
                    cout << "===================\n";
                    int row, col;

                    if (!Board.If_Exist_Moves(player_1.Get_Side())){
                        cout << "There isn't Moves :(\n" ;
                        continue ;
                    }

                    player_1.Get_Move(row, col);
                    while (!Board.If_Valid_Move(row, col, player_1.Get_Side())) {
                        cout << "Wrong Coordinate :(\n";
                        player_1.Get_Move(row, col);
                    }
                    Board.Update(row, col, player_1.Get_Side()) ;

                    Board.Display();
                    if (Board.isWinner() == -1) {
                        cout << "===================\n";
                        cout << player_1.Get_Name() << " Won :)\n";
                        return ;
                    }
                }
                else {
                    cout << "===================\n";
                    if (Board.Get_Number() > 5) {
                        Comp.Get_The_best(Board, 10, true, true);
                    }
                    else{
                        Comp.Get_The_best(Board, 100, true, true);
                    }
                    Board.Display() ;

                    if (Board.isWinner() == 1) {
                        cout << "===================\n";
                        cout << Comp.Get_Name() << " Won :)\n";
                        return ;
                    }
                }
            }
        }
    }
}