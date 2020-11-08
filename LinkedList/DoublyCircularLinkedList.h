#pragma once
#include <xutility>
#include <iostream>

struct DoublyCircularLinkedListNode
{
	DoublyCircularLinkedListNode() {}
	DoublyCircularLinkedListNode(int value) { m_data = value; }

	int m_data{ 0 };
	DoublyCircularLinkedListNode* m_prev{ nullptr };
	DoublyCircularLinkedListNode* m_next{ nullptr };
};

class DoublyCircularLinkedList
{
public:
#pragma region 생성자
	DoublyCircularLinkedList();
	DoublyCircularLinkedList(const DoublyCircularLinkedList& other);
	~DoublyCircularLinkedList();
#pragma endregion

#pragma region 속성
	const size_t Count() { return m_count; }
	DoublyCircularLinkedListNode& First() { return *m_head; }
	DoublyCircularLinkedListNode& Last() { return *m_tail; }
#pragma endregion

#pragma region 메서드
	void AddFirst(int value);
	void AddFirst(DoublyCircularLinkedListNode* node);
	void AddLast(int value);
	void AddLast(DoublyCircularLinkedListNode* node);
	void Insert(size_t index, int value);
	void Insert(size_t index, DoublyCircularLinkedListNode* node);

	bool RemoveFirst(int value);
	bool RemoveLast(int value);
	void Remove(const DoublyCircularLinkedListNode* node);
	void Clear();

	bool Contains(int value);
	bool Contains(const DoublyCircularLinkedListNode* node);
	DoublyCircularLinkedListNode* Find(int value);
	DoublyCircularLinkedListNode* FindLast(int value);

	void PrintInfo(bool isPrintReverse = false);
#pragma endregion

private:
#pragma region Class Util
	DoublyCircularLinkedListNode* PopNode(int value);
	void PushNode(DoublyCircularLinkedListNode* node);
#pragma endregion
	
private:
#pragma region 변수
	size_t m_count;
	DoublyCircularLinkedListNode* m_head;
	DoublyCircularLinkedListNode* m_tail;
	DoublyCircularLinkedListNode* m_free;
#pragma endregion
};