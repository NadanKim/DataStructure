#include "ArrayList.h"

#pragma region 생성자
ArrayList::ArrayList(size_t capacity)
	: m_capacity(capacity), m_count(0)
{
	m_items = new int[m_capacity] {0};
}

ArrayList::ArrayList(const ArrayList& other)
	: ArrayList(other.m_capacity)
{
	m_count = other.m_count;
	for (int i = 0; i < m_capacity; i++)
	{
		m_items[i] = other.m_items[i];
	}
}
#pragma endregion

#pragma region 메소드
int ArrayList::Add(int value)
{
	return 0;
}

void ArrayList::AddRange(const ArrayList& other)
{
}

void ArrayList::Insert(int index, int value)
{
}

void ArrayList::InsertRange(int index, ArrayList& other)
{
}

void ArrayList::Remove(int value)
{
}

void ArrayList::RemoveAt(int index)
{
}

void ArrayList::RemoveRange(int index, int count)
{
}

void ArrayList::Clear()
{
}

bool ArrayList::Contains(int value)
{
	return false;
}

int ArrayList::IndexOf(int value)
{
	return 0;
}

int ArrayList::LastIndexOf(int value)
{
	return 0;
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void ArrayList::PrintInfo()
{
	std::cout << "Capacity: " << m_capacity << std::endl;
	std::cout << "Count: " << m_count << std::endl;
	std::cout << "Items: ";
	for (int i = 0; i < m_capacity; i++)
	{
		std::cout << m_items[i] << ", ";
	}
	std::cout << std::endl;
}
#pragma endregion