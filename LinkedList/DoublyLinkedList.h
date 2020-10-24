#pragma once
#include <xutility>
#include <iostream>

struct DoublyLinkedListNode
{
	DoublyLinkedListNode() {}
	DoublyLinkedListNode(int value) { m_data = value; }

	int m_data{ 0 };
	DoublyLinkedListNode* m_prev{ nullptr };
	DoublyLinkedListNode* m_next{ nullptr };
};

class DoublyLinkedList
{
public:
#pragma region 생성자
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other);
	~DoublyLinkedList();
#pragma endregion

#pragma region 속성
	const int Count() { return m_count; }
	DoublyLinkedListNode& First() { return *m_head; }
	DoublyLinkedListNode& Last() { return *m_tail; }
#pragma endregion

#pragma region 메서드
	void AddFirst(int value);
	void AddFirst(DoublyLinkedListNode* node);
	void AddLast(int value);
	void AddLast(DoublyLinkedListNode* node);
	void Insert(int index, int value);
	void Insert(int index, DoublyLinkedListNode* node);

	bool RemoveFirst(int value);
	bool RemoveLast(int value);
	void Remove(const DoublyLinkedListNode* node);
	void Clear();

	bool Contains(int value);
	bool Contains(const DoublyLinkedListNode* node);
	DoublyLinkedListNode* Find(int value);
	DoublyLinkedListNode* FindLast(int value);

	void PrintInfo(bool isPrintReverse = false);
#pragma endregion

private:
#pragma region Class Util
	DoublyLinkedListNode* PopNode(int value);
	void PushNode(DoublyLinkedListNode* node);
#pragma endregion
	
private:
#pragma region 변수
	size_t m_count;
	DoublyLinkedListNode* m_head;
	DoublyLinkedListNode* m_tail;
	DoublyLinkedListNode* m_free;
#pragma endregion
};