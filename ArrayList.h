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
	int& Item(int index) { return index < m_count ? m_items[index] : throw std::out_of_range("index"); }
#pragma endregion

#pragma region 메소드
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

#pragma region Class Util
private:
	bool IsNeedToResize(int insertCount = 1);
	void Resize();
	void MoveToRight(int index, int insertCount = 1);
	void MoveToLeft(int index, int removeCount = 1);
#pragma endregion

private:
#pragma region 변수
	size_t m_capacity;
	size_t m_count;
	int* m_items;
#pragma endregion
};