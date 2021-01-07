#include "CircularQueue.h"

#pragma region 생성자
/// <summary>
/// 비어있고 초기 용량을 가지는 CircularQueue를 생성한다.
/// </summary>
/// <param name="capacity">생성할 공간의 크기(기본: 10)</param>
CircularQueue::CircularQueue(size_t capacity)
	: m_capacity(capacity), m_count(0), m_front(0), m_rear(0)
{
	if (capacity < 0)
	{
		throw std::out_of_range("capacity");
	}
	m_items = new int[m_capacity] {0};
}

/// <summary>
/// 다른 CircularQueue와 동일한 값을 가지는 CircularQueue를 생성한다.
/// </summary>
/// <param name="other">기준이 될 CircularQueue</param>
CircularQueue::CircularQueue(const CircularQueue& other)
	: CircularQueue(other.m_capacity)
{
	m_count = other.m_count;
	for (size_t i = 0; i < m_capacity; i++)
	{
		m_items[i] = other.m_items[i];
	}

	m_front = other.m_front;
	m_rear = other.m_rear;
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// CircularQueue의 끝 부분에 값을 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void CircularQueue::Enqueue(int value)
{
	if (IsNeedToResize())
	{
		Resize();
	}

	m_items[m_front++] = value;
	m_count++;

	m_front = m_front % (m_capacity + 1);
}

/// <summary>
/// CircularQueue의 시작 부분을 제거하지 않고 반환한다.
/// </summary>
/// <returns>시작 부분에 있는 값</returns>
int CircularQueue::Peek()
{
	if (m_count <= 0)
	{
		throw std::out_of_range("empty");
	}

	return m_items[m_rear];
}

/// <summary>
/// CircularQueue의 시작 부분의 값을 제거한 뒤 반환한다.
/// </summary>
/// <returns>시작 부분에 있던 값</returns>
int CircularQueue::Dequeue()
{
	if (m_count <= 0)
	{
		throw std::out_of_range("empty");
	}

	int data{ m_items[m_rear++] };
	m_rear = m_rear % (m_capacity + 1);
	m_count--;

	return data;
}

/// <summary>
/// CircularQueue의 모든 값을 제거한다.
/// </summary>
void CircularQueue::Clear()
{
	m_front = m_rear = m_count = 0;
}

/// <summary>
/// CircularQueue에 지정한 값이 존재하는지 확인한다.
/// </summary>
/// <param name="value">CircularQueue에서 찾을 값</param>
/// <returns>값의 존재 여부</returns>
bool CircularQueue::Contains(int value)
{
	for (size_t i = 0, j = m_rear; i < m_count; i++)
	{
		if (m_items[j] == value)
		{
			return true;
		}

		j = (j + 1) % (m_capacity + 1);
	}
	return false;
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void CircularQueue::PrintInfo()
{
	std::cout << "Capacity: " << m_capacity << std::endl;
	std::cout << "Count: " << m_count << std::endl;
	std::cout << "front: " << m_front << std::endl;
	std::cout << "rear: " << m_rear << std::endl;
	std::cout << "Items: ";
	for (size_t i = 0, j = m_rear; i < m_count; i++)
	{
		std::cout << m_items[j] << ", ";
		j = (j + 1) % (m_capacity + 1);
	}
	std::cout << std::endl;
}
#pragma endregion

#pragma region Class Util
/// <summary>
/// CircularQueue에 count만큼의 값을 삽입할 수 있는지 확인한다.
/// </summary>
/// <returns>삽입 가능 여부</returns>
bool CircularQueue::IsNeedToResize()
{
	return m_capacity < m_count + 1;
}

/// <summary>
/// 데이터 삽입 시 공간이 부족한 경우 공간을 2배로 늘려준다.
/// </summary>
void CircularQueue::Resize()
{
	int* newItems{ new int[m_capacity * 2]{ 0 } };
	for (size_t i = 0; i < m_count; i++)
	{
		newItems[i] = m_items[m_rear++];
		m_rear = m_rear % (m_capacity + 1);
	}

	m_capacity *= 2;
	m_rear = 0;
	m_front = m_count;

	delete[] m_items;
	m_items = newItems;
}
#pragma endregion