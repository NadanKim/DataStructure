#include "SinglyLinkedList.h"

#pragma region 생성자
/// <summary>
/// 비어있는 SinglyLinkedList를 생성한다.
/// </summary>
SinglyLinkedList::SinglyLinkedList()
	: m_count(0), m_head(nullptr)
{
}

/// <summary>
/// 다른 SinglyLinkedList가 가지고 있는 노드를 복사해 SinglyLinkedList를 생성한다.
/// </summary>
/// <param name="other">기준이 될 SinglyLinkedList</param>
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other)
	: m_count(other.m_count)
{
	SinglyLinkedListNode* prevNode = nullptr;
	SinglyLinkedListNode* curNode = other.m_head;
	while (curNode != nullptr)
	{
		SinglyLinkedListNode newNode(curNode->m_data);
		newNode.m_next = prevNode;
		prevNode = &newNode;
	}
	m_head = prevNode;
}

/// <summary>
/// 메모리 누수를 막기 위해 동적 생성한 노드들을 제거한다.
/// </summary>
SinglyLinkedList::~SinglyLinkedList()
{
	while (m_head != nullptr)
	{
		SinglyLinkedListNode* curNode = m_head;
		m_head = m_head->m_next;
		delete curNode;
	}
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// SinglyLinkedList의 시작 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void SinglyLinkedList::Add(int value)
{
	SinglyLinkedListNode* newNode = new SinglyLinkedListNode(value);
	Add(newNode);
}

/// <summary>
/// SinglyLinkedList의 시작 위치에 지정한 노드를 추가한다.
/// </summary>
/// <param name="node">추가할 새 노드</param>
void SinglyLinkedList::Add(SinglyLinkedListNode* node)
{
	if (node == nullptr || node->m_next != nullptr)
	{
		throw std::invalid_argument("node");
	}

	node->m_next = m_head;
	m_head = node;

	m_count++;
}

/// <summary>
/// SinglyLinkedList의 지정한 인덱스에 해당하는 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="index">값을 추가할 인덱스</param>
/// <param name="value">추가할 값</param>
void SinglyLinkedList::Insert(int index, int value)
{
	SinglyLinkedListNode* newNode = new SinglyLinkedListNode(value);
	Insert(index, newNode);
}

/// <summary>
/// SinglyLinkedList의 지정한 인덱스에 해당하는 위치에 지정된 노드를 추가한다.
/// </summary>
/// <param name="index">새 노드를 추가할 인덱스</param>
/// <param name="node">추가할 새 노드</param>
void SinglyLinkedList::Insert(int index, SinglyLinkedListNode* node)
{
	if (index < 0)
	{
		throw std::out_of_range("index");
	}

	if (node == nullptr || node->m_next != nullptr)
	{
		throw std::invalid_argument("node");
	}

	if (index > m_count)
	{
		index = m_count;
	}

	SinglyLinkedListNode* prevNode = nullptr;
	SinglyLinkedListNode* curNode = m_head;
	while (index--)
	{
		prevNode = curNode;
		curNode = curNode->m_next;
	}

	node->m_next = curNode;

	if (prevNode == nullptr)
	{
		m_head = node;
	}
	else
	{
		prevNode->m_next = node;
	}

	m_count++;
}

void SinglyLinkedList::PrintInfo()
{
	std::cout << "Count: " << m_count << std::endl;
	std::cout << "Nodes: ";
	SinglyLinkedListNode* curNode = m_head;
	while (curNode != nullptr)
	{
		std::cout << curNode->m_data << ", ";
		curNode = curNode->m_next;
	}
	std::cout << std::endl;
}
#pragma endregion