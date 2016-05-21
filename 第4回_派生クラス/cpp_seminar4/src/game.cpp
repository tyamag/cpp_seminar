#include "game.hpp"
#include "scene.hpp"

Game::Game() : scene_(nullptr) {}

Game::~Game() {
  if (scene_ != nullptr) delete scene_;
}

void Game::Start() {
  // ���C�����[�v
  while (true) {
    // ���݂̃V�[����Update���Ă΂��(�|�����[�t�B�Y��)
    // �Ⴆ��, scene_ �� SceneTitle �Ȃ� "Title scene update..." ���\�������
    scene_->Update(*this);
  }
}

void Game::ChangeScene(Scene* scene) {
  if (scene_ != nullptr) delete scene_;
  scene_ = scene;
}
