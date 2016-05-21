#pragma once  // このファイルを一度だけincludeされるようにするプリプロセス

// 前方宣言
class Game;

// ゲームで使うようなシーンの抽象クラス(タイトルとか戦闘画面とか)
class Scene {
public:
  // メンバ関数に virtual を付けることで派生クラスで再定義(オーバーライド)できる
  virtual ~Scene() {}  // 抽象クラスのデストラクタをvirtualにしとかないと派生クラスのデストラクタが呼ばれない!

  // 純粋仮想関数 virtual 関数 = 0
  // 抽象クラスだから実装はしないけど, 派生クラスはこういう関数(インターフェース)を持つよということを示す
  virtual void Update(Game& game) = 0;

  // 純粋仮想関数が1つでもあるクラスはオブジェクトを作成できないため, コンストラクタは定義する必要がない
  // Scene() {}  // ← 意味なし
};
