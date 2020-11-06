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
/// 다른 DoublyLinkedList가 가지고 있는 노드를 복사해 DoublyLinkedList를 생성한다.
/// </summary>
/// <param name="other">기준이 될 DoublyLinkedList</param>
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
	: m_count(other.m_count), m_head(nullptr), m_tail(nullptr), m_free(nullptr)
{
	if (other.m_head == nullptr)
	{
		return;
	}

	DoublyLinkedListNode* curNode{ other.m_head };

	if (curNode != nullptr)
	{
		m_head = m_tail = PopNode(curNode->m_data);
		curNode = curNode->m_next;
	}

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
	while (m_head != nullptr)
	{
		DoublyLinkedListNode* curNode{ m_head };
		m_head = m_head->m_next;
		delete curNode;
	}

	while (m_free != nullptr)
	{
		DoublyLinkedListNode* curNode{ m_free };
		m_free = m_free->m_next;
		delete curNode;
	}
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// DoublyLinkedList의 시작 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void DoublyLinkedList::AddFirst(int value)
{
	DoublyLinkedListNode* newNode{ PopNode(value) };
	AddFirst(newNode);
}

/// <summary>
/// DoublyLinkedList의 시작 위치에 지정한 노드를 추가한다.
/// </summary>
/// <param name="node">추가할 새 노드</param>
void DoublyLinkedList::AddFirst(DoublyLinkedListNode* node)
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

	m_count++;
}

/// <summary>
/// DoublyLinkedList의 끝 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void DoublyLinkedList::AddLast(int value)
{
	DoublyLinkedListNode* newNode{ PopNode(value) };
	AddLast(newNode);
}

/// <summary>
/// DoublyLinkedList의 끝 위치에 지정한 노드를 추가한다.
/// </summary>
/// <param name="node">추가할 새 노드</param>
void DoublyLinkedList::AddLast(DoublyLinkedListNode* node)
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

	m_count++;
}

/// <summary>
/// DoublyLinkedList의 지정한 인덱스에 해당하는 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="index">값을 추가할 인덱스</param>
/// <param name="value">추가할 값</param>
void DoublyLinkedList::Insert(size_t index, int value)
{
	DoublyLinkedListNode* newNode{ PopNode(value) };
	Insert(index, newNode);
}

/// <summary>
/// DoublyLinkedList의 지정한 인덱스에 해당하는 위치에 지정된 노드를 추가한다.
/// </summary>
/// <param name="index">새 노드를 추가할 인덱스</param>
/// <param name="node">추가할 새 노드</param>
void DoublyLinkedList::Insert(size_t index, DoublyLinkedListNode* node)
{
	if (index > m_count)
	{
		throw std::out_of_range("index");
	}

	if (node == nullptr || node->m_next != nullptr)
	{
		throw std::invalid_argument("node");
	}

	DoublyLinkedListNode* curNode{ m_head };
	DoublyLinkedListNode* prevNode{ curNode != nullptr ? curNode->m_prev : nullptr };
	for (int i = 0; i < index; i++)
	{
		prevNode = curNode;
		curNode = curNode != nullptr ? curNode->m_next : nullptr;
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

	if (node->m_prev == nullptr)
	{
		m_head = node;
	}
	if (node->m_next == nullptr)
	{
		m_tail = node;
	}

	m_count++;
}

/// <summary>
/// DoublyLinkedList에서 가장 처음 일치한 지정된 값을 포함한 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
bool DoublyLinkedList::RemoveFirst(int value)
{
	DoublyLinkedListNode* curNode{ m_head };
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
/// DoublyLinkedList에서 가장 처음 일치한 지정된 값을 포함한 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
bool DoublyLinkedList::RemoveLast(int value)
{
	DoublyLinkedListNode* curNode{ m_tail };
	while (curNode != nullptr)
	{
		if (curNode->m_data == value)
		{
			break;
		}
		curNode = curNode->m_prev;
	}

	if (curNode == nullptr)
	{
		return false;
	}

	Remove(curNode);

	return true;
}

/// <summary>
/// DoublyLinkedList에서 지정된 노드를 제거한다.
/// </summary>
/// <param name="node">제거할 노드</param>
void DoublyLinkedList::Remove(const DoublyLinkedListNode* node)
{
	if (node == nullptr)
	{
		throw std::invalid_argument("node");
	}

	DoublyLinkedListNode* curNode{ m_head };
	while (curNode != nullptr)
	{
		if (curNode == node)
		{
			break;
		}
		curNode = curNode->m_next;
	}

	if (curNode == nullptr)
	{
		throw std::out_of_range("node");
	}

	DoublyLinkedListNode* prevNode{ curNode->m_prev };
	DoublyLinkedListNode* nextNode{ curNode->m_next };
	if (prevNode != nullptr)
	{
		prevNode->m_next = nextNode;
	}
	else
	{
		m_head = nextNode;
	}

	if (nextNode != nullptr)
	{
		nextNode->m_prev = prevNode;
	}
	else
	{
		m_tail = prevNode;
	}

	PushNode(curNode);

	m_count--;
}

/// <summary>
/// DoublyLinkedList의 모든 노드를 제거한다.
/// </summary>
void DoublyLinkedList::Clear()
{
	while (m_head != nullptr)
	{
		DoublyLinkedListNode* curNode{ m_head };
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
bool DoublyLinkedList::Contains(int value)
{
	DoublyLinkedListNode* curNode{ m_head };
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
/// 지정한 노드가 DoublyLinkedList에 포함되는지 확인한다.
/// </summary>
/// <param name="node">찾을 노드</param>
/// <returns>노드의 포함 여부</returns>
bool DoublyLinkedList::Contains(const DoublyLinkedListNode* node)
{
	DoublyLinkedListNode* curNode{ m_head };
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
DoublyLinkedListNode* DoublyLinkedList::Find(int value)
{
	DoublyLinkedListNode* curNode{ m_head };
	while (curNode != nullptr)
	{
		if (curNode->m_data == value)
		{
			return curNode;
		}
		curNode = curNode->m_next;
	}
	return nullptr;
}

/// <summary>
/// 지정한 값을 포함하는 가장 마지막 일치하는 노드를 반환한다.
/// </summary>
/// <param name="value">찾을 값</param>
/// <returns>지정한 값을 포함하는 노드(없는 경우: nullptr)</returns>
DoublyLinkedListNode* DoublyLinkedList::FindLast(int value)
{
	DoublyLinkedListNode* curNode{ m_tail };
	while (curNode != nullptr)
	{
		if (curNode->m_data == value)
		{
			return curNode;
		}
		curNode = curNode->m_prev;
	}
	return nullptr;
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void DoublyLinkedList::PrintInfo(bool isPrintReverse)
{
	std::cout << "Count: " << m_count << std::endl;
	std::cout << "Nodes: ";

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
void DoublyLinkedList::PushNode(DoublyLinkedListNode* node)
{
	node->m_prev = nullptr;
	node->m_next = m_free;
	m_free = node;
}
#pragma endregion