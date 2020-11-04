#include "DoublyCircularLinkedList.h"

#pragma region 생성자
/// <summary>
/// 비어있는 DoublyCircularLinkedList를 생성한다.
/// </summary>
DoublyCircularLinkedList::DoublyCircularLinkedList()
	: m_count(0), m_head(nullptr), m_tail(nullptr), m_free(nullptr)
{
}

/// <summary>
/// 다른 SinglyLinkedList가 가지고 있는 노드를 복사해 SinglyLinkedList를 생성한다.
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
/// SinglyLinkedList의 시작 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void DoublyCircularLinkedList::AddFirst(int value)
{
	DoublyCircularLinkedListNode* newNode{ PopNode(value) };
	AddFirst(newNode);
}

/// <summary>
/// SinglyLinkedList의 시작 위치에 지정한 노드를 추가한다.
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
/// SinglyLinkedList의 끝 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void DoublyCircularLinkedList::AddLast(int value)
{
	DoublyCircularLinkedListNode* newNode{ PopNode(value) };
	AddLast(newNode);
}

/// <summary>
/// SinglyLinkedList의 끝 위치에 지정한 노드를 추가한다.
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
	while (index--)
	{
		curNode = curNode->m_next;
	}

	DoublyCircularLinkedListNode* prevNode{ curNode != nullptr ? curNode->m_prev : nullptr };
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
/// DoublyCircularLinkedList에서 가장 처음 일치한 지정된 값을 포함한 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
bool DoublyCircularLinkedList::RemoveFirst(int value)
{
	DoublyCircularLinkedListNode* curNode{ m_head };
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
/// DoublyCircularLinkedList에서 가장 처음 일치한 지정된 값을 포함한 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
bool DoublyCircularLinkedList::RemoveLast(int value)
{
	DoublyCircularLinkedListNode* curNode{ m_tail };
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
/// DoublyCircularLinkedList에서 지정된 노드를 제거한다.
/// </summary>
/// <param name="node">제거할 노드</param>
void DoublyCircularLinkedList::Remove(const DoublyCircularLinkedListNode* node)
{
	if (node == nullptr)
	{
		throw std::invalid_argument("node");
	}

	DoublyCircularLinkedListNode* curNode{ m_head };
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

	DoublyCircularLinkedListNode* prevNode{ curNode->m_prev };
	DoublyCircularLinkedListNode* nextNode{ curNode->m_next };
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
/// DoublyCircularLinkedList의 모든 노드를 제거한다.
/// </summary>
void DoublyCircularLinkedList::Clear()
{
	while (m_head != nullptr)
	{
		DoublyCircularLinkedListNode* curNode{ m_head };
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
bool DoublyCircularLinkedList::Contains(int value)
{
	DoublyCircularLinkedListNode* curNode{ m_head };
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
/// 지정한 노드가 DoublyCircularLinkedList에 포함되는지 확인한다.
/// </summary>
/// <param name="node">찾을 노드</param>
/// <returns>노드의 포함 여부</returns>
bool DoublyCircularLinkedList::Contains(const DoublyCircularLinkedListNode* node)
{
	DoublyCircularLinkedListNode* curNode{ m_head };
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
DoublyCircularLinkedListNode* DoublyCircularLinkedList::Find(int value)
{
	DoublyCircularLinkedListNode* curNode{ m_head };
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
DoublyCircularLinkedListNode* DoublyCircularLinkedList::FindLast(int value)
{
	DoublyCircularLinkedListNode* curNode{ m_tail };
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