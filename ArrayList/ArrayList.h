#pragma once
#include <xutility>
#include <iostream>

class ArrayList
{
public:
#pragma region 생성자
	ArrayList(int capacity = 10);
	ArrayList(const ArrayList& other);
	~ArrayList();
#pragma endregion

#pragma region 속성
	const int Capacity() { return m_capacity; }
	const int Count() { return m_count; }
	int& Item(int index) { 
		if (index < 0 || index >= m_count)
		{
			throw std::out_of_range("index");
		}
		return m_items[index];
	}
#pragma endregion

#pragma region 메서드
	int Add(int value);
	void AddRange(const ArrayList& other);
	void Insert(int index, int value);
	void InsertRange(int index, const ArrayList& other);

	void Remove(int value);
	void RemoveAt(int index);
	void RemoveRange(int index, int count);
	void Clear();

	bool Contains(int value);
	int IndexOf(int value);
	int LastIndexOf(int value);

	void PrintInfo(bool isShowAll = false);
#pragma endregion

private:
#pragma region Class Util
	bool IsNeedToResize(int insertCount = 1);
	void Resize();
	void MoveToRight(int index, int insertCount = 1);
	void MoveToLeft(int index, int removeCount = 1);
#pragma endregion

#pragma region 변수
	size_t m_capacity;
	size_t m_count;
	int* m_items;
#pragma endregion
};