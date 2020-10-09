#pragma once
#include <iostream>

struct SinglyLinkedListNode
{
	int m_data;
	SinglyLinkedListNode* m_next;
};

class SinglyLinkedList
{
#pragma region 생성자
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& other);
	~SinglyLinkedList();
#pragma endregion

#pragma region 속성
	const int Count() { return m_count; }
	SinglyLinkedListNode& Front() { return *m_head; }
#pragma endregion

#pragma region 메서드
	void Add(int value);
	void Add(SinglyLinkedListNode& node);
	void Insert(int index, int value);
	void Insert(int index, SinglyLinkedListNode& node);

	void Remove(int index, int value);
	void Remove(int index, const SinglyLinkedListNode& node);
	void Clear();

	bool Contains(int value);
	bool Contains(const SinglyLinkedListNode& node);
	SinglyLinkedListNode& Find(int value);
	SinglyLinkedListNode& FindLast(int value);

	void PrintInfo();
#pragma endregion

private:
#pragma region 변수
	size_t m_count;
	SinglyLinkedListNode* m_head;
#pragma endregion
};