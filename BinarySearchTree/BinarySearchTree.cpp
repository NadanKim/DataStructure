#include "BinarySearchTree.h"

#pragma region 생성자
/// <summary>
/// 비어있는 DoublyLinkedList를 생성한다.
/// </summary>
BinarySearchTree::BinarySearchTree()
	: m_count(0), m_max(0), m_min(0), m_root(nullptr), m_free(nullptr)
{
}

/// <summary>
/// 메모리 누수를 막기 위해 동적 생성한 노드들을 제거한다.
/// </summary>
BinarySearchTree::~BinarySearchTree()
{
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// 
/// </summary>
/// <param name="value">추가할 값</param>
void BinarySearchTree::Insert(int value)
{

}

/// <summary>
/// BinarySearchTree에서 지정된 값을 가진 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
void BinarySearchTree::Delete(int value)
{
	
}

/// <summary>
/// BinarySearchTree의 모든 노드를 제거한다.
/// </summary>
void BinarySearchTree::Clear()
{
	
}

/// <summary>
/// BinarySearchTree에 지정된 값이 존재하는지 검색한다.
/// </summary>
/// <param name="value">검색할 값</param>
bool BinarySearchTree::Search(int value)
{

}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void BinarySearchTree::PrintInfo()
{

}
#pragma endregion

#pragma region Class Util
/// <summary>
/// 자유 공간 리스트에서 노드를 가져오거나 새로 생성한다.
/// </summary>
/// <param name="value">노드 생성시 초기값</param>
/// <returns>새 노드</returns>
BinarySearchTree::Node* BinarySearchTree::PopNode(int value)
{
	Node* newNode{ nullptr };
	if (m_free == nullptr)
	{
		newNode = new Node(value);
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
void BinarySearchTree::PushNode(Node* node)
{
	node->m_prev = nullptr;
	node->m_next = m_free;
	m_free = node;
}
#pragma endregion