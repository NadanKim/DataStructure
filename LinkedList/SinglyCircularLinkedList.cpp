#include "SinglyCircularLinkedList.h"

#pragma region 생성자
/// <summary>
/// 비어있는 SinglyCircularLinkedList를 생성한다.
/// </summary>
SinglyCircularLinkedList::SinglyCircularLinkedList()
	: m_count(0), m_head(nullptr), m_free(nullptr)
{
}

/// <summary>
/// 다른 SinglyCircularLinkedList가 가지고 있는 노드를 복사해 SinglyCircularLinkedList를 생성한다.
/// </summary>
/// <param name="other">기준이 될 SinglyCircularLinkedList</param>
SinglyCircularLinkedList::SinglyCircularLinkedList(const SinglyCircularLinkedList& other)
	: m_count(other.m_count), m_head(nullptr), m_free(nullptr)
{
	if (other.m_head == nullptr)
	{
		return;
	}

	SinglyCircularLinkedListNode* curNode{ other.m_head };
	SinglyCircularLinkedListNode* prevNode{ PopNode(curNode->m_data) };

	m_head = prevNode;
	curNode = curNode->m_next;

	while (curNode->m_next != other.m_head)
	{
		SinglyCircularLinkedListNode* newNode{ PopNode(curNode->m_data) };
		prevNode->m_next = newNode;
		prevNode = newNode;
		curNode = curNode->m_next;
	}
}

/// <summary>
/// 메모리 누수를 막기 위해 동적 생성한 노드들을 제거한다.
/// </summary>
SinglyCircularLinkedList::~SinglyCircularLinkedList()
{
	if (m_head != nullptr)
	{
		SinglyCircularLinkedListNode* head{ m_head };
		do
		{
			SinglyCircularLinkedListNode* curNode{ m_head };
			m_head = m_head->m_next;
			delete curNode;
		} while (m_head != head);
	}

	while (m_free != nullptr)
	{
		SinglyCircularLinkedListNode* curNode{ m_free };
		m_free = m_free->m_next;
		delete curNode;
	}
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// SinglyCircularLinkedList의 시작 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void SinglyCircularLinkedList::Add(int value)
{
	SinglyCircularLinkedListNode* newNode{ PopNode(value) };
	Add(newNode);
}

/// <summary>
/// SinglyCircularLinkedList의 시작 위치에 지정한 노드를 추가한다.
/// </summary>
/// <param name="node">추가할 새 노드</param>
void SinglyCircularLinkedList::Add(SinglyCircularLinkedListNode* node)
{
	if (node == nullptr || node->m_next != nullptr)
	{
		throw std::invalid_argument("node");
	}

	node->m_next = m_head;

	UpdateHead(node);

	m_count++;
}

/// <summary>
/// SinglyCircularLinkedList의 지정한 인덱스에 해당하는 위치에 지정한 값이 포함된 새 노드를 추가한다.
/// </summary>
/// <param name="index">값을 추가할 인덱스</param>
/// <param name="value">추가할 값</param>
void SinglyCircularLinkedList::Insert(size_t index, int value)
{
	SinglyCircularLinkedListNode* newNode{ PopNode(value) };
	Insert(index, newNode);
}

/// <summary>
/// SinglyCircularLinkedList의 지정한 인덱스에 해당하는 위치에 지정된 노드를 추가한다.
/// </summary>
/// <param name="index">새 노드를 추가할 인덱스</param>
/// <param name="node">추가할 새 노드</param>
void SinglyCircularLinkedList::Insert(size_t index, SinglyCircularLinkedListNode* node)
{
	if (index > m_count)
	{
		throw std::out_of_range("index");
	}

	if (node == nullptr || node->m_next != nullptr)
	{
		throw std::invalid_argument("node");
	}

	SinglyCircularLinkedListNode* prevNode{ nullptr };
	SinglyCircularLinkedListNode* curNode{ m_head };
	while (index--)
	{
		prevNode = curNode;
		curNode = curNode->m_next;
	}

	node->m_next = curNode;

	if (prevNode != nullptr)
	{
		prevNode->m_next = node;
	}
	else
	{
		UpdateHead(node);
	}

	m_count++;
}

/// <summary>
/// SinglyCircularLinkedList에서 가장 처음 일치한 지정된 값을 포함한 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
bool SinglyCircularLinkedList::Remove(int value)
{
	if (m_head != nullptr)
	{
		SinglyCircularLinkedListNode* curNode{ m_head };
		do
		{
			if (curNode->m_data == value)
			{
				Remove(curNode);
				return true;
			}
			curNode = curNode->m_next;
		} while (curNode != m_head);
	}

	return false;
}

/// <summary>
/// SinglyCircularLinkedList에서 지정된 노드를 제거한다.
/// </summary>
/// <param name="node">제거할 노드</param>
void SinglyCircularLinkedList::Remove(const SinglyCircularLinkedListNode* node)
{
	if (node == nullptr)
	{
		throw std::invalid_argument("node");
	}

	if (m_head != nullptr)
	{
		SinglyCircularLinkedListNode* prevNode{ nullptr };
		SinglyCircularLinkedListNode* curNode{ m_head };
		do
		{
			if (curNode == node)
			{
				if (prevNode != nullptr)
				{
					prevNode->m_next = curNode->m_next;
				}
				else
				{
					UpdateHead(curNode->m_next);
				}
				PushNode(curNode);
				m_count--;
				return;
			}
			prevNode = curNode;
			curNode = curNode->m_next;
		} while (curNode != m_head);
	}

	throw std::out_of_range("node");
}

/// <summary>
/// SinglyCircularLinkedList의 모든 노드를 제거한다.
/// </summary>
void SinglyCircularLinkedList::Clear()
{
	if (m_head != nullptr)
	{
		SinglyCircularLinkedListNode* head{ m_head };
		do
		{
			SinglyCircularLinkedListNode* curNode{ m_head };
			m_head = m_head->m_next;
			PushNode(curNode);
		} while (m_head != head);
		m_head = nullptr;
	}
	m_count = 0;
}

/// <summary>
/// 지정한 값을 포함한 노드가 존재하는지 확인한다.
/// </summary>
/// <param name="value">찾을 값</param>
/// <returns>값의 존재 여부</returns>
bool SinglyCircularLinkedList::Contains(int value)
{
	SinglyCircularLinkedListNode* curNode{ m_head };
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
/// 지정한 노드가 SinglyCircularLinkedList에 포함되는지 확인한다.
/// </summary>
/// <param name="node">찾을 노드</param>
/// <returns>노드의 포함 여부</returns>
bool SinglyCircularLinkedList::Contains(const SinglyCircularLinkedListNode* node)
{
	SinglyCircularLinkedListNode* curNode{ m_head };
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
SinglyCircularLinkedListNode* SinglyCircularLinkedList::Find(int value)
{
	SinglyCircularLinkedListNode* curNode{ m_head };
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
SinglyCircularLinkedListNode* SinglyCircularLinkedList::FindLast(int value)
{
	SinglyCircularLinkedListNode* matchNode{ nullptr };
	SinglyCircularLinkedListNode* curNode{ m_head };
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
void SinglyCircularLinkedList::PrintInfo()
{
	std::cout << "Count: " << m_count << std::endl;
	std::cout << "Nodes: ";
	if (m_head != nullptr)
	{
		SinglyCircularLinkedListNode* curNode{ m_head };
		do
		{
			std::cout << curNode->m_data << ", ";
			curNode = curNode->m_next;
		} while (curNode != m_head);
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
SinglyCircularLinkedListNode* SinglyCircularLinkedList::PopNode(int value)
{
	SinglyCircularLinkedListNode* newNode{ nullptr };
	if (m_free == nullptr)
	{
		newNode = new SinglyCircularLinkedListNode(value);
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
void SinglyCircularLinkedList::PushNode(SinglyCircularLinkedListNode* node)
{
	node->m_next = m_free;
	m_free = node;
}

/// <summary>
/// 리스트의 head를 변경하고 리스트가 원형이 유지되도록 한다.
/// </summary>
/// <param name="node">head로 변경할 노드</param>
void SinglyCircularLinkedList::UpdateHead(SinglyCircularLinkedListNode* node)
{
	if (node == nullptr)
	{
		throw std::invalid_argument("node");
	}

	SinglyCircularLinkedListNode* tail{ m_head };
	if (tail != nullptr)
	{
		while (tail->m_next != m_head)
		{
			tail = tail->m_next;
		}
	}

	m_head = node;

	if (tail != nullptr)
	{
		tail->m_next = m_head;
	}
	else
	{
		m_head->m_next = m_head;
	}
}
#pragma endregion