# ifndef PROBLEM_5_6_A_M_GAME_CUH
# define PROBLEM_5_6_A_M_GAME_CUH

# include <iostream>
# include <iomanip>

using namespace std ;

class board{
private:
    int Number ;
    char** Board ;

public:
    void Set(int n) ;
    void Display() ;
    int isWinner() ;
    void Update(int row, int Col, char S) ;
    bool If_Exist_Moves(char S) ;
    bool If_Valid_Move(int row, int Col, char S) ;
    [[nodiscard]] int Get_Number() const ;
    void Remove(int row, int Col, char S) ;
    ~board() ;
};

class Player{
protected:
    string Name ;
    char Side{} ;

public:
    Player() ;
    explicit Player(string N, char S) ;
    virtual void Information() ;
    virtual string Get_Name() ;
    void Set_Name(string n) ;
    void Get_Move(int & row, int & col) ;
    [[nodiscard]] virtual char Get_Side() const ;
};

class ComputerPlayer : public Player{
private:
    string Name ;
    char Side{} ;

public:
    ComputerPlayer() ;
    void Information() override ;
    int Get_The_best(board & Board, int depth, bool IsComputer, bool First) ;
    [[nodiscard]] char Get_Side() const override ;
    string Get_Name() override  ;
};

class Game_Manger {
private:
    board Board{} ;

public:
    explicit Game_Manger(int n) ;
    void run() ;
};

# endif //PROBLEM_5_6_A_M_GAME_CUH