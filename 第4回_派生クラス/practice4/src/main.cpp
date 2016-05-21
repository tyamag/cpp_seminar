#include "action.hpp"
#include "actor.hpp"

int main() {
  // action�̃f�[�^
  const std::vector<Action*> data_action = {
    new Attack()
    , new Defense()
  };

  Actor actor;
  // actor�ɍs�����Z�b�g
  // �U���Ɩh�䂪�ł���悤�ɂ���
  const int act_ids[] = {0, 1};
  for (auto act_id : act_ids)
    actor.AddAction(data_action[act_id]);
  // �s���̎��s
  int selected_act_id = 0;
  actor.InvokeAction(selected_act_id);
  selected_act_id = 1;
  actor.InvokeAction(selected_act_id);

  // �f�[�^�̍폜
  // �X�}�[�g�|�C���^�������...(���T���\��)
  for (auto action : data_action) delete action;

  return 0;
}
