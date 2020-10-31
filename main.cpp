#include <iostream>
#include "LinkedList/SinglyCircularLinkedList.h"

// 생성한 자료구조 테스트용 메인
int main()
{
	SinglyCircularLinkedList a;
	a.Insert(0, 1);
	a.Insert(0, 2);
	a.Insert(2, 3);
	a.PrintInfo();
}