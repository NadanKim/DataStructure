#pragma once
#include <iostream>

struct GraphNode
{
	GraphNode(int value)
		: m_idx(value), m_next(nullptr)
	{
	}

	int m_idx;
	GraphNode* m_next;
};

struct GraphHeader
{
	GraphHeader(int value)
		: m_idx(value), m_data(nullptr), m_next(nullptr)
	{
	}

	int m_idx;
	GraphNode* m_data;
	GraphHeader* m_next;
};

class ArrayListGraph
{
public:
#pragma region ������
	ArrayListGraph();
	~ArrayListGraph();
#pragma endregion

#pragma region �Ӽ�
	size_t NodeCount() { return m_nodeCount; }
#pragma endregion

#pragma region �޼���
	void InsertNode(int num);
	void InsertEdge(int from, int to);

	void RemoveNode(int num);
	void RemoveEdge(int from, int to);
	void Clear();

	size_t GetDegreeIn(int num);
	size_t GetDegreeOut(int num);

	bool ContainsNode(int num);
	bool ContainsEdge(int from, int to);

	GraphHeader* GetTargetHeader(int num);

	void PrintInfo();
#pragma endregion

private:
#pragma region Class Util
	GraphHeader* PopHeader(int value);
	void PushHeader(GraphHeader* header);

	GraphNode* PopNode(int value);
	void PushNode(GraphNode* node);
#pragma endregion

#pragma region ����
	size_t m_nodeCount;

	GraphHeader* m_graphHeaders;
	GraphHeader* m_freeHeaders;

	GraphNode* m_freeNodes;
#pragma endregion
};