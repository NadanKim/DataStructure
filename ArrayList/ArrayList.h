#pragma once
#include <xutility>
#include <iostream>

class ArrayList
{
public:
#pragma region 생성자
	ArrayList(size_t capacity = 10);
	ArrayList(const ArrayList& other);
	~ArrayList();
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
	size_t Add(int value);
	void AddRange(const ArrayList& other);
	void Insert(size_t index, int value);
	void InsertRange(size_t index, const ArrayList& other);

	void Remove(int value);
	void RemoveAt(size_t index);
	void RemoveRange(size_t index, size_t count);
	void Clear();

	bool Contains(int value);
	int IndexOf(int value);
	int LastIndexOf(int value);

	void PrintInfo(bool isShowAll = false);
#pragma endregion

private:
#pragma region Class Util
	bool IsNeedToResize(size_t insertCount = 1);
	void Resize();
	void MoveToRight(size_t index, size_t insertCount = 1);
	void MoveToLeft(size_t index, size_t removeCount = 1);
#pragma endregion

#pragma region 변수
	size_t m_capacity;
	size_t m_count;
	int* m_items;
#pragma endregion
};