#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace ccilab {

class ToKanjiNumber {
public:
  /**
   * @brief ���P�ʂ܂ł̎��R�����������ɕϊ�����
   * @param[in] natural_num 1�`10^12-1(999,999,999,999)�܂ł̎��R��, 0�̏ꍇ�͗�ɂȂ�
   * @return ������
   */
  std::string operator()(unsigned long long natural_num) {
    if (natural_num == 0) return digit_kanji_list_[0];

    /*
    �����̌��̕�����4���������ɕϊ�����
    ex) natural_num = 1045030
        kanji: �ϊ���̊�����
        1045030 -> 104, 5030
        5030 -> "�ܐ�O�\" + "" -> kanji�̐擪�ɑ}��
        104 -> "�S�l" + "��" -> kanji�̐擪�ɑ}��
        kanji = �S�l���ܐ�O�\
    */
    std::string kanji_str = "";
    for (int i = 0; natural_num != 0; i += unit_num_of_digits_, natural_num /= unit_) {
      const auto unit_num = natural_num % unit_;
      const std::string digit_kanji = (unit_num == 0) ? "" : NumUnder10kToKanji(unit_num);
      const std::string scale_kanji = (i == 0 || digit_kanji == "") ? "" : Pow10ToKanji(i);
      kanji_str.insert(0, digit_kanji + scale_kanji);
    }
    if (kanji_str == "�疜") kanji_str.insert(0, "��");

    return kanji_str;
  }

private:
  // 1���ȓ��̐��l���������ɕϊ�����
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

  // 10^n �̐��l���������ɕϊ�����
  std::string Pow10ToKanji(int n) {
    const int base = n % unit_num_of_digits_;
    const int scale = n / unit_num_of_digits_ * unit_num_of_digits_;  // ex) n = 5, 5 / 4 = 1, 1 * 4 = 4
    const std::string base_kanji = (base == 0 && n > 0) ? "" : scale_kanji_map_.at(base);
    const std::string scale_kanji = (scale == 0) ? "" : scale_kanji_map_.at(scale);

    return base_kanji + scale_kanji;
  }

  const std::vector<std::string> digit_kanji_list_ = {
    "��", "��", "��", "�O", "�l", "��", "�Z", "��", "��", "��",
  };
  const std::unordered_map<int, std::string> scale_kanji_map_ = {
    {0, "��"}, {1, "�\"}, {2, "�S"}, {3, "��"},
    {4, "��"},
    {8, "��"},
  };
  const int unit_ = 10000;
  const int unit_num_of_digits_ = 4;
};

}
