#pragma once
#include "DxLib.h"

/// <summary>
/// �y���[�U��`:static�z�y�ˑ�:Dxlib�z
/// keybord�̂�
/// </summary>
class MyKeyInput
{
private:
	/*static�����o�ϐ�*/
	//���ꂼ���Key�̓��̓t���[����
	// ��`�����s���A���Ԃ̓O���[�o���ō쐬
	static int m_keyFrame[];
public:
	
	//
	MyKeyInput();
	~MyKeyInput();


};

// �ÓI�����o�ϐ��̎��ԍ쐬
int MyKeyInput::m_keyFrame[256];
