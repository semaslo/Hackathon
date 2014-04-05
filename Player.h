#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
public:
    Player(char* name, int playerID, int diamonds);
    ~Player();
    int GetDiamonds();
    void AddDiamonds(int diamonds);
    void SpendDiamonds(int diamonds);
private:
    int diamonds;
    int playerID;
    char* name;
};

Player::Player(char* name, int playerID, int diamonds){
    Player::diamonds = diamonds;
    Player::playerID = playerID;
    Player::name = (char*) malloc(strlen(name)*sizeof(char));
    sprintf(Player::name, name, strlen(name));
}

Player::~Player(){
    free(name);
}

void Player::AddDiamonds(int diamonds){
    Player::diamonds += diamonds;
}

void Player::SpendDiamonds(int diamonds){
    if(diamonds <= Player::diamonds){
        Player::diamonds -= diamonds;
    }
    else{
        throw 10;
    }
}

int Player::GetDiamonds(){
    return Player::diamonds;
}
#endif // PLAYER_H_INCLUDED
