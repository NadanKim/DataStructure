#include <iostream>
#include "ArrayList.h"

// 생성한 자료구조 테스트용 메인
int main()
{
    ArrayList a;
    a.PrintInfo();

    ArrayList b(30);

    b.Item(0) = 30;
    b.PrintInfo();

    ArrayList c(b);
    c.PrintInfo();
}