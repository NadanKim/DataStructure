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

	DoublyLinkedList b(a);
	b.PrintInfo();
}