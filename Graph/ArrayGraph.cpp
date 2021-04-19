#include "ArrayGraph.h"

#pragma region 생성자
/// <summary>
/// 지정된 크기 혹은 기본 크기의 ArrayGraph를 생성한다.
/// </summary>
/// <param name="nodeCapacity">생성할 그래프의 크기(기본:5)</param>
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
/// 메모리 누수를 막기 위해 동적 생성한 노드들을 제거한다.
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

#pragma region 메서드
/// <summary>
/// ArrayGraph에 노드를 추가한다.
/// </summary>
void ArrayGraph::InsertNode()
{
	if (m_nodeCount < m_nodeCapacity)
	{
		m_nodeCount++;
	}
}

/// <summary>
/// ArrayGraph에 from -> to 인 간선을 추가한다.
/// </summary>
/// <param name="from">시작 노드</param>
/// <param name="to">끝 노드</param>
void ArrayGraph::InsertEdge(int from, int to)
{
	if (from < 0 || from >= m_nodeCount || to < 0 || to >= m_nodeCount)
	{
		return;
	}

	m_graph[from][to]++;
}

/// <summary>
/// ArrayGraph에서 지정된 인덱스의 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
void ArrayGraph::RemoveNode(int index)
{
	
}

/// <summary>
/// ArrayGraph에서 from -> to 인 간선을 제거한다.
/// </summary>
/// <param name="from">시작 노드</param>
/// <param name="to">끝 노드</param>
void ArrayGraph::RemoveEdge(int from, int to)
{

}

/// <summary>
/// ArrayGraph의 모든 노드 및 간선을 제거한다.
/// </summary>
void ArrayGraph::Clear()
{
	
}

/// <summary>
/// 지정된 인덱스의 노드에 진입하는 차수를 반환한다.
/// </summary>
/// <param name="index">노드의 인덱스</param>
size_t ArrayGraph::GetDegreeIn(int index)
{
	return 0;
}

/// <summary>
/// 지정된 인덱스의 노드에서 진출하는 차수를 반환한다.
/// </summary>
/// <param name="index">노드의 인덱스</param>
size_t ArrayGraph::GetDegreeOut(int index)
{
	return 0;
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void ArrayGraph::PrintInfo()
{
	std::cout << "----------------------\n";
	std::cout << "Capacity: " << m_nodeCapacity << '\n';
	std::cout << "Count: " << m_nodeCount << '\n';
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