#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <string>
#include <unordered_map>

#include "Func.hpp"
#include "ToKanjiNumber.hpp"

namespace ccilab {

template<class T>
class vector {
  // ...
};

}

void Code1() {
  std::cout << "Hello, World!\n";
}

void Code2() {
  std::vector<int> array1;
  ccilab::vector<int> array2;
  // ...
}

void Code3() {
  using std::cout;  // このスコープ内のcoutはstd::coutであることを示す.
                    // std::coutのみstd::の表記を省略できる.
  cout << "Happy new nyaa!\n";
}

void Code4() {
  using namespace std;  // std名前空間のすべての名前にアクセスできるようにする.
  cout << "Happy new nyaa!\n";
  vector<int> array;
}

void Code5() {
  bool b  = true;  short s  = 1;
  int i   = 42;    long l   = 114514;
  float f = 3.14;  double d = 1.7320508;
  std::cout << b << ' ' <<  s << ' '  // <<は連結できる
    << i << ' ' << l << ' '
    << f << ' ' << d << "\n";
}

void Code6() {
  struct Point {
    int x, y;
  };

  Point points[] = {
    {0, 0}, {2, 5}
  };
  Point* ptr = &(points[0]);  // &アドレス演算子. ptr = points でも可
  ptr->x = 1;                 // ->アロー演算子. (*ptr).x = 1 または ptr[0].x = 1 と同じ意味
  std::cout << "(x, y) = (" << ptr->x << ", " << ptr->y << ")\n";
  std::cout << "(x, y) = (" << ptr[1].x << ", " << ptr[1].y << ")\n";
  std::cout << ptr << "\n";
  std::cout << ptr + 1 << "\n";
  ptr = nullptr;  // 何も指さないとき. C++ではNULLではなくnullptrを使ったほうがよい
}

void Code7() {
  int* ptr = new int;  // new 型名 で動的にメモリを確保
  // ...
  delete ptr;  // メモリを解放

  int size = 100;
  int* array = new int[size];  // size分確保
  // ...
  delete [] array;  // 複数メモリ確保した場合は, deleteのあとに[]必要

  // 2次元配列
  int row = 100, col = 10;
  int** array2d = new int*[row];
  for (int i = 0; i < row; ++i) {
    array2d[i] = new int[col];
  }
  // ...
  for (int i = 0; i < row; ++i) {
    delete [] array2d[i];
  }
}

void PrintBookTitles(const std::vector<std::string>& title_list, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    std::cout << title_list[i] << "\n";
  }
}

void Code8() {
  using namespace std;
  // 魔導書10万8000冊記憶
  vector<string> index(108000);
  index[0] = "エイボンの書";
  index[1] = "秘王の教義";
  index[2] = "ネクロノミコン";
  // ...

  // 最初の3冊の魔導書の題名を出力
  PrintBookTitles(index, 3);
}

void Code9() {
  int answer = 42;
  int& ref = answer;
  //int& foo;  // 初期化してないためエラーになる
}

void Code10() {
  const std::string password = "password";  // 初期化
  //password = "super hacker";  // constなオブジェクトには代入できないためエラーになる
}

// 10^nを漢数字に変換する
std::string KanjiOf10ToPower(int n) {
  const std::unordered_map<int, std::string> kanji_scale_map = {
    {0, "一"}, {1, "十"}, {2, "百"}, {3, "千"},
    {4, "万"},
    {8, "億"},
  };

  const int base = n % 4;  // 一, 十, 百, 千の4つ
  const int scale = n / 4 * 4; // ex) n = 5, 5 / 4 = 1, 1 * 4 = 4

  return (base == 0 && n > 0 ? "" : kanji_scale_map.at(base))  // n = 4 とか 8 のときは '一' を省略
    + (scale > 0 ? kanji_scale_map.at(scale) : "");
}

std::string ToKanjiNumbersUnder10000(unsigned long long natural_num) {
  const std::string kanji0to9[] = {
    "零",  // ダミー
    "一", "二", "三", "四", "五", "六", "七", "八", "九",
  };

  const std::string sub_num_str = std::to_string(natural_num % 10000);
  if (sub_num_str == "0") return "";

  std::string kanji_str = "";
  for (size_t i = 0; i < sub_num_str.size(); ++i) {
    const int base = sub_num_str[i] - '0';
    if (base == 0) continue;

    const int exponent = static_cast<int>(sub_num_str.size() - i - 1);
    const std::string base_kanji = (base == 1 && exponent > 0 ? "" : kanji0to9[base]);
    const std::string scale_kanji = (exponent == 0 ? "" : KanjiOf10ToPower(exponent));
    kanji_str += base_kanji + scale_kanji;
  }

  return kanji_str;
}

/**
 * @brief 億単位までの自然数を漢数字に変換する
 * @param natural_num 1～10^12-1(999,999,999,999)までの自然数, 0の場合は零になる
 * @return 漢数字
 */
std::string ToKanjiNumbers(unsigned long long natural_num) {
  if (natural_num == 0) return "零";
  if (natural_num == 10000000) return "一千万";

  // 数字のけつの方から4桁ずつ漢字に変換する
  std::string kanji_str = "";
  for (int i = 0; natural_num != 0; i += 4, natural_num /= 10000) {
    const std::string base_kanji = ToKanjiNumbersUnder10000(natural_num);
    const std::string scale_kanji = (i > 0 && base_kanji != "" ? KanjiOf10ToPower(i) : "");
    kanji_str.insert(0, base_kanji + scale_kanji);
  }

  return kanji_str;
}

template <class T>
class NumUnitGen {
public:
  NumUnitGen(T num, T unit) : num_(num), unit_(unit) {};
  T operator()() {
    const T sub_num = num_ % unit_;
    num_ /= unit_;

    return sub_num;
  }

private:
  T num_;
  const T unit_;
};

std::string NumUnder10kToKanji(unsigned long long natural_num) {
  if (natural_num == 0) return "零";

  /*
  ex) kanji_str = "1234"
      '4' -> "四"
      '3' -> "三十"
      '2' -> "二百"
      '1' -> "千"
      digit_strs = {
        "四", "三十", "二百", "千"
      }
  */
  using namespace std;
  const vector<string> digit_kanji_list = {
    "", "一", "二", "三", "四", "五", "六", "七", "八", "九",
  };
  const vector<string> scale_list = {
    "", "十", "百", "千"
  };
  const auto digit_strs = Func::Map(Func::Reverse(to_string(natural_num)), scale_list, vector<string>(),
    [&](char digit_ch, const string& scale_kanji) {
      const int digit = digit_ch - '0';
      const auto digit_kanji  = (digit == 1 && scale_kanji != "")
                                  ? "" : digit_kanji_list[digit];
      const auto scale_kanji2 = (digit == 0 || scale_kanji == "")
                                  ? "" : scale_kanji;
      return digit_kanji + scale_kanji2;
    });
  return Func::Fold(Func::Reverse(digit_strs), string(""));
}

std::string ToKanjiNumbers2(unsigned long long natural_num) {
  if (natural_num == 0) return NumUnder10kToKanji(natural_num);

  using namespace std;
  using ullong = unsigned long long;  // size_tが処理系依存のため別名定義

  const auto num_of_digit = to_string(natural_num).size();
  const auto unit_count = num_of_digit / 4 + ((num_of_digit % 4 > 0) ? 1 : 0);  // 4桁の単位が何個あるか
  const vector<string> scale_list = {
    "", "万", "億", "兆"
  };
  const auto unit_kanji_list = Func::Map(
    Func::GenerateN(vector<ullong>(), unit_count, NumUnitGen<ullong>(natural_num, 10000)),
    scale_list, vector<string>(),
    [](const ullong unit_num, const string& scale_kanji) {
      const string digit_kanji = (unit_num == 0) ? "" : NumUnder10kToKanji(unit_num);
      return (digit_kanji == "") ? "" : digit_kanji + scale_kanji;
    });
  const auto kanji_str = Func::Fold(Func::Reverse(unit_kanji_list), string(""));
  return (kanji_str == "千万") ? "一" + kanji_str : kanji_str;
}

int main() {
  const unsigned long long test_num[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 17,
    100, 101, 110, 199, 200,
    1000, 1001, 1111, 9991, 9999,
    10000, 10001, 11111, 22312, 77777, 99999,
    100000, 100001,
    10000000, 98237234,
    100000000, 111111111,
    1000300521, 23411110000,
    10000000000, 900911111119,
    100000000000, 100911111111,
    555555555555, 999999999999,
    1999999999990, 9999999999999,
  };

  /*
  ccilab::ToKanjiNumber ToKanjiNum;
  for (auto num : test_num) {
    std::cout << num << " = " << ToKanjiNum(num) << "\n";
  }
  */

  for (auto num : test_num) {
    std::cout << num << " = " << ToKanjiNumbers2(num) << "\n";
  }

  return 0;
}
