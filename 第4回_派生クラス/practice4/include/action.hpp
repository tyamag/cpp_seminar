#pragma once

// �s����\���N���X
struct Action {
  virtual ~Action() {}
  virtual void Invoke() = 0;
};

// �U���s��
struct Attack : public Action {
  void Invoke() override;
};

// �h��s��
struct Defense : public Action {
  void Invoke() override;
};
