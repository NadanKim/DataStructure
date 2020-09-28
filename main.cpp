#include <iostream>
#include "ArrayList.h"

// 생성한 자료구조 테스트용 메인
int main()
{
    ArrayList a;
    a.Add(3);
    a.Add(67);
    a.Add(3);
    a.Add(67);
    a.Add(3);
    a.Add(67);
    a.Add(3);
    a.Add(67);
    a.Add(3);
    a.Add(67);
    a.Add(3);
    a.PrintInfo();

    ArrayList b;
    b.Add(3333);
    b.AddRange(a);
    b.Add(11111);
    b.AddRange(a);
    b.PrintInfo();

    ArrayList c;
    c.Add(123456);
    c.AddRange(b);
    c.PrintInfo();

    a.Insert(2, 444);
    a.PrintInfo();

    a.InsertRange(3, c);
    a.PrintInfo();
}