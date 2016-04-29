#include <algorithm>
#include <numeric>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>

void code1() {
  // C����ł̕�����̒����擾
  const char* c_str = "I like C.";
  std::cout << c_str << ": length = " << std::strlen(c_str) << "\n";  // �֐����g��
                                                                      // std::string�̗��p
  const std::string cpp_str = "I prefer C++.";
  std::cout << cpp_str << ": length = " << cpp_str.length() << "\n"; // string�̃����o�֐����g��
}

// �v���C���[�L�����N���X
class Player {
public:
  Player(const std::string& name, int hp)
    : name_(name), hp_(hp) {
    /*
    �����o�������q���X�g���g���ꍇ
    name_, hp_ ��, ���ꂼ�� name, hp �ŏ����������
    */
  }
  /*
  Player(const std::string& name, int hp) {
    //�����o�������q���X�g���g��Ȃ��ꍇ
    //�����o name_, hp_ �͂܂��K���Ȓl�ŏ����������
    //ex) name_(""); hp_(??);
    //���̌�, �l���������邽��, �����
    
    name_ = name;
    hp_ = hp;
  }
  */
  // �f�X�g���N�^
  ~Player() {}
  // �Q�b�^�[
  const std::string& name() const { return name_; }
  int hp() const { return hp_; }
  // �Z�b�^�[
  void set_hp(int hp) { hp_ = hp; }

private:
  std::string name_;  // ���O
  int hp_;            // �q�b�g�|�C���g
};

void code2() {
  Player player("���g", 10);
  std::cout << player.name() << " hp = " << player.hp() << "\n";
  player.set_hp(1);
  std::cout << player.name() << " hp = " << player.hp() << "\n";
}

void code3() {
  std::vector<int> i_vec = {1, 2, 3};                // int���i�[����vector
  std::vector<double> d_vec = {1.0, 1.414, 1.7325};  // double���i�[����vector
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
    "�ӂ邢����", "���킸�Ƃт���", "�݂��̂���"
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
    "�ӂ邢����", "���킸�Ƃт���", "�݂��̂���"
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
  std::vector<int> i_vec;  // ���I�z�� vector
  i_vec.push_back(666);  // vector�̖����ɗv�f��ǉ�
  i_vec.push_back(9999);
  for (const auto& elem : i_vec) std::cout << elem << ", ";
  std::cout << "\n";

  std::list<int> i_list; // �o�������X�g list
  i_list.push_back(111);  // list�̖����ɗv�f��ǉ�
  i_list.insert(i_list.begin(), {0, 1}); // list�̐擪�ɗv�f��}��
  for (const auto& elem : i_list) std::cout << elem << ", ";
  std::cout << "\n";

  // ��i���Ƃ��̍�i�ɓo�ꂷ��c���f���L�����̃n�b�V���}�b�v
  std::unordered_map<std::string, std::string> tundere_map;
  tundere_map["�Ƃ�h���I"] = "������";
  tundere_map["���u���C�u�I"] = "���ؖ�^�P";
  for (const auto& pair : tundere_map) {
    std::cout << pair.first << " -> " << pair.second << "\n";
  }
}

void code8() {
  std::vector<int> i_vec = {1, 2, 3};
  // 1. �Y�����őS����(�f�[�^�\���Ɉˑ�)
  for (size_t i = 0; i < i_vec.size(); ++i) std::cout << i_vec[i] << " ";
  std::cout << "\n";
  // 2. �C�e���[�^�őS����
  for (auto iter = i_vec.begin(); iter != i_vec.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << "\n";
  // 3. �͈�for��(�ÖٓI�ɃC�e���[�^�𗘗p ... 2�Ɠ���)
  for (auto num : i_vec) std::cout << num << " ";
  std::cout << "\n";
}

void code9() {
  std::vector<int> i_vec = {3, 2, 1};
  // vector�̍��v���v�Z
  std::cout << std::accumulate(i_vec.begin(), i_vec.end(), 0) << "\n";
  // vector�������Ƀ\�[�g
  std::sort(i_vec.begin(), i_vec.end());
  for (auto num : i_vec) std::cout << num << " ";
  std::cout << "\n";
}

int main() {
  std::vector<int> i_vec = {3, 2, 1};
  // vector�̍��v���v�Z
  std::cout << std::accumulate(i_vec.begin(), i_vec.end(), 0) << "\n";
  // vector�������Ƀ\�[�g
  std::sort(i_vec.begin(), i_vec.end());
  for (auto num : i_vec) std::cout << num << " ";
  std::cout << "\n";

  return 0;
}
