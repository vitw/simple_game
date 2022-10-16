#pragma once
#include "Creature.h"
#include <string>

class Player : public Creature {
private:
  int m_level;

public:
  Player(std::string name);
  void levelUp();
  int getLevel() { return m_level; }
  bool hasWon();
};
