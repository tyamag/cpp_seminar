#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

void Calculation() {
  using namespace std;
  const unordered_map<string, function<int(int, int)>> opcode_map = {
    {"+", plus<int>()}
    , {"-", minus<int>()}
    , {"*", multiplies<int>()}
    , {"/", divides<int>()}
    , {"special", [](int a, int b) { return (a + b) + (a - 2 * b) + (a * b) + (a / b); }}
  };

  const string prompt = "> ";
  cout << "input code like this: + 1 2\n";
  while (true) {
    std::cout << prompt;
    string opcode;
    int arg1, arg2;
    cin >> opcode >> arg1 >> arg2;
    if (opcode_map.find(opcode) == opcode_map.end()) {
      std::cerr << "error: \"" << opcode << "\" is not opcode!\n";
      continue;
    }
    std::cout << opcode_map.at(opcode)(arg1, arg2) << "\n";
  }
}

int main(int argc, char* argv[]) {
  Calculation();

  return 0;
}
