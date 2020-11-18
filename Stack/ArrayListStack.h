#pragma once
#include <xutility>
#include <iostream>

class ArrayListStack
{
public:
#pragma region 생성자
	ArrayListStack(int capacity = 10);
	ArrayListStack(const ArrayListStack& other);
#pragma endregion

#pragma region 속성
	const size_t Count() { return m_count; }
#pragma endregion

#pragma region 메서드
	void Push(int value);

	int Peek();
	int Pop();
	void Clear();

	bool Contains(int value);
#pragma endregion

private:
#pragma region 변수
	size_t m_count;
	int* m_items;
#pragma endregion
};