#include "game.hpp"
#include "scene.hpp"

Game::Game() : scene_(nullptr) {}

Game::~Game() {
  if (scene_ != nullptr) delete scene_;
}

void Game::Start() {
  // メインループ
  while (true) {
    // 現在のシーンのUpdateが呼ばれる(ポリモーフィズム)
    // 例えば, scene_ が SceneTitle なら "Title scene update..." が表示される
    scene_->Update(*this);
  }
}

void Game::ChangeScene(Scene* scene) {
  if (scene_ != nullptr) delete scene_;
  scene_ = scene;
}
