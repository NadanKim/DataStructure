#include "SinglyLinkedList.h"

#pragma region 생성자
#pragma endregion

#pragma region 메서드
void SinglyLinkedList::PrintInfo()
{
	std::cout << "Count: " << m_count << std::endl;
	std::cout << "Nodes: ";
	SinglyLinkedListNode* curNode = m_head;
	while (curNode != nullptr)
	{
		std::cout << curNode->m_data << ", ";
		curNode = curNode->m_next;
	}
	std::cout << std::endl;
}
#pragma endregion