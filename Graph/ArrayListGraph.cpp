#include "ArrayListGraph.h"

#pragma region ������
/// <summary>
/// ������ ũ�� Ȥ�� �⺻ ũ���� ArrayListGraph�� �����Ѵ�.
/// </summary>
ArrayListGraph::ArrayListGraph()
	: m_nodeCount(0), m_graphHeaders(nullptr), m_freeHeaders(nullptr)
{
}

/// <summary>
/// �޸� ������ ���� ���� ���� ������ ������ �����Ѵ�.
/// </summary>
ArrayListGraph::~ArrayListGraph()
{
	while (m_freeNodes != nullptr)
	{
		GraphNode* curNode{ m_freeNodes };
		m_freeNodes = m_freeNodes->m_next;
		delete curNode;
	}

	while (m_graphHeaders != nullptr)
	{
		GraphHeader* curHead{ m_graphHeaders };
		m_graphHeaders = m_graphHeaders->m_next;
		delete curHead;
	}

	while (m_freeHeaders != nullptr)
	{
		GraphHeader* curHead{ m_freeHeaders };
		m_freeHeaders = m_freeHeaders->m_next;
		delete curHead;
	}
}
#pragma endregion

#pragma region �޼���
/// <summary>
/// ArrayListGraph�� ��带 �߰��Ѵ�.
/// </summary>
void ArrayListGraph::InsertNode()
{

}

/// <summary>
/// ArrayListGraph�� from -> to �� ������ �߰��Ѵ�.
/// </summary>
/// <param name="from">���� ���</param>
/// <param name="to">�� ���</param>
void ArrayListGraph::InsertEdge(int from, int to)
{

}

/// <summary>
/// ArrayListGraph���� ������ �ε����� ��带 �����Ѵ�.
/// </summary>
/// <param name="value">������ ��</param>
void ArrayListGraph::RemoveNode(int index)
{
	
}

/// <summary>
/// ArrayListGraph���� from -> to �� ������ �����Ѵ�.
/// </summary>
/// <param name="from">���� ���</param>
/// <param name="to">�� ���</param>
void ArrayListGraph::RemoveEdge(int from, int to)
{
	
}

/// <summary>
/// ArrayListGraph�� ��� ��� �� ������ �����Ѵ�.
/// </summary>
void ArrayListGraph::Clear()
{
	
}

/// <summary>
/// ������ �ε����� ��忡 �����ϴ� ������ ��ȯ�Ѵ�.
/// </summary>
/// <param name="index">����� �ε���</param>
size_t ArrayListGraph::GetDegreeIn(int index)
{
	return 0;
}

/// <summary>
/// ������ �ε����� ��忡�� �����ϴ� ������ ��ȯ�Ѵ�.
/// </summary>
/// <param name="index">����� �ε���</param>
size_t ArrayListGraph::GetDegreeOut(int index)
{
	return 0;
}

/// <summary>
/// �׽�Ʈ�� ����Ʈ ���� ��� �Լ�
/// </summary>
void ArrayListGraph::PrintInfo()
{
	std::cout << "----------------------\n";
	std::cout << "Count: " << m_nodeCount << '\n';
	GraphHeader* curHeader{ m_graphHeaders };
	while (curHeader != nullptr)
	{
		std::cout << curHeader->m_idx << " : ";
		if (curHeader->m_data == nullptr)
		{
			std::cout << "NULL\n";
		}
		else
		{
			GraphNode* curNode{ curHeader->m_data };
			while (curNode != nullptr)
			{
				std::cout << curNode->m_idx << ' ';
				curNode = curNode->m_next;
			}
			std::cout << '\n';
		}
	}
	std::cout << "----------------------\n\n";
}
#pragma endregion

#pragma region Class Util
/// <summary>
/// ���� ���� ����Ʈ���� ����� �������ų� ���� �����Ѵ�.
/// </summary>
/// <param name="value">��� ���� �� �ε��� ��</param>
/// <returns>�� ���</returns>
GraphHeader* ArrayListGraph::PopHeader(int value)
{
	GraphHeader* newNode{ nullptr };
	if (m_freeHeaders == nullptr)
	{
		newNode = new GraphHeader(value);
	}
	else
	{
		newNode = m_freeHeaders;
		m_freeHeaders = m_freeHeaders->m_next;

		newNode->m_idx = value;
		newNode->m_data = nullptr;
		newNode->m_next = nullptr;
	}
	return newNode;
}

/// <summary>
/// ���� ���� ����Ʈ�� ���ŵ� ����� �����Ѵ�.
/// </summary>
/// <param name="node">���ŵ� ���</param>
void ArrayListGraph::PushHeader(GraphHeader* header)
{
	header->m_next = m_freeHeaders;
	m_freeHeaders = header;
}

/// <summary>
/// ���� ���� ����Ʈ���� ��带 �������ų� ���� �����Ѵ�.
/// </summary>
/// <param name="value">��� ������ �ʱⰪ</param>
/// <returns>�� ���</returns>
GraphNode* ArrayListGraph::PopNode(int value)
{
	GraphNode* newNode{ nullptr };
	if (m_freeNodes == nullptr)
	{
		newNode = new GraphNode(value);
	}
	else
	{
		newNode = m_freeNodes;
		m_freeNodes = m_freeNodes->m_next;

		newNode->m_idx = value;
		newNode->m_next = nullptr;
	}
	return newNode;
}

/// <summary>
/// ���� ���� ����Ʈ�� ���ŵ� ��带 �����Ѵ�.
/// </summary>
/// <param name="node">���ŵ� ���</param>
void ArrayListGraph::PushNode(GraphNode* node)
{
	node->m_next = m_freeNodes;
	m_freeNodes = node;
}
#pragma endregion