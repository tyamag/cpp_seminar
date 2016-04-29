#include <algorithm>
#include <numeric>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>

void code1() {
  // C言語での文字列の長さ取得
  const char* c_str = "I like C.";
  std::cout << c_str << ": length = " << std::strlen(c_str) << "\n";  // 関数を使う
                                                                      // std::stringの利用
  const std::string cpp_str = "I prefer C++.";
  std::cout << cpp_str << ": length = " << cpp_str.length() << "\n"; // stringのメンバ関数を使う
}

// プレイヤーキャラクラス
class Player {
public:
  Player(const std::string& name, int hp)
    : name_(name), hp_(hp) {
    /*
    メンバ初期化子リストを使う場合
    name_, hp_ は, それぞれ name, hp で初期化される
    */
  }
  /*
  Player(const std::string& name, int hp) {
    //メンバ初期化子リストを使わない場合
    //メンバ name_, hp_ はまず適当な値で初期化される
    //ex) name_(""); hp_(??);
    //その後, 値が代入されるため, 非効率
    
    name_ = name;
    hp_ = hp;
  }
  */
  // デストラクタ
  ~Player() {}
  // ゲッター
  const std::string& name() const { return name_; }
  int hp() const { return hp_; }
  // セッター
  void set_hp(int hp) { hp_ = hp; }

private:
  std::string name_;  // 名前
  int hp_;            // ヒットポイント
};

void code2() {
  Player player("ロト", 10);
  std::cout << player.name() << " hp = " << player.hp() << "\n";
  player.set_hp(1);
  std::cout << player.name() << " hp = " << player.hp() << "\n";
}

void code3() {
  std::vector<int> i_vec = {1, 2, 3};                // intを格納するvector
  std::vector<double> d_vec = {1.0, 1.414, 1.7325};  // doubleを格納するvector
  for (auto num : i_vec) std::cout << num << " ";
  std::cout << "\n";
  for (auto num : d_vec) std::cout << num << " ";
  std::cout << "\n";
}

template<class Range, class T>
T Sum(const Range& range, T init) {
  for (const auto& elem : range) { 
    init += elem;
  }
  return init;
}

void code4() {
  int i_array[] = {1, 2, 3};
  std::cout << Sum(i_array, 0) << "\n";
  std::vector<int> i_vec = {4, 5, 6};
  std::cout << Sum(i_vec, 0) << "\n";
  std::vector<std::string> str_vec = {
    "ふるいけや", "かわずとびこむ", "みずのおと"
  };
  std::cout << Sum(str_vec, std::string("")) << "\n";
}

template<class Range>
void PrintRange(const Range& range) {
  std::cout << "[ ";
  for (const auto& elem : range) { 
    std::cout << elem << ", ";
  }
  std::cout << "]\n";
}

void code5() {
  int i_array[] = {1, 2, 3};
  PrintRange(i_array);
  std::vector<int> i_vec = {4, 5, 6};
  PrintRange(i_vec);
  std::vector<std::string> str_vec = {
    "ふるいけや", "かわずとびこむ", "みずのおと"
  };
  PrintRange(str_vec);
}

template<class T>
class MyContainer {
public:
  MyContainer(size_t size) : size_(size), ptr_(new T[size]) {}
  ~MyContainer() { delete[] ptr_; }
  T& operator[](size_t i) { return ptr_[i]; }
  size_t size() const { return size_; }
private:
  size_t size_;
  T* ptr_;
};

void code6() {
  MyContainer<int> i_container(2);
  i_container[0] = 0;
  i_container[1] = 1;
  for (size_t i = 0; i < i_container.size(); ++i) {
    std::cout << i_container[i] << "\n";
  }
}

void code7() {
  std::vector<int> i_vec;  // 動的配列 vector
  i_vec.push_back(666);  // vectorの末尾に要素を追加
  i_vec.push_back(9999);
  for (const auto& elem : i_vec) std::cout << elem << ", ";
  std::cout << "\n";

  std::list<int> i_list; // 双方向リスト list
  i_list.push_back(111);  // listの末尾に要素を追加
  i_list.insert(i_list.begin(), {0, 1}); // listの先頭に要素を挿入
  for (const auto& elem : i_list) std::cout << elem << ", ";
  std::cout << "\n";

  // 作品名とその作品に登場するツンデレキャラのハッシュマップ
  std::unordered_map<std::string, std::string> tundere_map;
  tundere_map["とらドラ！"] = "逢坂大河";
  tundere_map["ラブライブ！"] = "西木野真姫";
  for (const auto& pair : tundere_map) {
    std::cout << pair.first << " -> " << pair.second << "\n";
  }
}

void code8() {
  std::vector<int> i_vec = {1, 2, 3};
  // 1. 添え字で全走査(データ構造に依存)
  for (size_t i = 0; i < i_vec.size(); ++i) std::cout << i_vec[i] << " ";
  std::cout << "\n";
  // 2. イテレータで全走査
  for (auto iter = i_vec.begin(); iter != i_vec.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << "\n";
  // 3. 範囲for文(暗黙的にイテレータを利用 ... 2と同じ)
  for (auto num : i_vec) std::cout << num << " ";
  std::cout << "\n";
}

void code9() {
  std::vector<int> i_vec = {3, 2, 1};
  // vectorの合計を計算
  std::cout << std::accumulate(i_vec.begin(), i_vec.end(), 0) << "\n";
  // vectorを昇順にソート
  std::sort(i_vec.begin(), i_vec.end());
  for (auto num : i_vec) std::cout << num << " ";
  std::cout << "\n";
}

int main() {
  std::vector<int> i_vec = {3, 2, 1};
  // vectorの合計を計算
  std::cout << std::accumulate(i_vec.begin(), i_vec.end(), 0) << "\n";
  // vectorを昇順にソート
  std::sort(i_vec.begin(), i_vec.end());
  for (auto num : i_vec) std::cout << num << " ";
  std::cout << "\n";

  return 0;
}
