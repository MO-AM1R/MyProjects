# include "A_M_Game.h"

Player::Player() = default;

Player::Player(string N, char S){
    Name = std::move(N) ;
    Side = S ;
}

void Player::Information() {
    cout << "The Name -> " << Name <<
    " and his Side -> " << Side << "\n" ;
}

string Player::Get_Name() {
    return Name ;
}

char Player::Get_Side() const {
    return Side;
}

void Player::Set_Name(string n) {
    Name = std::move(n);
}

void Player::Get_Move(int & row, int & col) {
    cout << "Player " << Name << " Enter the coordinate of the rocket\n";
    cin >> row >> col ;
}