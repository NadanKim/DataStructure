#pragma once

class ArrayList
{
public:
	// 积己磊
	ArrayList();
	ArrayList(ArrayList& other);
	ArrayList(int capacity);

	// 加己
	const size_t Capacity() { return m_capacity; }
	const size_t Count() { return m_count; }
	int& Item(int index) { return m_items[index]; }

	// 皋辑靛
	int Add(int value);
	void AddRange(ArrayList& other);
	void Insert(int index, int value);
	void InsertRange(int index, ArrayList& other);

	void Remove(int value);
	void RemoveAt(int index);
	void RemoveRange(int index, int count);
	void Clear();

	bool Contains(int value);
	int IndexOf(int value);
	int LastIndexOf(int value);

private:
	size_t m_capacity;
	size_t m_count;
	int* m_items;
};