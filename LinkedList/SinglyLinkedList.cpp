#include "SinglyLinkedList.h"

#pragma region 생성자
/// <summary>
/// 비어있는 SinglyLinkedList를 생성한다.
/// </summary>
SinglyLinkedList::SinglyLinkedList()
	: m_count(0), m_head(nullptr), m_free(nullptr)
{
}

/// <summary>
/// 다른 SinglyLinkedList가 가지고 있는 노드를 복사해 SinglyLinkedList를 생성한다.
/// </summary>
/// <param name="other">기준이 될 SinglyLinkedList</param>
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other)
	: m_count(other.m_count), m_free(nullptr)
{
	SinglyLinkedListNode* curNode{ other.m_head };
	SinglyLinkedListNode* prevNode{ PopNode(curNode->m_data) };

	m_head = prevNode;
	curNode = curNode->m_next;

	while (curNode != nullptr)
	{
		SinglyLinkedListNode* newNode{ PopNode(curNode->m_data) };
		prevNode->m_next = newNode;
		prevNode = newNode;
		curNode = curNode->m_next;
	}
}

/// <summary>
/// 메모리 누수를 막기 위해 동적 생성한 노드들을 제거한다.
/// </summary>
SinglyLinkedList::~SinglyLinkedList()
{
	while (m_head != nullptr)
	{
		SinglyLinkedListNode* curNode{ m_head };
		m_head = m_head->m_next;
		delete curNode;
	}

	while (m_free != nullptr)
	{
		SinglyLinkedListNode* curNode{ m_free };
		m_free = m_free->m_next;
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
	SinglyLinkedListNode* newNode{ PopNode(value) };
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
	SinglyLinkedListNode* newNode{ PopNode(value) };
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

	SinglyLinkedListNode* prevNode{ nullptr };
	SinglyLinkedListNode* curNode{ m_head };
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

/// <summary>
/// SinglyLinkedList에서 가장 처음 일치한 지정된 값을 포함한 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
bool SinglyLinkedList::Remove(int value)
{
	SinglyLinkedListNode* curNode{ m_head };
	while (curNode != nullptr)
	{
		if (curNode->m_data == value)
		{
			break;
		}
		curNode = curNode->m_next;
	}

	if (curNode == nullptr)
	{
		return false;
	}

	Remove(curNode);

	return true;
}

/// <summary>
/// SinglyLinkedList에서 지정된 노드를 제거한다.
/// </summary>
/// <param name="node">제거할 노드</param>
void SinglyLinkedList::Remove(const SinglyLinkedListNode* node)
{
	if (node == nullptr)
	{
		throw std::invalid_argument("node");
	}

	SinglyLinkedListNode* prevNode{ nullptr };
	SinglyLinkedListNode* curNode{ m_head };
	while (curNode != nullptr)
	{
		if (curNode == node)
		{
			break;
		}
		prevNode = curNode;
		curNode = curNode->m_next;
	}

	if (curNode == nullptr)
	{
		throw std::out_of_range("node");
	}

	if (prevNode == nullptr)
	{
		m_head = curNode->m_next;
	}
	else
	{
		prevNode->m_next = curNode->m_next;
	}
	PushNode(curNode);

	m_count--;
}

/// <summary>
/// SinglyLinkedList의 모든 노드를 제거한다.
/// </summary>
void SinglyLinkedList::Clear()
{
	while (m_head != nullptr)
	{
		SinglyLinkedListNode* curNode{ m_head };
		m_head = m_head->m_next;
		PushNode(curNode);
	}
	m_count = 0;
}

/// <summary>
/// 지정한 값을 포함한 노드가 존재하는지 확인한다.
/// </summary>
/// <param name="value">찾을 값</param>
/// <returns>값의 존재 여부</returns>
bool SinglyLinkedList::Contains(int value)
{
	SinglyLinkedListNode* curNode{ m_head };
	while (curNode != nullptr)
	{
		if (curNode->m_data == value)
		{
			return true;
		}
		curNode = curNode->m_next;
	}
	return false;
}

/// <summary>
/// 지정한 노드가 SinglyLinkedList에 포함되는지 확인한다.
/// </summary>
/// <param name="node">찾을 노드</param>
/// <returns>노드의 포함 여부</returns>
bool SinglyLinkedList::Contains(const SinglyLinkedListNode* node)
{
	SinglyLinkedListNode* curNode{ m_head };
	while (curNode != nullptr)
	{
		if (curNode == node)
		{
			return true;
		}
		curNode = curNode->m_next;
	}
	return false;
}

/// <summary>
/// 지정한 값을 포함하는 가장 처음 일치하는 노드를 반환한다.
/// </summary>
/// <param name="value">찾을 값</param>
/// <returns>지정한 값을 포함하는 노드(없는 경우: nullptr)</returns>
SinglyLinkedListNode* SinglyLinkedList::Find(int value)
{
	SinglyLinkedListNode* curNode{ m_head };
	while (curNode != nullptr)
	{
		if (curNode->m_data == value)
		{
			break;
		}
		curNode = curNode->m_next;
	}
	return curNode;
}

/// <summary>
/// 지정한 값을 포함하는 가장 마지막 일치하는 노드를 반환한다.
/// </summary>
/// <param name="value">찾을 값</param>
/// <returns>지정한 값을 포함하는 노드(없는 경우: nullptr)</returns>
SinglyLinkedListNode* SinglyLinkedList::FindLast(int value)
{
	SinglyLinkedListNode* matchNode{ nullptr };
	SinglyLinkedListNode* curNode{ m_head };
	while (curNode != nullptr)
	{
		if (curNode->m_data == value)
		{
			matchNode = curNode;
		}
		curNode = curNode->m_next;
	}
	return matchNode;
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void SinglyLinkedList::PrintInfo()
{
	std::cout << "Count: " << m_count << std::endl;
	std::cout << "Nodes: ";
	SinglyLinkedListNode* curNode{ m_head };
	while (curNode != nullptr)
	{
		std::cout << curNode->m_data << ", ";
		curNode = curNode->m_next;
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
SinglyLinkedListNode* SinglyLinkedList::PopNode(int value)
{
	SinglyLinkedListNode* newNode{ nullptr };
	if (m_free == nullptr)
	{
		newNode = new SinglyLinkedListNode(value);
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
void SinglyLinkedList::PushNode(SinglyLinkedListNode* node)
{
	node->m_next = m_free;
	m_free = node;
}
#pragma endregion