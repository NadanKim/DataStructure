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
		SinglyLinkedListNode newNode;
		newNode.m_data = curNode->m_data;
		newNode.m_next = prevNode;
		prevNode = &newNode;
	}
	m_head = prevNode;
}
#pragma endregion

#pragma region 메서드
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