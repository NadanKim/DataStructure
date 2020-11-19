#pragma once
#include "../ArrayList/ArrayList.h"

class ArrayListStack
{
public:
#pragma region 생성자
	ArrayListStack(int capacity = 10);
	ArrayListStack(const ArrayListStack& other);
#pragma endregion

#pragma region 속성
	const size_t Count() { return m_items.Count(); }
#pragma endregion

#pragma region 메서드
	void Push(int value);

	int Peek();
	int Pop();
	void Clear();

	bool Contains(int value);

	void PrintInfo();
#pragma endregion

private:
#pragma region 변수
	int m_top;
	ArrayList m_items;
#pragma endregion
};