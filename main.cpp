#include <iostream>
#include "ArrayList/ArrayList.h"

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
    b.Add(11111);
    b.PrintInfo();

    ArrayList c;
    c.Add(123456);
    c.AddRange(b);
    c.PrintInfo();

    a.Remove(67);
    a.Remove(67);
    a.Remove(67);
    a.Remove(67);
    a.Remove(67);
    a.Remove(67);
    a.PrintInfo();

    b.RemoveRange(1, 0);
    b.PrintInfo();

    c.Clear();
    c.PrintInfo();

    std::cout << a.IndexOf(3) << std::endl;
    std::cout << std::boolalpha << a.Contains(67) << std::endl;
    std::cout << a.IndexOf(67) << std::endl;
    std::cout << a.LastIndexOf(3) << std::endl;
}