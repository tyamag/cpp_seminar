#include <iostream>
#include <string>
#include <vector>

// 10000以内の自然数を漢数字に変換する
// 0のとき, "零"を返す
std::string NumUnder10kToKanji(unsigned long long natural_num) {
  if (natural_num == 0) return "零";

  /*
  ex) natural_num = 1234
      1 -> "千"
      2 -> "二百"
      3 -> "三十"
      4 -> "四"
      kanji_str = "千二百三十四"
  */
  const std::vector<std::string> digit_kanji_list = {
    "", "一", "二", "三", "四", "五", "六", "七", "八", "九"
  };
  const std::vector<std::string> scale_kanji_list = {
    "", "十", "百", "千"
  };
  const auto num_str = std::to_string(natural_num);
  std::string kanji_str = "";
  for (size_t i = 0; i < num_str.size(); ++i) {
    const int digit = num_str[i] - '0';
    if (digit == 0) continue;
    const int exponent = static_cast<int>(num_str.size() - i - 1);
    const std::string digit_kanji = (digit == 1 && exponent > 0) ? "" : digit_kanji_list[digit];
    const std::string scale_kanji = (exponent == 0) ? "" : scale_kanji_list[exponent];
    kanji_str += (digit_kanji + scale_kanji);
  }
  return kanji_str;
}

// 億単位までの自然数を漢数字に変換する
// 0のとき, "零"を返す
std::string ToKanjiNumbers(unsigned long long natural_num) {
  if (natural_num == 0) return NumUnder10kToKanji(natural_num);

  /*
  方針: 数字の後ろの方から4桁ずつ漢字に変換する
  ex) natural_num = 1045030
      kanji: 変換後の漢数字
      1045030 -> 104, 5030
      5030 -> "五千三十" + "" -> kanjiの先頭に挿入
      104 -> "百四" + "万" -> kanjiの先頭に挿入
      kanji = 百四万五千三十
  */
  const int UNIT = 10000;
  const std::vector<std::string> scale_kanji_list = {
   "", "万", "億"
  };
  std::string kanji_str = "";
  for (int i = 0; natural_num != 0; ++i, natural_num /= UNIT) {
    const auto unit_num = natural_num % UNIT;
    const auto digit_kanji = (unit_num == 0) ? "" : NumUnder10kToKanji(unit_num);
    const auto scale_kanji = (digit_kanji == "") ? "" : scale_kanji_list[i];
    kanji_str.insert(0, digit_kanji + scale_kanji);
  }
  if (kanji_str == "千万") kanji_str.insert(0, "一");
  return kanji_str;
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
  };

  for (auto num : test_num) {
    std::cout << num << " = " << ToKanjiNumbers(num) << "\n";
  }

  return 0;
}
