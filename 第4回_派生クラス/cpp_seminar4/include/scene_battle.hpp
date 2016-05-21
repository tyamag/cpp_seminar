#pragma once

#include "scene.hpp"

class SceneBattle : public Scene {
public:
  SceneBattle() {}
  ~SceneBattle() {}
  void Update(Game& game) override;
};
