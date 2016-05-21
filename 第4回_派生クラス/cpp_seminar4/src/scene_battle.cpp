#include "scene_battle.hpp"
#include "game.hpp"

#include <iostream>
#include <string>

void SceneBattle::Update(Game& game) {
  std::cout << "Battle scene update\n";
  std::cout << "Your turn\n";
  std::cout << ">>";
  std::string input;
  std::cin >> input;
  std::cout << "\n";
  // do something
}
