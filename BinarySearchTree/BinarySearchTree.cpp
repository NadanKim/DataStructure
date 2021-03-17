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
	Clear();

	while (m_free != nullptr)
	{
		Node* curNode{ m_free };
		m_free = m_free->m_right;
		delete curNode;
	}
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// 
/// </summary>
/// <param name="value">추가할 값</param>
void BinarySearchTree::Insert(int value)
{
	
	Node** target{ &m_root };
	while (*target != nullptr)
	{
		if ((*target)->m_data == value)
		{
			target = nullptr;
			break;
		}

		if ((*target)->m_data > value)
		{
			target = &((*target)->m_left);
		}
		else
		{
			target = &((*target)->m_right);
		}
	}

	if (target != nullptr)
	{
		*target = PopNode(value);
		m_count++;
	}
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
	return false;
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void BinarySearchTree::PrintInfo()
{
	std::cout << "----------------------\n";
	PrintInfo(m_root);
	std::cout << "----------------------\n\n";
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void BinarySearchTree::PrintInfo(Node* node, size_t depth)
{
	if (node == nullptr)
	{
		return;
	}

	for (int i = 0; i < depth; i++)
	{
		std::cout << "  ";
	}
	std::cout << "└  " << node->m_data << '\n';

	PrintInfo(node->m_left, depth + 1);
	PrintInfo(node->m_right, depth + 1);
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
		m_free = m_free->m_right;

		newNode->m_data = value;
		newNode->m_right = nullptr;
	}

	return newNode;
}

/// <summary>
/// 자유 공간 리스트에 제거된 노드를 저장한다.
/// </summary>
/// <param name="node">제거된 노드</param>
void BinarySearchTree::PushNode(Node* node)
{
	node->m_left = nullptr;
	node->m_right = m_free;
	m_free = node;
}
#pragma endregion