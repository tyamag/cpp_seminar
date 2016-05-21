#include "game.hpp"
#include "scene_title.hpp"

int main() {
  Game game;
  game.ChangeScene(new SceneTitle());
  game.Start();
  return 0;
}
