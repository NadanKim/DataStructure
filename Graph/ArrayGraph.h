#pragma once
#include <iostream>

class ArrayGraph
{
public:
#pragma region 생성자
	ArrayGraph(size_t nodeCapacity = 5);
	~ArrayGraph();
#pragma endregion

#pragma region 속성
	size_t NodeCapacity() { return m_nodeCapacity; }
	size_t NodeCount() { return m_nodeCount; }
#pragma endregion

#pragma region 메서드
	void InsertNode();
	void InsertEdge(int from, int to);

	void RemoveNode(int index);
	void RemoveEdge(int from, int to);
	void Clear();

	size_t GetDegreeIn(int index);
	size_t GetDegreeOut(int index);

	void PrintInfo();
#pragma endregion

private:
#pragma region Class Util
#pragma endregion

#pragma region 변수
	size_t m_nodeCapacity;
	size_t m_nodeCount;

	int** m_graph;
#pragma endregion
};