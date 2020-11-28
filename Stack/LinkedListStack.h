#pragma once
#include "../LinkedList/SinglyLinkedList.h"

class LinkedListStack
{
public:
#pragma region 생성자
	LinkedListStack();
	LinkedListStack(const LinkedListStack& other);
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
	SinglyLinkedList m_items;
#pragma endregion
};