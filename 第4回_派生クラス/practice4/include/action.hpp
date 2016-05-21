#pragma once

// 行動を表すクラス
struct Action {
  virtual ~Action() {}
  virtual void Invoke() = 0;
};

// 攻撃行動
struct Attack : public Action {
  void Invoke() override;
};

// 防御行動
struct Defense : public Action {
  void Invoke() override;
};
