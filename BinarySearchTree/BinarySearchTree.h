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
	const int Max()
	{
		if (m_root == nullptr)
			return 0;

		Node* target{ m_root };

		while (target->m_left != nullptr)
		{
			target = target->m_left;
		}

		return target->m_data;
	}
	const int Min()
	{
		if (m_root == nullptr)
			return 0;

		Node* target{ m_root };

		while (target->m_right != nullptr)
		{
			target = target->m_right;
		}

		return target->m_data;
	}
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

	Node* m_root;
	Node* m_free;
#pragma endregion
};