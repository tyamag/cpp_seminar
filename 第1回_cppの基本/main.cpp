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
  using std::cout;  // ���̃X�R�[�v����cout��std::cout�ł��邱�Ƃ�����.
                    // std::cout�̂�std::�̕\�L���ȗ��ł���.
  cout << "Happy new nyaa!\n";
}

void Code4() {
  using namespace std;  // std���O��Ԃ̂��ׂĂ̖��O�ɃA�N�Z�X�ł���悤�ɂ���.
  cout << "Happy new nyaa!\n";
  vector<int> array;
}

void Code5() {
  bool b  = true;  short s  = 1;
  int i   = 42;    long l   = 114514;
  float f = 3.14;  double d = 1.7320508;
  std::cout << b << ' ' <<  s << ' '  // <<�͘A���ł���
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
  Point* ptr = &(points[0]);  // &�A�h���X���Z�q. ptr = points �ł���
  ptr->x = 1;                 // ->�A���[���Z�q. (*ptr).x = 1 �܂��� ptr[0].x = 1 �Ɠ����Ӗ�
  std::cout << "(x, y) = (" << ptr->x << ", " << ptr->y << ")\n";
  std::cout << "(x, y) = (" << ptr[1].x << ", " << ptr[1].y << ")\n";
  std::cout << ptr << "\n";
  std::cout << ptr + 1 << "\n";
  ptr = nullptr;  // �����w���Ȃ��Ƃ�. C++�ł�NULL�ł͂Ȃ�nullptr���g�����ق����悢
}

void Code7() {
  int* ptr = new int;  // new �^�� �œ��I�Ƀ��������m��
  // ...
  delete ptr;  // �����������

  int size = 100;
  int* array = new int[size];  // size���m��
  // ...
  delete [] array;  // �����������m�ۂ����ꍇ��, delete�̂��Ƃ�[]�K�v

  // 2�����z��
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
  // ������10��8000���L��
  vector<string> index(108000);
  index[0] = "�G�C�{���̏�";
  index[1] = "�鉤�̋��`";
  index[2] = "�l�N���m�~�R��";
  // ...

  // �ŏ���3���̖������̑薼���o��
  PrintBookTitles(index, 3);
}

void Code9() {
  int answer = 42;
  int& ref = answer;
  //int& foo;  // ���������ĂȂ����߃G���[�ɂȂ�
}

void Code10() {
  const std::string password = "password";  // ������
  //password = "super hacker";  // const�ȃI�u�W�F�N�g�ɂ͑���ł��Ȃ����߃G���[�ɂȂ�
}

// 10^n���������ɕϊ�����
std::string KanjiOf10ToPower(int n) {
  const std::unordered_map<int, std::string> kanji_scale_map = {
    {0, "��"}, {1, "�\"}, {2, "�S"}, {3, "��"},
    {4, "��"},
    {8, "��"},
  };

  const int base = n % 4;  // ��, �\, �S, ���4��
  const int scale = n / 4 * 4; // ex) n = 5, 5 / 4 = 1, 1 * 4 = 4

  return (base == 0 && n > 0 ? "" : kanji_scale_map.at(base))  // n = 4 �Ƃ� 8 �̂Ƃ��� '��' ���ȗ�
    + (scale > 0 ? kanji_scale_map.at(scale) : "");
}

std::string ToKanjiNumbersUnder10000(unsigned long long natural_num) {
  const std::string kanji0to9[] = {
    "��",  // �_�~�[
    "��", "��", "�O", "�l", "��", "�Z", "��", "��", "��",
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
 * @brief ���P�ʂ܂ł̎��R�����������ɕϊ�����
 * @param natural_num 1�`10^12-1(999,999,999,999)�܂ł̎��R��, 0�̏ꍇ�͗�ɂȂ�
 * @return ������
 */
std::string ToKanjiNumbers(unsigned long long natural_num) {
  if (natural_num == 0) return "��";
  if (natural_num == 10000000) return "��疜";

  // �����̂��̕�����4���������ɕϊ�����
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
  if (natural_num == 0) return "��";

  /*
  ex) kanji_str = "1234"
      '4' -> "�l"
      '3' -> "�O�\"
      '2' -> "��S"
      '1' -> "��"
      digit_strs = {
        "�l", "�O�\", "��S", "��"
      }
  */
  using namespace std;
  const vector<string> digit_kanji_list = {
    "", "��", "��", "�O", "�l", "��", "�Z", "��", "��", "��",
  };
  const vector<string> scale_list = {
    "", "�\", "�S", "��"
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
  using ullong = unsigned long long;  // size_t�������n�ˑ��̂��ߕʖ���`

  const auto num_of_digit = to_string(natural_num).size();
  const auto unit_count = num_of_digit / 4 + ((num_of_digit % 4 > 0) ? 1 : 0);  // 4���̒P�ʂ������邩
  const vector<string> scale_list = {
    "", "��", "��", "��"
  };
  const auto unit_kanji_list = Func::Map(
    Func::GenerateN(vector<ullong>(), unit_count, NumUnitGen<ullong>(natural_num, 10000)),
    scale_list, vector<string>(),
    [](const ullong unit_num, const string& scale_kanji) {
      const string digit_kanji = (unit_num == 0) ? "" : NumUnder10kToKanji(unit_num);
      return (digit_kanji == "") ? "" : digit_kanji + scale_kanji;
    });
  const auto kanji_str = Func::Fold(Func::Reverse(unit_kanji_list), string(""));
  return (kanji_str == "�疜") ? "��" + kanji_str : kanji_str;
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
