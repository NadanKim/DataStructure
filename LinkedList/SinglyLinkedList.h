#pragma once
#include <xutility>
#include <iostream>

struct SinglyLinkedListNode
{
	SinglyLinkedListNode() {}
	SinglyLinkedListNode(int value) { m_data = value; }

	int m_data{ 0 };
	SinglyLinkedListNode* m_next{ nullptr };
};

class SinglyLinkedList
{
public:
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
	void Add(SinglyLinkedListNode* node);
	void Insert(size_t index, int value);
	void Insert(size_t index, SinglyLinkedListNode* node);

	bool Remove(int value);
	void Remove(const SinglyLinkedListNode* node);
	void Clear();

	bool Contains(int value);
	bool Contains(const SinglyLinkedListNode* node);
	SinglyLinkedListNode* Find(int value);
	SinglyLinkedListNode* FindLast(int value);

	void PrintInfo();
#pragma endregion

private:
#pragma region Class Util
	SinglyLinkedListNode* PopNode(int value);
	void PushNode(SinglyLinkedListNode* node);
#pragma endregion
	
private:
#pragma region 변수
	size_t m_count;
	SinglyLinkedListNode* m_head;
	SinglyLinkedListNode* m_free;
#pragma endregion
};