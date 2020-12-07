#pragma once
#include "../ArrayList/ArrayList.h"

class ArrayListQueue
{
public:
#pragma region 생성자
	ArrayListQueue(int capacity = 10);
	ArrayListQueue(const ArrayListQueue& other);
#pragma endregion

#pragma region 속성
	const size_t Count() { return m_items.Count(); }
#pragma endregion

#pragma region 메서드
	void Enqueue(int value);

	int Peek();
	int Dequeue();
	void Clear();

	bool Contains(int value);

	void PrintInfo();
#pragma endregion

private:
#pragma region 변수
	size_t m_rear;
	ArrayList m_items;
#pragma endregion
};