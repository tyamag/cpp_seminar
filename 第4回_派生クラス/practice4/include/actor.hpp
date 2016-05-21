#pragma once

#include <vector>

struct Action;

// �A�N�V���������s����l(�v���C���[�Ƃ�)
class Actor {
public:
  Actor() {}
  ~Actor() {};
  void AddAction(Action* action) { actions_.push_back(action); }
  void InvokeAction(size_t i);

private:
  std::vector<Action*> actions_;
};
