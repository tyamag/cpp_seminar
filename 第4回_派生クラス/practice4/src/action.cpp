#include "action.hpp"

#include <iostream>

void Attack::Invoke() {
  std::cout << "こうげき!\n";
}

void Defense::Invoke() {
  std::cout << "ぼうぎょ!\n";
}
