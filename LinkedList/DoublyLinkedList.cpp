#include "DoublyLinkedList.h"

#pragma region 생성자
/// <summary>
/// 비어있는 DoublyLinkedList를 생성한다.
/// </summary>
DoublyLinkedList::DoublyLinkedList()
	: m_count(0), m_head(nullptr), m_tail(nullptr), m_free(nullptr)
{
}

/// <summary>
/// 다른 SinglyLinkedList가 가지고 있는 노드를 복사해 SinglyLinkedList를 생성한다.
/// </summary>
/// <param name="other">기준이 될 DoublyLinkedList</param>
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
	: m_count(other.m_count), m_free(nullptr)
{
	DoublyLinkedListNode* curNode{ other.m_head };

	m_head = m_tail = PopNode(curNode->m_data);
	curNode = curNode->m_next;

	while (curNode != nullptr)
	{
		DoublyLinkedListNode* newNode{ PopNode(curNode->m_data) };
		m_tail->m_next = newNode;
		newNode->m_prev = m_tail;
		m_tail = newNode;
		curNode = curNode->m_next;
	}
}

/// <summary>
/// 메모리 누수를 막기 위해 동적 생성한 노드들을 제거한다.
/// </summary>
DoublyLinkedList::~DoublyLinkedList()
{
	while (m_head->m_next != nullptr)
	{
		m_head = m_head->m_next;
		delete m_head->m_prev;
	}
	delete m_head;

	while (m_free->m_next != nullptr)
	{
		m_free = m_free->m_next;
		delete m_free->m_prev;
	}
	delete m_free;
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void DoublyLinkedList::PrintInfo(bool isPrintReverse)
{
	DoublyLinkedListNode* curNode{ isPrintReverse ? m_tail : m_head };
	while (curNode != nullptr)
	{
		std::cout << curNode->m_data << ", ";
		curNode = isPrintReverse ? curNode->m_prev : curNode->m_next;
	}
	std::cout << std::endl;
}
#pragma endregion

#pragma region Class Util
/// <summary>
/// 자유 공간 리스트에서 노드를 가져오거나 새로 생성한다.
/// </summary>
/// <param name="value">노드 생성시 초기값</param>
/// <returns>새 노드</returns>
DoublyLinkedListNode* DoublyLinkedList::PopNode(int value)
{
	DoublyLinkedListNode* newNode{ nullptr };
	if (m_free == nullptr)
	{
		newNode = new DoublyLinkedListNode(value);
	}
	else
	{
		newNode = m_free;
		newNode->m_data = value;
		newNode->m_prev = newNode->m_next = nullptr;

		m_free = m_free->m_next;
	}

	return newNode;
}

/// <summary>
/// 자유 공간 리스트에 제거된 노드를 저장한다.
/// </summary>
/// <param name="node">제거된 노드</param>
void DoublyLinkedList::PushNode(DoublyLinkedListNode* node)
{
	m_free->m_prev = node;
	node->m_next = m_free;
	m_free = node;
}
#pragma endregion