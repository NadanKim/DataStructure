#include <iostream>
#include "Queue/CircularQueue.h"

// 생성한 자료구조 테스트용 메인
int main()
{
	CircularQueue q(2);

	q.Enqueue(1);
	q.PrintInfo();

	q.Enqueue(2);
	q.PrintInfo();

	q.Enqueue(3);
	q.PrintInfo();

	q.Peek();
	q.PrintInfo();

	q.Dequeue();
	q.PrintInfo();

	q.Dequeue();
	q.PrintInfo();

	q.Dequeue();
	q.PrintInfo();

	q.Enqueue(1);
	q.PrintInfo();

	q.Enqueue(2);
	q.PrintInfo();

	q.Enqueue(3);
	q.PrintInfo();
}