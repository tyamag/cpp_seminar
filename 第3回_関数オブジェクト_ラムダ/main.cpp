#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct TsundereChara {
  TsundereChara(const std::string& name, int tsundere_power)
    : name_(name), tsundere_power_(tsundere_power) {}

  // メンバ関数として比較演算子を定義
  bool operator<(const TsundereChara& other) const {  // ← constな関数にしないとエラーになる
    return tsundere_power_ < other.tsundere_power_;
  }

  int tsundere_power() const { return tsundere_power_; }
  std::string name_;
  int tsundere_power_;
};

// グローバル関数としてTsundereCharaのツンデレ度比較演算子を定義
/*
bool operator<(const TsundereChara& a, const TsundereChara& b) {
  return a.tsundere_power_ < b.tsundere_power_;
}
*/

void Code1() {
  const TsundereChara yui("古手川唯", 3);
  const TsundereChara hinagiku("桂ヒナギク", 9);
  std::cout << "Q. " << yui.name_ << "　と " << hinagiku.name_
    << " ってどっちがよりツンデレってるのか?\n";
  // 定義した < 演算子を利用
  const auto& greater = (yui < hinagiku) ? hinagiku : yui;  // std::max(yui, hinagiku)でも可
  std::cout << "A. " << greater.name_ << " だゾ!\n";
}

// TsundereChara比較用関数オブジェクト
struct TsunderePowerComp {
  bool operator()(const TsundereChara& a, const TsundereChara& b) {
    return a.tsundere_power_ < b.tsundere_power_;
  }
};

void Code2() {
  const TsundereChara yui("古手川唯", 3);
  const TsundereChara hinagiku("桂ヒナギク", 9);
  std::cout << "Q. " << yui.name_ << "　と " << hinagiku.name_
    << " ってどっちがよりツンデレってるのか?\n";
  // 関数オブジェクトを利用
  const auto& greater = std::max(yui, hinagiku, TsunderePowerComp());
  std::cout << "A. " << greater.name_ << " だゾ!\n";
}

void Code3() {
  // 足し算の関数オブジェクト
  std::plus<int> i_plus;
  const int a = 1;
  const int b = 2;
  std::cout << i_plus(a, b) << "\n";

  // 2つのvectorを要素ごとに足す
  const std::vector<int> nums = {1, 2, 3, 4};
  const std::vector<int> nums2 = {10, 100, 1000, 10000};
  std::vector<int> result(nums.size());
  std::transform(nums.cbegin(), nums.cend(), nums2.cbegin(), result.begin(), i_plus);
  for (auto num : result) std::cout << num << ", ";
  std::cout << "\n";
}

template<class T>
const T& MyMax(const T& a, const T& b, bool (*Cmp)(const T&, const T&)) {  // 関数ポインタの指定が煩雑
  return Cmp(a, b) ? b : a;
}

bool TsundereComp(const TsundereChara& a, const TsundereChara& b) {
  return a.tsundere_power_ < b.tsundere_power_;
}

void Code4() {
  const TsundereChara yui("古手川唯", 3);
  const TsundereChara hinagiku("桂ヒナギク", 9);
  std::cout << "Q. " << yui.name_ << "　と " << hinagiku.name_
    << " ってどっちがよりツンデレってるのか?\n";
  const auto& greater = MyMax(yui, hinagiku, &TsundereComp);
  std::cout << "A. " << greater.name_ << " だゾ!\n";
}

void Code5() {
  const TsundereChara yui("古手川唯", 3);
  const TsundereChara hinagiku("桂ヒナギク", 9);
  std::cout << "Q. " << yui.name_ << "　と " << hinagiku.name_
    << " ってどっちがよりツンデレってるのか?\n";
  // ラムダ式の利用
  // 匿名の関数オブジェクトを作ってる
  /*
  [](const TsundereChara& a, const TsundereChara& b) { return a.tsundere_power_ < b.tsundere_power_; }
  は,
  struct ??? {
    bool operator()(const TsundereChara& a, const TsundereChara& b) {
      return a.tsundere_power_ < b.tsundere_power_;
    }
  };
  のような関数オブジェクトを生成する
  */
  const auto& greater = std::max(yui, hinagiku, [](const TsundereChara& a, const TsundereChara& b) {
    return a.tsundere_power_ < b.tsundere_power_;
  });
  std::cout << "A. " << greater.name_ << " だゾ!\n";
}

void Code6() {
  int count = 1;
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  // ラムダ式で変数(count)を参照
  std::for_each(nums.begin(), nums.end(), [&count](int num) {
    if (num % 2 == 0) count++;
  });
  std::cout << count << "\n";
}

int main() {
  Code6();

  return 0;
}
