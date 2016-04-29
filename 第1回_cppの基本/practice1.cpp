#include <iostream>
#include <string>
#include <vector>

// 10000�ȓ��̎��R�����������ɕϊ�����
// 0�̂Ƃ�, "��"��Ԃ�
std::string NumUnder10kToKanji(unsigned long long natural_num) {
  if (natural_num == 0) return "��";

  /*
  ex) natural_num = 1234
      1 -> "��"
      2 -> "��S"
      3 -> "�O�\"
      4 -> "�l"
      kanji_str = "���S�O�\�l"
  */
  const std::vector<std::string> digit_kanji_list = {
    "", "��", "��", "�O", "�l", "��", "�Z", "��", "��", "��"
  };
  const std::vector<std::string> scale_kanji_list = {
    "", "�\", "�S", "��"
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

// ���P�ʂ܂ł̎��R�����������ɕϊ�����
// 0�̂Ƃ�, "��"��Ԃ�
std::string ToKanjiNumbers(unsigned long long natural_num) {
  if (natural_num == 0) return NumUnder10kToKanji(natural_num);

  /*
  ���j: �����̌��̕�����4���������ɕϊ�����
  ex) natural_num = 1045030
      kanji: �ϊ���̊�����
      1045030 -> 104, 5030
      5030 -> "�ܐ�O�\" + "" -> kanji�̐擪�ɑ}��
      104 -> "�S�l" + "��" -> kanji�̐擪�ɑ}��
      kanji = �S�l���ܐ�O�\
  */
  const int UNIT = 10000;
  const std::vector<std::string> scale_kanji_list = {
   "", "��", "��"
  };
  std::string kanji_str = "";
  for (int i = 0; natural_num != 0; ++i, natural_num /= UNIT) {
    const auto unit_num = natural_num % UNIT;
    const auto digit_kanji = (unit_num == 0) ? "" : NumUnder10kToKanji(unit_num);
    const auto scale_kanji = (digit_kanji == "") ? "" : scale_kanji_list[i];
    kanji_str.insert(0, digit_kanji + scale_kanji);
  }
  if (kanji_str == "�疜") kanji_str.insert(0, "��");
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
