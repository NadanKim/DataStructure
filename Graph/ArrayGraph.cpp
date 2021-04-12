#include "ArrayGraph.h"

#pragma region ������
/// <summary>
/// ������ ũ�� Ȥ�� �⺻ ũ���� ArrayGraph�� �����Ѵ�.
/// </summary>
/// <param name="nodeCapacity">������ �׷����� ũ��(�⺻:5)</param>
ArrayGraph::ArrayGraph(size_t nodeCapacity)
	: m_nodeCapacity(nodeCapacity), m_nodeCount(0)
{
	m_graph = new int* [nodeCapacity];
	for (size_t i = 0; i < nodeCapacity; i++)
	{
		m_graph[i] = new int[nodeCapacity];
		std::fill_n(m_graph[i], nodeCapacity, 0);
	}
}

/// <summary>
/// �޸� ������ ���� ���� ���� ������ ������ �����Ѵ�.
/// </summary>
ArrayGraph::~ArrayGraph()
{
	for (size_t i = 0; i < m_nodeCapacity; i++)
	{
		delete[] m_graph[i];
	}
	delete[] m_graph;
}
#pragma endregion

#pragma region �޼���
/// <summary>
/// ArrayGraph�� ��带 �߰��Ѵ�.
/// </summary>
void ArrayGraph::InsertNode()
{
	
}

/// <summary>
/// ArrayGraph�� from -> to �� ������ �߰��Ѵ�.
/// </summary>
/// <param name="from">���� ���</param>
/// <param name="to">�� ���</param>
void ArrayGraph::InsertEdge(int from, int to)
{

}

/// <summary>
/// ArrayGraph���� ������ �ε����� ��带 �����Ѵ�.
/// </summary>
/// <param name="value">������ ��</param>
void ArrayGraph::RemoveNode(int index)
{
	
}

/// <summary>
/// ArrayGraph���� from -> to �� ������ �����Ѵ�.
/// </summary>
/// <param name="from">���� ���</param>
/// <param name="to">�� ���</param>
void ArrayGraph::RemoveEdge(int from, int to)
{

}

/// <summary>
/// ArrayGraph�� ��� ��� �� ������ �����Ѵ�.
/// </summary>
void ArrayGraph::Clear()
{
	
}

/// <summary>
/// ������ �ε����� ��忡 �����ϴ� ������ ��ȯ�Ѵ�.
/// </summary>
/// <param name="index">����� �ε���</param>
size_t ArrayGraph::GetDegreeIn(int index)
{
	return 0;
}

/// <summary>
/// ������ �ε����� ��忡�� �����ϴ� ������ ��ȯ�Ѵ�.
/// </summary>
/// <param name="index">����� �ε���</param>
size_t ArrayGraph::GetDegreeOut(int index)
{
	return 0;
}

/// <summary>
/// �׽�Ʈ�� ����Ʈ ���� ��� �Լ�
/// </summary>
void ArrayGraph::PrintInfo()
{
	std::cout << "----------------------\n";
	for (size_t i = 0; i < m_nodeCapacity; i++)
	{
		for (size_t j = 0; j < m_nodeCapacity; j++)
		{
			std::cout << ' ' << m_graph[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "----------------------\n\n";
}
#pragma endregion

#pragma region Class Util
#pragma endregion