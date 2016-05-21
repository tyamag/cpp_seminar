#pragma once

#include <vector>

struct Action;

// アクションを実行する人(プレイヤーとか)
class Actor {
public:
  Actor() {}
  ~Actor() {};
  void AddAction(Action* action) { actions_.push_back(action); }
  void InvokeAction(size_t i);

private:
  std::vector<Action*> actions_;
};
