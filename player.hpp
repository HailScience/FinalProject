#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
private:
    int position;
public:
    Player(int position)
    {
        this->position = position;
    }
    void setPosition(int position)
    {
        this->position = position;
    }
    int getPosition()
    {
        return position;
    }
};

#endif