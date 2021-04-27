#include "ArrayListGraph.h"

#pragma region 생성자
/// <summary>
/// 지정된 크기 혹은 기본 크기의 ArrayListGraph를 생성한다.
/// </summary>
ArrayListGraph::ArrayListGraph()
	: m_nodeCount(0), m_graphHeaders(nullptr), m_freeHeaders(nullptr), m_freeNodes(nullptr)
{
}

/// <summary>
/// 메모리 누수를 막기 위해 동적 생성한 노드들을 제거한다.
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

#pragma region 메서드
/// <summary>
/// ArrayListGraph에 노드를 추가한다.
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
/// ArrayListGraph에 from -> to 인 간선을 추가한다.
/// </summary>
/// <param name="from">시작 노드</param>
/// <param name="to">끝 노드</param>
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
/// ArrayListGraph에서 지정된 인덱스의 노드를 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
void ArrayListGraph::RemoveNode(int num)
{
	
}

/// <summary>
/// ArrayListGraph에서 from -> to 인 간선을 제거한다.
/// </summary>
/// <param name="from">시작 노드</param>
/// <param name="to">끝 노드</param>
void ArrayListGraph::RemoveEdge(int from, int to)
{
	
}

/// <summary>
/// ArrayListGraph의 모든 노드 및 간선을 제거한다.
/// </summary>
void ArrayListGraph::Clear()
{
	
}

/// <summary>
/// 지정된 인덱스의 노드에 진입하는 차수를 반환한다.
/// </summary>
/// <param name="index">노드의 인덱스</param>
size_t ArrayListGraph::GetDegreeIn(int index)
{
	return 0;
}

/// <summary>
/// 지정된 인덱스의 노드에서 진출하는 차수를 반환한다.
/// </summary>
/// <param name="index">노드의 인덱스</param>
size_t ArrayListGraph::GetDegreeOut(int index)
{
	return 0;
}

/// <summary>
/// 그래프에 지정된 숫자의 노드가 존재하는지 검사
/// </summary>
/// <param name="num">확인할 번호</param>
/// <returns>노드 존재 여부</returns>
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
/// 그래프에 시작 노드에서 끝 노드로의 에지가 존재하는지 검사
/// </summary>
/// <param name="from">시작 노드 번호</param>
/// <param name="to">끝 노드 번호</param>
/// <returns>에지 존재 여부</returns>
bool ArrayListGraph::ContainsEdge(int from, int to)
{
	if (!ContainsNode(from) || !ContainsNode(to))
	{
		std::cout << "존재하지 않는 노드를 추가하려 하고 있습니다.\n";
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
/// 지정된 번호의 헤더가 존재하는 경우 헤더 반환
/// </summary>
/// <param name="num">노드 번호</param>
/// <returns>해당 번호의 노드(없으면 nullptr)</returns>
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
/// 테스트용 리스트 정보 출력 함수
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
/// 자유 공간 리스트에서 헤더를 가져오거나 새로 생성한다.
/// </summary>
/// <param name="value">헤더 생성 시 인덱스 값</param>
/// <returns>새 헤더</returns>
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
/// 자유 공간 리스트에 제거된 헤더를 저장한다.
/// </summary>
/// <param name="node">제거된 헤더</param>
void ArrayListGraph::PushHeader(GraphHeader* header)
{
	header->m_next = m_freeHeaders;
	m_freeHeaders = header;
}

/// <summary>
/// 자유 공간 리스트에서 노드를 가져오거나 새로 생성한다.
/// </summary>
/// <param name="value">노드 생성시 초기값</param>
/// <returns>새 노드</returns>
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
/// 자유 공간 리스트에 제거된 노드를 저장한다.
/// </summary>
/// <param name="node">제거된 노드</param>
void ArrayListGraph::PushNode(GraphNode* node)
{
	node->m_next = m_freeNodes;
	m_freeNodes = node;
}
#pragma endregion