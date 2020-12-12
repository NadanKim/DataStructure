#pragma once
#include "../ArrayList/ArrayList.h"

class LinkedListQueue
{
public:
#pragma region 생성자
	LinkedListQueue(int capacity = 10);
	LinkedListQueue(const LinkedListQueue& other);
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
	ArrayList m_items;
#pragma endregion
};