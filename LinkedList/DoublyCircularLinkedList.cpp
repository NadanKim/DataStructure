﻿#include "DoublyCircularLinkedList.h"

#pragma region 생성자
/// <summary>
/// 비어있는 DoublyCircularLinkedList를 생성한다.
/// </summary>
DoublyCircularLinkedList::DoublyCircularLinkedList()
	: m_count(0), m_head(nullptr), m_tail(nullptr), m_free(nullptr)
{
}

/// <summary>
/// 다른 DoublyCircularLinkedList가 가지고 있는 노드를 복사해 DoublyCircularLinkedList를 생성한다.
/// </summary>
/// <param name="other">기준이 될 DoublyCircularLinkedList</param>
DoublyCircularLinkedList::DoublyCircularLinkedList(const DoublyCircularLinkedList& other)
	: m_count(other.m_count), m_head(nullptr), m_tail(nullptr), m_free(nullptr)
{
	if (other.m_head == nullptr)
	{
		return;
	}

	DoublyCircularLinkedListNode* curNode{ other.m_head };

	m_head = m_tail = PopNode(curNode->m_data);
	curNode = curNode->m_next;

	while (curNode->m_prev != other.m_tail)
	{
		DoublyCircularLinkedListNode* newNode{ PopNode(curNode->m_data) };
		m_tail->m_next = newNode;
		newNode->m_prev = m_tail;
		m_tail = newNode;
		curNode = curNode->m_next;
	}

	m_head->m_prev = m_tail;
	m_tail->m_next = m_head;
}

/// <summary>
/// 메모리 누수를 막기 위해 동적 생성한 노드들을 제거한다.
/// </summary>
DoublyCircularLinkedList::~DoublyCircularLinkedList()
{
	if (m_head != nullptr)
	{
		DoublyCircularLinkedListNode* head{ m_head };
		do
		{
			DoublyCircularLinkedListNode* curNode{ m_head };
			m_head = m_head->m_next;
			delete curNode;
		} while (m_head != head);
	}

	while (m_free != nullptr)
	{
		DoublyCircularLinkedListNode* curNode{ m_free };
		m_free = m_free->m_next;
		delete curNode;
	}
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// DoublyCircularLinkedList의 시작 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void DoublyCircularLinkedList::AddFirst(int value)
{
	DoublyCircularLinkedListNode* newNode{ PopNode(value) };
	AddFirst(newNode);
}

/// <summary>
/// DoublyCircularLinkedList의 시작 위치에 지정한 노드를 추가한다.
/// </summary>
/// <param name="node">추가할 새 노드</param>
void DoublyCircularLinkedList::AddFirst(DoublyCircularLinkedListNode* node)
{
	if (node == nullptr || node->m_prev != nullptr || node->m_next != nullptr)
	{
		throw std::invalid_argument("node");
	}

	node->m_next = m_head;
	if (m_head != nullptr)
	{
		m_head->m_prev = node;
		m_head = node;
	}
	else
	{
		m_head = m_tail = node;
	}

	m_head->m_prev = m_tail;
	m_tail->m_next = m_head;

	m_count++;
}

/// <summary>
/// DoublyCircularLinkedList의 끝 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void DoublyCircularLinkedList::AddLast(int value)
{
	DoublyCircularLinkedListNode* newNode{ PopNode(value) };
	AddLast(newNode);
}

/// <summary>
/// DoublyCircularLinkedList의 끝 위치에 지정한 노드를 추가한다.
/// </summary>
/// <param name="node">추가할 새 노드</param>
void DoublyCircularLinkedList::AddLast(DoublyCircularLinkedListNode* node)
{
	if (node == nullptr || node->m_prev != nullptr || node->m_next != nullptr)
	{
		throw std::invalid_argument("node");
	}

	node->m_prev = m_tail;
	if (m_tail != nullptr)
	{
		m_tail->m_next = node;
		m_tail = node;
	}
	else
	{
		m_head = m_tail = node;
	}

	m_head->m_prev = m_tail;
	m_tail->m_next = m_head;

	m_count++;
}

/// <summary>
/// DoublyCircularLinkedList의 지정한 인덱스에 해당하는 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="index">값을 추가할 인덱스</param>
/// <param name="value">추가할 값</param>
void DoublyCircularLinkedList::Insert(size_t index, int value)
{
	DoublyCircularLinkedListNode* newNode{ PopNode(value) };
	Insert(index, newNode);
}

/// <summary>
/// DoublyCircularLinkedList의 지정한 인덱스에 해당하는 위치에 지정된 노드를 추가한다.
/// </summary>
/// <param name="index">새 노드를 추가할 인덱스</param>
/// <param name="node">추가할 새 노드</param>
void DoublyCircularLinkedList::Insert(size_t index, DoublyCircularLinkedListNode* node)
{
	if (index > m_count)
	{
		throw std::out_of_range("index");
	}

	if (node == nullptr || node->m_next != nullptr)
	{
		throw std::invalid_argument("node");
	}

	DoublyCircularLinkedListNode* curNode{ m_head };
	DoublyCircularLinkedListNode* prevNode{ m_tail };
	for (size_t i = 0; i < index; i++)
	{
		prevNode = curNode;
		curNode = curNode->m_next;
	}

	node->m_prev = prevNode;
	if (prevNode != nullptr)
	{
		prevNode->m_next = node;
	}
	node->m_next = curNode;
	if (curNode != nullptr)
	{
		curNode->m_prev = node;
	}

	if (index == 0)
	{
		m_head = node;
	}
	if (index == m_count)
	{
		m_tail = node;
	}

	m_count++;
}

/// <summary>
/// DoublyCircularLinkedList에서 가장 처음 일치한 지정된 값을 포함한 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
bool DoublyCircularLinkedList::RemoveFirst(int value)
{
	bool foundNode{ false };
	DoublyCircularLinkedListNode* curNode{ m_head };

	if (m_head != nullptr)
	{
		do
		{
			if (curNode->m_data == value)
			{
				foundNode = true;
				break;
			}
			curNode = curNode->m_next;
		} while (curNode != m_head);
	}

	if (!foundNode)
	{
		return false;
	}

	Remove(curNode);

	return true;
}

/// <summary>
/// DoublyCircularLinkedList에서 가장 처음 일치한 지정된 값을 포함한 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
bool DoublyCircularLinkedList::RemoveLast(int value)
{
	bool foundNode{ false };
	DoublyCircularLinkedListNode* curNode{ m_tail };

	if (m_tail != nullptr)
	{
		do
		{
			if (curNode->m_data == value)
			{
				foundNode = true;
				break;
			}
			curNode = curNode->m_prev;
		} while (curNode != m_tail);
	}

	if (!foundNode)
	{
		return false;
	}

	Remove(curNode);

	return true;
}

/// <summary>
/// DoublyCircularLinkedList에서 지정된 노드를 제거한다.
/// </summary>
/// <param name="node">제거할 노드</param>
void DoublyCircularLinkedList::Remove(const DoublyCircularLinkedListNode* node)
{
	if (node == nullptr)
	{
		throw std::invalid_argument("node");
	}

	bool foundNode{ false };
	DoublyCircularLinkedListNode* curNode{ m_head };
	
	if (m_head != nullptr)
	{
		do
		{
			if (curNode == node)
			{
				foundNode = true;
				break;
			}
			curNode = curNode->m_next;
		} while (curNode != m_head);
	}

	if (!foundNode)
	{
		throw std::out_of_range("node");
	}

	DoublyCircularLinkedListNode* prevNode{ curNode->m_prev };
	DoublyCircularLinkedListNode* nextNode{ curNode->m_next };
	prevNode->m_next = nextNode;
	if (prevNode == m_tail)
	{
		m_head = nextNode;
	}

	nextNode->m_prev = prevNode;
	if (nextNode == m_head)
	{
		m_tail = prevNode;
	}

	if (m_head == m_tail && m_tail == curNode)
	{
		m_head = m_tail = nullptr;
	}

	PushNode(curNode);

	m_count--;
}

/// <summary>
/// DoublyCircularLinkedList의 모든 노드를 제거한다.
/// </summary>
void DoublyCircularLinkedList::Clear()
{
	if (m_head != nullptr)
	{
		DoublyCircularLinkedListNode* head{ m_head };
		do
		{
			DoublyCircularLinkedListNode* curNode{ m_head };
			m_head = m_head->m_next;
			PushNode(curNode);
		} while (m_head != head);
	}
	m_head = m_tail = nullptr;
	m_count = 0;
}

/// <summary>
/// 지정한 값을 포함한 노드가 존재하는지 확인한다.
/// </summary>
/// <param name="value">찾을 값</param>
/// <returns>값의 존재 여부</returns>
bool DoublyCircularLinkedList::Contains(int value)
{
	if (m_head != nullptr)
	{
		DoublyCircularLinkedListNode* curNode{ m_head };
		do
		{
			if (curNode->m_data == value)
			{
				return true;
			}
			curNode = curNode->m_next;
		} while (curNode != m_head);
	}
	return false;
}

/// <summary>
/// 지정한 노드가 DoublyCircularLinkedList에 포함되는지 확인한다.
/// </summary>
/// <param name="node">찾을 노드</param>
/// <returns>노드의 포함 여부</returns>
bool DoublyCircularLinkedList::Contains(const DoublyCircularLinkedListNode* node)
{
	if (m_head != nullptr)
	{
		DoublyCircularLinkedListNode* curNode{ m_head };
		do
		{
			if (curNode == node)
			{
				return true;
			}
			curNode = curNode->m_next;
		} while (curNode != m_head);
	}
	return false;
}

/// <summary>
/// 지정한 값을 포함하는 가장 처음 일치하는 노드를 반환한다.
/// </summary>
/// <param name="value">찾을 값</param>
/// <returns>지정한 값을 포함하는 노드(없는 경우: nullptr)</returns>
DoublyCircularLinkedListNode* DoublyCircularLinkedList::Find(int value)
{
	if (m_head != nullptr)
	{
		DoublyCircularLinkedListNode* curNode{ m_head };
		do
		{
			if (curNode->m_data == value)
			{
				return curNode;
			}
			curNode = curNode->m_next;
		} while (curNode != m_head);
	}
	return nullptr;
}

/// <summary>
/// 지정한 값을 포함하는 가장 마지막 일치하는 노드를 반환한다.
/// </summary>
/// <param name="value">찾을 값</param>
/// <returns>지정한 값을 포함하는 노드(없는 경우: nullptr)</returns>
DoublyCircularLinkedListNode* DoublyCircularLinkedList::FindLast(int value)
{
	if (m_tail != nullptr)
	{
		DoublyCircularLinkedListNode* curNode{ m_tail };
		do
		{
			if (curNode->m_data == value)
			{
				return curNode;
			}
			curNode = curNode->m_prev;
		} while (curNode != m_tail);
	}
	return nullptr;
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void DoublyCircularLinkedList::PrintInfo(bool isPrintReverse)
{
	std::cout << "Count: " << m_count << std::endl;
	std::cout << "Nodes: ";

	DoublyCircularLinkedListNode* curNode{ isPrintReverse ? m_tail : m_head };
	if (curNode != nullptr)
	{
		do
		{
			std::cout << curNode->m_data << ", ";
			curNode = isPrintReverse ? curNode->m_prev : curNode->m_next;
		} while (isPrintReverse ? curNode->m_next != m_head : curNode->m_prev != m_tail);
		std::cout << std::endl;
	}
}
#pragma endregion

#pragma region Class Util
/// <summary>
/// 자유 공간 리스트에서 노드를 가져오거나 새로 생성한다.
/// </summary>
/// <param name="value">노드 생성시 초기값</param>
/// <returns>새 노드</returns>
DoublyCircularLinkedListNode* DoublyCircularLinkedList::PopNode(int value)
{
	DoublyCircularLinkedListNode* newNode{ nullptr };
	if (m_free == nullptr)
	{
		newNode = new DoublyCircularLinkedListNode(value);
	}
	else
	{
		newNode = m_free;
		m_free = m_free->m_next;

		newNode->m_data = value;
		newNode->m_next = nullptr;
	}

	return newNode;
}

/// <summary>
/// 자유 공간 리스트에 제거된 노드를 저장한다.
/// </summary>
/// <param name="node">제거된 노드</param>
void DoublyCircularLinkedList::PushNode(DoublyCircularLinkedListNode* node)
{
	node->m_prev = nullptr;
	node->m_next = m_free;
	m_free = node;
}
#pragma endregion