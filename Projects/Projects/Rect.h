#pragma once
#include "Vec2.h"

class Rect	// ��`�i�l�p�j�̏����擾���Ă���Ă���
{
public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="x">���S���W�FX</param>
	/// <param name="y">���S���W�FY</param>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	void Init(float x, float y, float width, float height)
	{
		m_pos.x = x;
		m_pos.y = y;
		m_width  = width;
		m_height = height;
	}
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="pos">���S���W</param>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	void Init(const Vec2& pos, float width, float height)
	{
		m_pos = pos;
		m_width = width;
		m_height = height;
	}

	/// <summary>
	/// ���S���X�V
	/// </summary>
	/// <param name="x">X���W</param>
	/// <param name="y">Y���W</param>
	void UpdateCenter(float x, float y)
	{
		m_pos.x = x;
		m_pos.y = y;
	}
	/// <summary>
	/// ���S���X�V
	/// </summary>
	/// <param name="pos">���W</param>
	void UpdateCenter(const Vec2& pos)
	{
		m_pos = pos;
	}

	/// <summary>
	/// �������擾
	/// </summary>
	/// <returns>x - widht * 0.5f</returns>
	float GetLeft() const
	{
		return m_pos.x - m_width * 0.5f;
	}
	/// <summary>
	/// �E�����擾
	/// </summary>
	/// <returns>x - widht * 0.5f</returns>
	float GetRight() const
	{
		return m_pos.x + m_width * 0.5f;
	}
	/// <summary>
	/// �㑤���擾
	/// </summary>
	/// <returns>y - hegiht * 0.5f</returns>
	float GetTop() const
	{
		return m_pos.y - m_height * 0.5f;
	}
	/// <summary>
	/// �������擾
	/// </summary>
	/// <returns>y + hegiht * 0.5f</returns>
	float GetBottom() const
	{
		return m_pos.y + m_height * 0.5f;
	}

private:
	// ���S
	Vec2 m_pos;
	// ����̕��E����
	float m_width;
	float m_height;
};