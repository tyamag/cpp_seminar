#pragma once

#include "scene.hpp"

class SceneTitle : public Scene {  // Sceneクラスを継承
public:
  SceneTitle() {}
  ~SceneTitle() {}

  // override と書くことで関数をオーバーライドしていることを明示できる
  // 普通は, ヘッダ(.h や .hpp)では関数は宣言だけしておいて,
  // .c や .cpp ファイルに定義を書く
  void Update(Game& game) override;
};
