#include "ArrayListGraph.h"

#pragma region ������
/// <summary>
/// ������ ũ�� Ȥ�� �⺻ ũ���� ArrayListGraph�� �����Ѵ�.
/// </summary>
ArrayListGraph::ArrayListGraph()
	: m_nodeCount(0), m_graphHeaders(nullptr), m_freeHeaders(nullptr), m_freeNodes(nullptr)
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
void ArrayListGraph::InsertNode(int num)
{
	if (ContainsNode(num))
	{
		return;
	}

	GraphHeader* newHeader{ PopHeader(num) };
	newHeader->m_next = m_graphHeaders;
	m_graphHeaders = newHeader;

	m_nodeCount++;
}

/// <summary>
/// ArrayListGraph�� from -> to �� ������ �߰��Ѵ�.
/// </summary>
/// <param name="from">���� ���</param>
/// <param name="to">�� ���</param>
void ArrayListGraph::InsertEdge(int from, int to)
{
	if (ContainsEdge(from, to))
	{
		return;
	}

	GraphHeader* fromHeader{ GetTargetHeader(from) };
	GraphNode* newNode{ PopNode(to) };
	newNode->m_next = fromHeader->m_data;
	fromHeader->m_data = newNode;
}

/// <summary>
/// ArrayListGraph���� ������ �ε����� ��带 �����Ѵ�.
/// </summary>
/// <param name="value">������ ��</param>
void ArrayListGraph::RemoveNode(int num)
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
/// �׷����� ������ ������ ��尡 �����ϴ��� �˻�
/// </summary>
/// <param name="num">Ȯ���� ��ȣ</param>
/// <returns>��� ���� ����</returns>
bool ArrayListGraph::ContainsNode(int num)
{
	GraphHeader* curHead{ m_graphHeaders };
	while (curHead != nullptr)
	{
		if (curHead->m_idx == num)
		{
			return true;
		}
		curHead = curHead->m_next;
	}

	return false;
}

/// <summary>
/// �׷����� ���� ��忡�� �� ������ ������ �����ϴ��� �˻�
/// </summary>
/// <param name="from">���� ��� ��ȣ</param>
/// <param name="to">�� ��� ��ȣ</param>
/// <returns>���� ���� ����</returns>
bool ArrayListGraph::ContainsEdge(int from, int to)
{
	if (!ContainsNode(from) || !ContainsNode(to))
	{
		std::cout << "�������� �ʴ� ��带 �߰��Ϸ� �ϰ� �ֽ��ϴ�.\n";
		return true;
	}

	GraphHeader* targetHeader{ GetTargetHeader(from) };
	GraphNode* targetNode{ targetHeader->m_data };
	while (targetNode != nullptr)
	{
		if (targetNode->m_idx == to)
		{
			return true;
		}
		targetNode = targetNode->m_next;
	}

	return false;
}

/// <summary>
/// ������ ��ȣ�� ����� �����ϴ� ��� ��� ��ȯ
/// </summary>
/// <param name="num">��� ��ȣ</param>
/// <returns>�ش� ��ȣ�� ���(������ nullptr)</returns>
GraphHeader* ArrayListGraph::GetTargetHeader(int num)
{
	GraphHeader* target{ m_graphHeaders };
	while (target != nullptr)
	{
		if (target->m_idx == num)
		{
			break;
		}
		target = target->m_next;
	}

	return target;
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
		curHeader = curHeader->m_next;
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