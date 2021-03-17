#pragma once
#include <iostream>

class BinarySearchTree
{
public:
#pragma region 노드
	struct Node
	{
		Node() {}
		Node(int value) { m_data = value; }

		int m_data{ 0 };
		Node* m_left{ nullptr };
		Node* m_right{ nullptr };
	};
#pragma endregion

#pragma region 생성자
	BinarySearchTree();
	~BinarySearchTree();
#pragma endregion

#pragma region 속성
	const size_t Count() { return m_count; }
	const int Max() { return m_max; }
	const int Min() { return m_min; }
#pragma endregion

#pragma region 메서드
	void Insert(int value);

	void Delete(int value);
	void Clear();

	bool Search(int value);

	void PrintInfo();
private:
	void PrintInfo(Node* node, size_t depth = 0);
#pragma endregion

private:
#pragma region Class Util
	Node* PopNode(int value);
	void PushNode(Node* node);
#pragma endregion

#pragma region 변수
	size_t m_count;
	int m_min;
	int m_max;

	Node* m_root;
	Node* m_free;
#pragma endregion
};