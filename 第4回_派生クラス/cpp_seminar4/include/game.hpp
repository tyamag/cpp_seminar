#pragma once

// Scene�̕���include Game����, �������ł�include Scene�Ƃ����,
// Scene��, �܂��錾����ĂȂ�Game�����悤�Ƃ���
// Game�̕���, �܂��錾����ĂȂ�Scene�����悤�Ƃ���
// ����, �f�b�h���b�N���ۂ����Ƃ��N���Ă��܂�
// ����������邽��, �O���錾���s��, �C���N���[�h������
// �R���p�C����, ���������N���X�����邼,�@�Ƌ�����
class Scene;

class Game {
public:
  Game();
  ~Game();
  void Start();
  void ChangeScene(Scene* scene);

private:
  Scene* scene_;
};
