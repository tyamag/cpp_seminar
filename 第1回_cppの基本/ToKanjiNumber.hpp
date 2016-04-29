#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace ccilab {

class ToKanjiNumber {
public:
  /**
   * @brief 億単位までの自然数を漢数字に変換する
   * @param[in] natural_num 1～10^12-1(999,999,999,999)までの自然数, 0の場合は零になる
   * @return 漢数字
   */
  std::string operator()(unsigned long long natural_num) {
    if (natural_num == 0) return digit_kanji_list_[0];

    /*
    数字の後ろの方から4桁ずつ漢字に変換する
    ex) natural_num = 1045030
        kanji: 変換後の漢数字
        1045030 -> 104, 5030
        5030 -> "五千三十" + "" -> kanjiの先頭に挿入
        104 -> "百四" + "万" -> kanjiの先頭に挿入
        kanji = 百四万五千三十
    */
    std::string kanji_str = "";
    for (int i = 0; natural_num != 0; i += unit_num_of_digits_, natural_num /= unit_) {
      const auto unit_num = natural_num % unit_;
      const std::string digit_kanji = (unit_num == 0) ? "" : NumUnder10kToKanji(unit_num);
      const std::string scale_kanji = (i == 0 || digit_kanji == "") ? "" : Pow10ToKanji(i);
      kanji_str.insert(0, digit_kanji + scale_kanji);
    }
    if (kanji_str == "千万") kanji_str.insert(0, "一");

    return kanji_str;
  }

private:
  // 1万以内の数値を漢数字に変換する
  std::string NumUnder10kToKanji(unsigned long long natural_num) {
    const std::string num_str = std::to_string(natural_num % unit_);
    if (num_str == "0") return digit_kanji_list_[0];

    std::string kanji_str = "";
    for (size_t i = 0; i < num_str.size(); ++i) {
      const int digit = num_str[i] - '0';
      if (digit == 0) continue;
      const int exponent = static_cast<int>(num_str.size() - i - 1);
      const std::string digit_kanji = (digit == 1 && exponent > 0) ? "" : digit_kanji_list_[digit];
      const std::string scale_kanji = (exponent == 0) ? "" : Pow10ToKanji(exponent);
      kanji_str += (digit_kanji + scale_kanji);
    }

    return kanji_str;
  }

  // 10^n の数値を漢数字に変換する
  std::string Pow10ToKanji(int n) {
    const int base = n % unit_num_of_digits_;
    const int scale = n / unit_num_of_digits_ * unit_num_of_digits_;  // ex) n = 5, 5 / 4 = 1, 1 * 4 = 4
    const std::string base_kanji = (base == 0 && n > 0) ? "" : scale_kanji_map_.at(base);
    const std::string scale_kanji = (scale == 0) ? "" : scale_kanji_map_.at(scale);

    return base_kanji + scale_kanji;
  }

  const std::vector<std::string> digit_kanji_list_ = {
    "零", "一", "二", "三", "四", "五", "六", "七", "八", "九",
  };
  const std::unordered_map<int, std::string> scale_kanji_map_ = {
    {0, "一"}, {1, "十"}, {2, "百"}, {3, "千"},
    {4, "万"},
    {8, "億"},
  };
  const int unit_ = 10000;
  const int unit_num_of_digits_ = 4;
};

}
