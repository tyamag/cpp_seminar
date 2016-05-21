#pragma once

// Sceneの方でinclude Gameして, こっちでもinclude Sceneとすると,
// Sceneは, まだ宣言されてないGameを見ようとする
// Gameの方も, まだ宣言されてないSceneを見ようとする
// 結果, デッドロックっぽいことが起きてしまう
// これをさけるため, 前方宣言を行い, インクルードせずに
// コンパイラに, こういうクラスがあるぞ,　と教える
class Scene;

class Game {
public:
  Game();
  ~Game();
  void Start();
  void ChangeScene(Scene* scene);

private:
  Scene* scene_;
};
