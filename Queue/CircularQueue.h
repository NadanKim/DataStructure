#pragma once
#include <xutility>
#include <iostream>

class CircularQueue
{
public:
#pragma region 생성자
	CircularQueue(size_t capacity = 10);
	CircularQueue(const CircularQueue& other);
#pragma endregion

#pragma region 속성
	const size_t Capacity() { return m_capacity; }
	const size_t Count() { return m_count; }
	int& Item(size_t index) {
		if (index >= m_count)
		{
			throw std::out_of_range("index");
		}
		return m_items[index];
	}
#pragma endregion

#pragma region 메서드
	void Enqueue(int value);

	int Peek();
	int Dequeue();
	void Clear();

	bool Contains(int value);

	void PrintInfo();
#pragma endregion

#pragma region Class Util
	bool IsNeedToResize();
	void Resize();
#pragma endregion

private:
#pragma region 변수
	size_t m_capacity;
	size_t m_count;
	int* m_items;

	size_t m_front;
	size_t m_rear;
#pragma endregion
};