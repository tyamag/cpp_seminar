#pragma once

#include "scene.hpp"

class SceneTitle : public Scene {  // Scene�N���X���p��
public:
  SceneTitle() {}
  ~SceneTitle() {}

  // override �Ə������ƂŊ֐����I�[�o�[���C�h���Ă��邱�Ƃ𖾎��ł���
  // ���ʂ�, �w�b�_(.h �� .hpp)�ł͊֐��͐錾�������Ă�����,
  // .c �� .cpp �t�@�C���ɒ�`������
  void Update(Game& game) override;
};
