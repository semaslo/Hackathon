#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
class Player
{
public:
   Player();
   int GetDiamonds();
   void AddDiamonds(int diamonds);
   void SpendDiamonds(int diamonds);
   void SetName(std::string name);
   std::string GetName();
private:
   int diamonds;
   std::string name;
};

#endif // PLAYER_H_INCLUDED
