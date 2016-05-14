#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

struct TsundereChara {
  TsundereChara(const std::string& name, int tsundere_power)
    : name_(name), tsundere_power_(tsundere_power) {}
  std::string name_;
  int tsundere_power_;
};

std::ostream& operator<<(std::ostream& out, const TsundereChara& chara) {
  out << chara.name_ << ", power = " << chara.tsundere_power_;
  return out;
}

int main() {
  using namespace std;
  ifstream ifs("tsundere_list.txt", ios::in);
  vector<TsundereChara> tsundere_list;
  cout << "`“Ç‚Ýž‚Ý`" << "\n";
  string line;
  while (getline(ifs, line)) {
    cout << line << "\n";
    vector<string> tokens;
    boost::split(tokens, line, boost::is_any_of(","));
    tsundere_list.emplace_back(tokens[0], stoi(tokens[1]));
  }
  ifs.close();

  cout << "\n`ƒcƒ“ƒfƒŒƒpƒ[~‡ƒ\[ƒg`" << "\n";
  vector<TsundereChara> power_sorted(tsundere_list);
  sort(power_sorted.begin(), power_sorted.end(), [](const TsundereChara& chara1, const TsundereChara& chara2) {
    return chara1.tsundere_power_ > chara2.tsundere_power_;
  });
  copy(power_sorted.cbegin(), power_sorted.cend(), ostream_iterator<TsundereChara>(cout, "\n"));

  cout << "\n`–¼‘O•\Ž¦(d•¡‚ ‚è)`" << "\n";
  vector<TsundereChara> name_sorted(tsundere_list);
  sort(name_sorted.begin(), name_sorted.end(), [](const TsundereChara& chara1, const TsundereChara& chara2) {
    return chara1.name_ < chara2.name_;
  });
  copy(name_sorted.cbegin(), name_sorted.cend(), ostream_iterator<TsundereChara>(cout, "\n"));

  cout << "\n`–¼‘O•\Ž¦(d•¡‚È‚µ)`" << "\n";
  vector<TsundereChara> uniqued(tsundere_list);
  sort(uniqued.begin(), uniqued.end(), [](const TsundereChara& chara1, const TsundereChara& chara2) {
    return chara1.name_ < chara2.name_;
  });
  auto unique_end = unique(uniqued.begin(), uniqued.end(), [](const TsundereChara& chara1, const TsundereChara& chara2) {
    return chara1.name_ == chara2.name_
      && chara1.tsundere_power_ == chara2.tsundere_power_;
  });
  copy(uniqued.begin(), unique_end, ostream_iterator<TsundereChara>(cout, "\n"));

  return 0;
}
