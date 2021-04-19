#include <iostream>
#include "Graph/ArrayGraph.h"

// 생성한 자료구조 테스트용 메인
int main()
{
	ArrayGraph graph;

	graph.InsertNode();
	graph.InsertNode();
	graph.PrintInfo();

	graph.InsertEdge(0, 1);
	graph.PrintInfo();

	graph.InsertEdge(1, 1);
	graph.PrintInfo();
}