#pragma once
#include "Creature.h"
#include <array>
#include <cstdlib>
#include <ctime>

class Monster : public Creature {
public:
  enum class Type {
    DRAGON,
    ORC,
    SLIME,
    MAX_TYPES,
  };

private:
  static const Creature &getDefaultCreature(Type type) {
    static const std::array<Creature, static_cast<std::size_t>(Type::MAX_TYPES)>
        monsterData{{{"dragon", 'D', 20, 4, 100},
                     {"orc", 'o', 4, 2, 25},
                     {"slime", 's', 1, 1, 10}}};

    return monsterData.at(static_cast<std::size_t>(type));
  }

public:
  Monster(Type type) : Creature{getDefaultCreature(type)} {}

  static Monster getRandomMonster() {
    static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};
    int num = static_cast<int>(Type::MAX_TYPES) * (std::rand() * fraction);
    return Monster{static_cast<Type>(num)};
  }
};
