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

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(11);
    a.Add(newNode);
    a.PrintInfo();

    a.Insert(0, 0);
    a.PrintInfo();

    a.Insert(10, new SinglyLinkedListNode(22));
    a.PrintInfo();

    a.Remove(1);
    a.PrintInfo();

    a.Add(11);
    a.PrintInfo();

    if (a.Contains(11))
    {
        std::cout << a.FindLast(11) << '\n';
    }
}