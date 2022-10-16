#include "Creature.h"
#include <string>

Creature::Creature(std::string name, char symbol, int health, int damage,
                   int gold)
    : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage},
      m_gold{gold} {};

void Creature::reduceHealth(int damage) { m_health -= damage; }
bool Creature::isDead() { return m_health <= 0 ? true : false; }
void Creature::addGold(int gold) { m_gold += gold; }
