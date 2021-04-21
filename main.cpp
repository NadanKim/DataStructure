#include <iostream>
#include "Graph/ArrayGraph.h"

// 생성한 자료구조 테스트용 메인
int main()
{
	ArrayGraph graph;

	graph.InsertNode();
	graph.InsertNode();
	graph.InsertNode();
	graph.InsertNode();

	graph.InsertEdge(0, 1);
	graph.InsertEdge(0, 3);
	graph.InsertEdge(1, 1);
	graph.InsertEdge(1, 2);
	graph.InsertEdge(1, 3);
	graph.InsertEdge(2, 0);
	graph.InsertEdge(2, 3);
	graph.InsertEdge(3, 0);
	graph.PrintInfo();

	std::cout << graph.GetDegreeIn(2) << ' ' << graph.GetDegreeOut(2) << '\n';

	graph.RemoveEdge(3, 0);
	graph.PrintInfo();

	std::cout << graph.GetDegreeIn(2) << ' ' << graph.GetDegreeOut(2) << '\n';

	graph.RemoveNode(1);
	graph.PrintInfo();

	std::cout << graph.GetDegreeIn(2) << ' ' << graph.GetDegreeOut(2) << '\n';

	graph.Clear();
	graph.PrintInfo();
}