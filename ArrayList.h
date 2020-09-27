#pragma once
#include <xutility>
#include <iostream>

class ArrayList
{
public:
#pragma region 생성자
	ArrayList(size_t capacity = 10);
	ArrayList(const ArrayList& other);
#pragma endregion

#pragma region 속성
	const size_t Capacity() { return m_capacity; }
	const size_t Count() { return m_count; }
	int& Item(int index) { return m_items[index]; }
#pragma endregion

#pragma region 메소드
	int Add(int value);
	void AddRange(const ArrayList& other);
	void Insert(int index, int value);
	void InsertRange(int index, ArrayList& other);

	void Remove(int value);
	void RemoveAt(int index);
	void RemoveRange(int index, int count);
	void Clear();

	bool Contains(int value);
	int IndexOf(int value);
	int LastIndexOf(int value);

	void PrintInfo();
#pragma endregion

private:
#pragma region 변수
	size_t m_capacity;
	size_t m_count;
	int* m_items;
#pragma endregion
};