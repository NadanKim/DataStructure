#include "ArrayList.h"

#pragma region 생성자
/// <summary>
/// 비어있고 초기 용량을 가지는 ArrayList를 생성한다.
/// </summary>
/// <param name="capacity">생성할 공간의 크기(기본: 10)</param>
ArrayList::ArrayList(int capacity)
	: m_capacity(capacity), m_count(0)
{
	if (capacity < 0)
	{
		throw std::out_of_range("capacity");
	}
	m_items = new int[m_capacity] {0};
}

/// <summary>
/// 다른 ArrayList와 동일한 값을 가지는 ArrayList를 생성한다.
/// </summary>
/// <param name="other">기준이 될 ArrayList</param>
ArrayList::ArrayList(const ArrayList& other)
	: ArrayList(other.m_capacity)
{
	m_count = other.m_count;
	for (int i = 0; i < m_capacity; i++)
	{
		m_items[i] = other.m_items[i];
	}
}

/// <summary>
/// 메모리 누수를 막기 위해 동적 생성한 데이터 영역을 제거한다.
/// </summary>
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
	if (index < 0 || index > m_count)
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
	if (index < 0 || index > m_count)
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
}

/// <summary>
/// ArrayList에서 가장 먼저 발견되는 값을 제거한다.
/// </summary>
/// <param name="value">제거할 값</param>
void ArrayList::Remove(int value)
{
	int index = IndexOf(value);
	if (index != -1)
	{
		MoveToLeft(index);
	}
}

/// <summary>
/// ArrayList에서 지정된 인덱스의 값을 제거한다.
/// </summary>
/// <param name="index">제거할 인덱스(조건: 0이상)</param>
void ArrayList::RemoveAt(int index)
{
	if (index < 0 || index >= m_count)
	{
		throw std::out_of_range("index");
	}

	MoveToLeft(index);
}

/// <summary>
/// ArrayList에서 지정된 범위의 값을 제거한다.
/// </summary>
/// <param name="index">제거할 범위의 시작 인덱스</param>
/// <param name="count">제거할 값 개수</param>
void ArrayList::RemoveRange(int index, int count)
{
	if (index < 0)
	{
		throw std::out_of_range("index");
	}
	else if (count < 0)
	{
		throw std::out_of_range("count");
	}

	if (index >= m_count)
	{
		throw std::invalid_argument("index");
	}
	else if (count > m_count - index)
	{
		throw std::invalid_argument("count");
	}

	MoveToLeft(index, count);
}

/// <summary>
/// ArrayList의 모든 값을 제거한다.
/// </summary>
void ArrayList::Clear()
{
	m_count = 0;
}

/// <summary>
/// ArrayList에 지정한 값이 존재하는지 확인한다.
/// </summary>
/// <param name="value">ArrayList에서 찾을 값</param>
/// <returns>값의 존재 여부</returns>
bool ArrayList::Contains(int value)
{
	return IndexOf(value) != -1;
}

/// <summary>
/// ArryList을 앞에서 부터 지정한 값을 검사해 인덱스를 반환한다.
/// </summary>
/// <param name="value">ArrayList에서 잦을 값</param>
/// <returns>값의 인덱스(없으면 -1)</returns>
int ArrayList::IndexOf(int value)
{
	for (int i = 0; i < m_count; i++)
	{
		if (m_items[i] == value)
		{
			return i;
		}
	}
	return -1;
}

/// <summary>
/// ArryList을 뒤에서 부터 지정한 값을 검사해 인덱스를 반환한다.
/// </summary>
/// <param name="value">ArrayList에서 잦을 값</param>
/// <returns>값의 인덱스(없으면 -1)</returns>
int ArrayList::LastIndexOf(int value)
{
	for (int i = m_count - 1; i >= 0; i--)
	{
		if (m_items[i] == value)
		{
			return i;
		}
	}
	return -1;
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void ArrayList::PrintInfo(bool isShowAll)
{
	std::cout << "Capacity: " << m_capacity << std::endl;
	std::cout << "Count: " << m_count << std::endl;
	std::cout << "Items: ";
	for (int i = 0, limit = isShowAll ? m_capacity : m_count; i < m_count; i++)
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
	m_count += insertCount;
}

/// <summary>
/// 제거 이후 빈 공간 제거를 위해 값을 왼쪽으로 이동시킨다.
/// </summary>
/// <param name="index">데이터를 삭제할 인덱스</param>
/// <param name="removeCount">삭제할 값의 개수(기본: 1)</param>
void ArrayList::MoveToLeft(int index, int removeCount)
{
	for (int i = index; i < m_count - removeCount; i++)
	{
		m_items[i] = m_items[i + removeCount];
	}
	m_count -= removeCount;
}
#pragma endregion
