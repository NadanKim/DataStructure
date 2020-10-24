#include <iostream>
#include "LinkedList/DoublyLinkedList.h"

// 생성한 자료구조 테스트용 메인
int main()
{
	DoublyLinkedList a;
	a.AddFirst(1);
	a.PrintInfo();
	a.AddLast(2);
	a.PrintInfo();
	a.Insert(0, 0);
	a.PrintInfo();
	a.Insert(1, 3);
	a.PrintInfo();

	DoublyLinkedListNode* newNode = new DoublyLinkedListNode(111);

	a.Insert(1, newNode);
	a.PrintInfo();

	a.Remove(newNode);
	a.PrintInfo();

	a.AddFirst(22);
	a.AddLast(22);
	a.PrintInfo();

	a.RemoveFirst(22);
	a.PrintInfo();

	a.AddFirst(22);
	a.PrintInfo();

	a.RemoveLast(22);
	a.PrintInfo();
}