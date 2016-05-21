#include "scene_title.hpp"
#include "scene_battle.hpp"
#include "game.hpp"

#include <iostream>
#include <string>

void SceneTitle::Update(Game& game) {
  std::cout << "Title scene update\n";
  std::cout << "press \'z\' to start game\n";
  std::cout << ">>";
  std::string input;
  std::cin >> input;
  std::cout << "\n";
  if (input == "z") {  // ƒV[ƒ“‘JˆÚ
    game.ChangeScene(new SceneBattle());
  }
}
