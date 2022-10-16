#include "Creature.h"
#include "Monster.h"
#include "Player.h"
#include <iostream>
#include <string>

void attackMonster(Player &player, Monster &monster) {
  if (player.isDead()) {
    return;
  }

  std::cout << "You hit the " << monster.getName() << " for "
            << player.getDamage() << " damage.\n";
  monster.reduceHealth(player.getDamage());
  if (monster.isDead()) {
    std::cout << "!!!You killed " << monster.getName() << "!!!" << std::endl;
    player.levelUp();
    player.addGold(monster.getGold());
    std::cout << "You are now level " << player.getLevel() << std::endl;
    std::cout << "You now have " << player.getGold() << " gold" << std::endl;
  }
}
void attackPlayer(Player &player, Monster &monster) {
  if (monster.isDead()) {
    return;
  }
  std::cout << "You got attacked by " << monster.getName() << " with damage "
            << monster.getDamage() << std::endl;
  player.reduceHealth(monster.getDamage());
  std::cout << "Your remaining health is " << player.getHealth() << std::endl;
}

void fightMonster(Player &player) {
  Monster monster{Monster::getRandomMonster()};
  std::cout << "You have encountered a " << monster.getName() << " ("
            << monster.getSymbol() << ").\n";

  while (!player.isDead() && !monster.isDead()) {
    std::cout << "(R)un or (F)fight: ";
    std::string choosing;
    std::cin >> choosing;
    if (choosing == "F" || choosing == "f") {
      attackMonster(player, monster);
      attackPlayer(player, monster);
    }
    if (choosing == "R" || choosing == "r") {
      static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};
      int num = static_cast<int>(2) * (std::rand() * fraction);
      if (num == 1) {
        std::cout << "You failed to flee" << std::endl;
        attackPlayer(player, monster);
      } else {
        std::cout << "You successfully fled" << std::endl;
      }
    }
  }
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::rand();

  std::string player_name;
  std::cout << "Enter your name : ";
  std::cin >> player_name;
  Player player(player_name);
  std::cout << "Welcome, " << player.getName() << std::endl;
  std::cout << "You have " << player.getHealth() << " health and are carrying "
            << player.getGold() << " gold.\n";

  while (!player.isDead() && !player.hasWon()) {
    fightMonster(player);
  }

  if (player.isDead()) {
    std::cout << "You lost at level " << player.getLevel() << " with "
              << player.getGold() << " gold" << std::endl;
  }
  if (player.hasWon()) {
    std::cout << "Congrats, " << player.getName() << ". You won with "
              << player.getGold() << " gold" << std::endl;
  }

  return 0;
}
