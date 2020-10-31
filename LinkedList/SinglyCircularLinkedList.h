#pragma once
#include <xutility>
#include <iostream>

struct SinglyCircularLinkedListNode
{
	SinglyCircularLinkedListNode() {}
	SinglyCircularLinkedListNode(int value) { m_data = value; }

	int m_data{ 0 };
	SinglyCircularLinkedListNode* m_next{ nullptr };
};

class SinglyCircularLinkedList
{
public:
#pragma region 생성자
	SinglyCircularLinkedList();
	SinglyCircularLinkedList(const SinglyCircularLinkedList& other);
	~SinglyCircularLinkedList();
#pragma endregion

#pragma region 속성
	const int Count() { return m_count; }
	SinglyCircularLinkedListNode& Front() { return *m_head; }
#pragma endregion

#pragma region 메서드
	void Add(int value);
	void Add(SinglyCircularLinkedListNode* node);
	void Insert(size_t index, int value);
	void Insert(size_t index, SinglyCircularLinkedListNode* node);

	bool Remove(int value);
	void Remove(const SinglyCircularLinkedListNode* node);
	void Clear();

	bool Contains(int value);
	bool Contains(const SinglyCircularLinkedListNode* node);
	SinglyCircularLinkedListNode* Find(int value);
	SinglyCircularLinkedListNode* FindLast(int value);

	void PrintInfo();
#pragma endregion

private:
#pragma region Class Util
	SinglyCircularLinkedListNode* PopNode(int value);
	void PushNode(SinglyCircularLinkedListNode* node);

	void UpdateHead(SinglyCircularLinkedListNode* node);
#pragma endregion
	
private:
#pragma region 변수
	size_t m_count;
	SinglyCircularLinkedListNode* m_head;
	SinglyCircularLinkedListNode* m_free;
#pragma endregion
};