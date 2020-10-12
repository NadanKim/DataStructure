#include <iostream>
#include "LinkedList/SinglyLinkedList.h"

// 생성한 자료구조 테스트용 메인
int main()
{
    SinglyLinkedList a;
    a.Add(1);
    a.PrintInfo();

    a.Add(2);
    a.PrintInfo();

    a.Add(new SinglyLinkedListNode(11));
    a.PrintInfo();

    a.Insert(0, 0);
    a.PrintInfo();

    a.Insert(10, new SinglyLinkedListNode(22));
    a.PrintInfo();
}