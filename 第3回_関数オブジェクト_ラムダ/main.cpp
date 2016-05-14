#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct TsundereChara {
  TsundereChara(const std::string& name, int tsundere_power)
    : name_(name), tsundere_power_(tsundere_power) {}

  // �����o�֐��Ƃ��Ĕ�r���Z�q���`
  bool operator<(const TsundereChara& other) const {  // �� const�Ȋ֐��ɂ��Ȃ��ƃG���[�ɂȂ�
    return tsundere_power_ < other.tsundere_power_;
  }

  int tsundere_power() const { return tsundere_power_; }
  std::string name_;
  int tsundere_power_;
};

// �O���[�o���֐��Ƃ���TsundereChara�̃c���f���x��r���Z�q���`
/*
bool operator<(const TsundereChara& a, const TsundereChara& b) {
  return a.tsundere_power_ < b.tsundere_power_;
}
*/

void Code1() {
  const TsundereChara yui("�Î��B", 3);
  const TsundereChara hinagiku("�j�q�i�M�N", 9);
  std::cout << "Q. " << yui.name_ << "�@�� " << hinagiku.name_
    << " ���Ăǂ��������c���f�����Ă�̂�?\n";
  // ��`���� < ���Z�q�𗘗p
  const auto& greater = (yui < hinagiku) ? hinagiku : yui;  // std::max(yui, hinagiku)�ł���
  std::cout << "A. " << greater.name_ << " ���]!\n";
}

// TsundereChara��r�p�֐��I�u�W�F�N�g
struct TsunderePowerComp {
  bool operator()(const TsundereChara& a, const TsundereChara& b) {
    return a.tsundere_power_ < b.tsundere_power_;
  }
};

void Code2() {
  const TsundereChara yui("�Î��B", 3);
  const TsundereChara hinagiku("�j�q�i�M�N", 9);
  std::cout << "Q. " << yui.name_ << "�@�� " << hinagiku.name_
    << " ���Ăǂ��������c���f�����Ă�̂�?\n";
  // �֐��I�u�W�F�N�g�𗘗p
  const auto& greater = std::max(yui, hinagiku, TsunderePowerComp());
  std::cout << "A. " << greater.name_ << " ���]!\n";
}

void Code3() {
  // �����Z�̊֐��I�u�W�F�N�g
  std::plus<int> i_plus;
  const int a = 1;
  const int b = 2;
  std::cout << i_plus(a, b) << "\n";

  // 2��vector��v�f���Ƃɑ���
  const std::vector<int> nums = {1, 2, 3, 4};
  const std::vector<int> nums2 = {10, 100, 1000, 10000};
  std::vector<int> result(nums.size());
  std::transform(nums.cbegin(), nums.cend(), nums2.cbegin(), result.begin(), i_plus);
  for (auto num : result) std::cout << num << ", ";
  std::cout << "\n";
}

template<class T>
const T& MyMax(const T& a, const T& b, bool (*Cmp)(const T&, const T&)) {  // �֐��|�C���^�̎w�肪�ώG
  return Cmp(a, b) ? b : a;
}

bool TsundereComp(const TsundereChara& a, const TsundereChara& b) {
  return a.tsundere_power_ < b.tsundere_power_;
}

void Code4() {
  const TsundereChara yui("�Î��B", 3);
  const TsundereChara hinagiku("�j�q�i�M�N", 9);
  std::cout << "Q. " << yui.name_ << "�@�� " << hinagiku.name_
    << " ���Ăǂ��������c���f�����Ă�̂�?\n";
  const auto& greater = MyMax(yui, hinagiku, &TsundereComp);
  std::cout << "A. " << greater.name_ << " ���]!\n";
}

void Code5() {
  const TsundereChara yui("�Î��B", 3);
  const TsundereChara hinagiku("�j�q�i�M�N", 9);
  std::cout << "Q. " << yui.name_ << "�@�� " << hinagiku.name_
    << " ���Ăǂ��������c���f�����Ă�̂�?\n";
  // �����_���̗��p
  // �����̊֐��I�u�W�F�N�g������Ă�
  /*
  [](const TsundereChara& a, const TsundereChara& b) { return a.tsundere_power_ < b.tsundere_power_; }
  ��,
  struct ??? {
    bool operator()(const TsundereChara& a, const TsundereChara& b) {
      return a.tsundere_power_ < b.tsundere_power_;
    }
  };
  �̂悤�Ȋ֐��I�u�W�F�N�g�𐶐�����
  */
  const auto& greater = std::max(yui, hinagiku, [](const TsundereChara& a, const TsundereChara& b) {
    return a.tsundere_power_ < b.tsundere_power_;
  });
  std::cout << "A. " << greater.name_ << " ���]!\n";
}

void Code6() {
  int count = 1;
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  // �����_���ŕϐ�(count)���Q��
  std::for_each(nums.begin(), nums.end(), [&count](int num) {
    if (num % 2 == 0) count++;
  });
  std::cout << count << "\n";
}

int main() {
  Code6();

  return 0;
}
