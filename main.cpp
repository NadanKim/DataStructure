#include <iostream>
#include "LinkedList/DoublyCircularLinkedList.h"

// 생성한 자료구조 테스트용 메인
int main()
{
	DoublyCircularLinkedList a;
	a.AddFirst(1);
	a.AddFirst(2);
	a.AddFirst(3);
	a.PrintInfo();

	DoublyCircularLinkedListNode* newNode = new DoublyCircularLinkedListNode(4);
	a.AddLast(newNode);
	a.PrintInfo();

	a.Insert(4, 5);
	a.PrintInfo();

	a.AddLast(1);
	a.PrintInfo();

	a.Clear();
	a.PrintInfo();
}