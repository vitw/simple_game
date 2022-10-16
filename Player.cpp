#include "Player.h"
#include <iostream>
#include <string>

Player::Player(std::string name) : Creature(name, '@', 10, 1, 0){};

void Player::levelUp() {
  m_level++;
  m_damage++;
  m_health += 2;
}

bool Player::hasWon() { return m_level >= 20 ? true : false; }
