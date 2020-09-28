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

ArrayList::~ArrayList()
{
	if (m_items != nullptr)
	{
		delete[] m_items;
	}
}
#pragma endregion

#pragma region 메소드
/// <summary>
/// ArrayList의 끝에 값을 추가한다.
/// </summary>
/// <param name="value">ArrayList 끝에 추가할 값</param>
/// <returns>값이 추가된 인덱스</returns>
int ArrayList::Add(int value)
{
	if (IsNeedToResize())
	{
		Resize();
	}
	m_items[m_count] = value;

	return m_count++;
}

/// <summary>
/// ArrayList의 끝에 다른 ArrayList를 추가한다.
/// </summary>
/// <param name="other">ArrayList 끝에 추가할 다른 ArrayList</param>
void ArrayList::AddRange(const ArrayList& other)
{
	while (IsNeedToResize(other.m_count))
	{
		Resize();
	}

	for (int i = 0; i < other.m_count; i++)
	{
		m_items[m_count++] = other.m_items[i];
	}
}

/// <summary>
/// ArrayList의 지정된 인덱스에 값을 추가한다.
/// </summary>
/// <param name="index">값을 추가할 인덱스</param>
/// <param name="value">추가할 값</param>
void ArrayList::Insert(int index, int value)
{
	if (index > m_count)
	{
		throw std::out_of_range("index");
	}

	if (IsNeedToResize())
	{
		Resize();
	}

	MoveToRight(index);
	m_items[index] = value;
	m_count++;
}

/// <summary>
/// ArrayList의 지정된 인덱스에 다른 ArrayList를 추가한다.
/// </summary>
/// <param name="index">다른 ArrayList를 추가할 인덱스</param>
/// <param name="other">추가할 다른 ArrayList</param>
void ArrayList::InsertRange(int index, const ArrayList& other)
{
	if (index > m_count)
	{
		throw std::out_of_range("index");
	}

	while (IsNeedToResize(other.m_count))
	{
		Resize();
	}

	MoveToRight(index, other.m_count);
	for (int i = 0; i < other.m_count; i++)
	{
		m_items[index + i] = other.m_items[i];
	}
	m_count += other.m_count;
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

#pragma region Class Util
/// <summary>
/// ArrayList에 count만큼의 값을 삽입할 수 있는지 확인한다.
/// </summary>
/// <param name="count">삽입할 값의 개수(기본: 1)</param>
/// <returns>삽입 가능 여부</returns>
bool ArrayList::IsNeedToResize(int insertCount)
{
	return m_capacity < m_count + insertCount;
}

/// <summary>
/// 데이터 삽입 시 공간이 부족한 경우 공간을 2배로 늘려준다.
/// </summary>
void ArrayList::Resize()
{
	int* newItems = new int[m_capacity * 2]{ 0 };
	for (int i = 0; i < m_capacity; i++)
	{
		newItems[i] = m_items[i];
	}
	m_capacity *= 2;

	delete[] m_items;
	m_items = newItems;
}

/// <summary>
/// 삽입을 위한 공간 확보를 위해 기존 값을 오른쪽으로 이동시킨다.
/// </summary>
/// <param name="index">데이터를 삽입할 인덱스</param>
/// <param name="insertCount">삽입할 값의 개수(기본: 1)</param>
void ArrayList::MoveToRight(int index, int insertCount)
{
	for (int i = m_count - 1; i >= index; i--)
	{
		m_items[i + insertCount] = m_items[i];
	}
}
#pragma endregion
