# include "A_M_Game.h"

ComputerPlayer::ComputerPlayer() {
    Name = "Computer_Player" ;
    Side = 'v' ;
}

char ComputerPlayer::Get_Side() const {
    return Player::Get_Side();
}

int ComputerPlayer::Get_The_best(board & Board, int depth, bool IsComputer, bool First = true){
    int Result = Board.isWinner() ;

    if (Result != 0 || depth == 0){
        return Result ;
    }
    if (IsComputer){
        int Temp = -100 ;
        int Row, Column ;
        for (int i = 0; i < Board.Get_Number() - 1; ++i) {
            for (int j = 0; j < Board.Get_Number() - 1; ++j) {
                if (Board.If_Valid_Move(i, j, 'v')){
                    Board.Update(i, j, 'v') ;
                    int Score = Get_The_best(Board, depth - 1, false, false) ;
                    Board.Remove(i, j, 'v') ;
                    if (Score > Temp){
                        Temp = Score ;
                        Row = i ;
                        Column = j ;
                    }
                }
            }
        }
        if (First){
            Board.Update(Row, Column, 'v') ;
        }
        return Temp ;
    }
    else{
        int Temp = 100 ;
        int Row, Column ;
        for (int i = 0; i < Board.Get_Number() - 1; ++i) {
            for (int j = 0; j < Board.Get_Number() - 1; ++j) {
                if (Board.If_Valid_Move(i, j, '>')){
                    Board.Update(i, j, '>') ;
                    int Score = Get_The_best(Board, depth - 1, true, false) ;
                    Board.Remove(i, j, '>') ;
                    if (Score < Temp){
                        Temp = Score ;
                        Row = i ;
                        Column = j ;
                    }
                }
            }
        }
        if (First){
            Board.Update(Row, Column, 'v') ;
        }
        return Temp ;
    }
}

void ComputerPlayer::Information() {
    cout << "The Name -> " << Name <<
         " and his Side -> " << Side << "\n" ;
}

string ComputerPlayer::Get_Name() {
    return Name;
}