#pragma once
#include <string>

class Creature {
protected:
  std::string m_name;
  char m_symbol;
  int m_health;
  int m_damage;
  int m_gold;

public:
  Creature(std::string name, char symbol, int health, int damage, int gold);
  std::string getName() { return m_name; }
  char getSymbol() { return m_symbol; }
  int getHealth() { return m_health; };
  int getDamage() { return m_damage; };
  int getGold() { return m_gold; };

  void reduceHealth(int damage);
  bool isDead();
  void addGold(int gold);
};
