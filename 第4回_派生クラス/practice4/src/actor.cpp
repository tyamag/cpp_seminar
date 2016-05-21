#include "actor.hpp"
#include "action.hpp"

void Actor::InvokeAction(size_t i) {
  actions_[i]->Invoke();
}
