#include "action.hpp"
#include "actor.hpp"

int main() {
  // actionのデータ
  const std::vector<Action*> data_action = {
    new Attack()
    , new Defense()
  };

  Actor actor;
  // actorに行動をセット
  // 攻撃と防御ができるようにする
  const int act_ids[] = {0, 1};
  for (auto act_id : act_ids)
    actor.AddAction(data_action[act_id]);
  // 行動の実行
  int selected_act_id = 0;
  actor.InvokeAction(selected_act_id);
  selected_act_id = 1;
  actor.InvokeAction(selected_act_id);

  // データの削除
  // スマートポインタがあれば...(次週やる予定)
  for (auto action : data_action) delete action;

  return 0;
}
