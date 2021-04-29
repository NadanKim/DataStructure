#include <iostream>
#include "Graph/ArrayListGraph.h"

// 생성한 자료구조 테스트용 메인
int main()
{
	ArrayListGraph graph;
	graph.InsertNode(1);
	graph.InsertNode(2);
	graph.InsertNode(3);
	graph.InsertNode(4);

	graph.InsertEdge(1, 2);
	graph.InsertEdge(1, 4);
	graph.InsertEdge(2, 3);
	graph.InsertEdge(2, 4);
	graph.InsertEdge(3, 4);

	graph.PrintInfo();

	std::cout << graph.GetDegreeIn(1) << ' ' << graph.GetDegreeOut(1) << '\n';

	graph.RemoveEdge(1, 4);

	graph.PrintInfo();

	std::cout << graph.GetDegreeIn(1) << ' ' << graph.GetDegreeOut(1) << '\n';

	graph.RemoveNode(2);

	graph.PrintInfo();
}