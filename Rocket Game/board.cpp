# include "A_M_Game.h"

void board::Display() {

    for (int i = 0; i < Number; ++i) {
        if (i == 0){
            cout << "   " ;
            for (int j = 0; j < Number; ++j) {
                cout << j << ' ' ;
            }
            cout << "\n   " << setw((Number * 2) - 1) << setfill('-') << '-' ;
            cout << '\n' ;
        }
        for (int j = 0; j < Number; ++j) {
            if (j == 0){
                cout << i << "| " ;
            }
            cout << Board[i][j] << " " ;
        }
        cout << "\n" ;
    }
}

int board::isWinner() {
    int result = 0;

    for (int i = 1; i < Number - 1; ++i) {
        if (Board[Number - 1][i] == 'v'){
            result = 1 ;
        }
        else{
            result = 0;
            break ;
        }
    }
    if (result != 1) {
        for (int i = 1; i < Number - 1; ++i) {
            if (Board[i][Number - 1] == '>') {
                result = -1;
            } else {
                result = 0;
                break;
            }
        }
    }
    return result ;
}

void board::Update(int row, int Col, char S) {
    if ((Board[row][Col] == S) && S == 'v'){
        if (Board[row + 1][Col] == '*'){
            Board[row + 1][Col] = 'v' ;
            Board[row][Col] = '*' ;
        }
        else{
            Board[row + 2][Col] = 'v' ;
            Board[row][Col] = '*' ;
        }
    }
    else{
        if (Board[row][Col + 1] == '*'){
            Board[row][Col + 1] = '>' ;
            Board[row][Col] = '*' ;
        }
        else{
            Board[row][Col + 2] = '>' ;
            Board[row][Col] = '*' ;
        }
    }
}

void board::Remove(int row, int Col, char S) {
    if (S == 'v'){
        if (Board[row + 1][Col] == 'v') {
            Board[row + 1][Col] = '*';
        }
        else{
            Board[row + 2][Col] = '*';
        }

        if (Board[row][Col] == '*') {
            Board[row][Col] = 'v';
        }
        else{
            Board[row - 1][Col] = 'v';
        }
    }
    else {
        if (Board[row][Col + 1] == '>') {
            Board[row][Col + 1] = '*';
        }
        else{
            Board[row][Col + 2] = '*';
        }

        if (Board[row][Col] == '*') {
            Board[row][Col] = '>';
        }
        else{
            Board[row][Col - 1] = '>';
        }
    }
}

void board::Set(int n) {
    Number = n ;

    Board = new char* [n] ;
    for (int i = 0; i < n; ++i) {
        Board[i] = new char [n] ;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Board[i][j] = '*' ;
        }
    }

    for (int i = 1; i <= Number - 2; ++i) {
        Board[i][0] = '>' ;
    }
    for (int i = 1; i <= Number - 2; ++i) {
        Board[0][i] = 'v' ;
    }
}

int board::Get_Number() const {
    return Number;
}

board::~board() {
    for (int i = 0; i < Number; ++i) {
        delete[] Board[i] ;
    }
    delete[] Board ;
}

bool board::If_Valid_Move(int row, int Col, char S) {
    if (row > Number - 2 || Col > Number - 2){
        return false ;
    }
    if (Board[row][Col] == '>' && S == '>'){
        if (Board[row][Col + 1] == '*' || Board[row][Col + 2] == '*'){
            return true ;
        }
        else{
            return false ;
        }
    }
    else if (Board[row][Col] == 'v' && S == 'v'){
        if (Board[row + 1][Col] == '*' || Board[row + 2][Col] == '*'){
            return true ;
        }
        else{
            return false ;
        }
    }
    else{
        return false ;
    }
}

bool board::If_Exist_Moves(char S) {
    for (int i = 0; i < Number - 1; ++i) {
        for (int j = 0; j < Number - 1; ++j) {
            if (If_Valid_Move(i, j, S)){
                return true ;
            }
        }
    }
    return false ;
}