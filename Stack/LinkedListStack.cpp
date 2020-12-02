#include "LinkedListStack.h"

#pragma region 생성자
/// <summary>
/// 비어있고 초기 용량을 가지는 LinkedListStack을 생성한다.
/// </summary>
LinkedListStack::LinkedListStack()
{
}

/// <summary>
/// 다른 LinkedListStack과 동일한 값을 가지는 LinkedListStack을 생성한다.
/// </summary>
/// <param name="other">기준이 될 LinkedListStack</param>
LinkedListStack::LinkedListStack(const LinkedListStack& other)
	: m_items(other.m_items)
{
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// LinkedListStack의 맨 위에 값을 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void LinkedListStack::Push(int value)
{
	m_items.Add(value);
}

/// <summary>
/// LinkedListStack의 최상위 값을 제거하지 않고 반환한다.
/// </summary>
/// <returns>최상위에 있는 값</returns>
int LinkedListStack::Peek()
{
	if (m_items.Count() <= 0)
	{
		throw std::out_of_range("empty");
	}
	
	return m_items.Front().m_data;
}

/// <summary>
/// LinkedListStack의 최상위 값을 제거한 뒤 반환한다.
/// </summary>
/// <returns>최상위에 있던 값</returns>
int LinkedListStack::Pop()
{
	if (m_items.Count() <= 0)
	{
		throw std::out_of_range("empty");
	}

	int data{ m_items.Front().m_data };
	m_items.Remove(&m_items.Front());

	return data;
}

/// <summary>
/// LinkedListStack의 모든 값을 제거한다.
/// </summary>
void LinkedListStack::Clear()
{
	m_items.Clear();
}

/// <summary>
/// LinkedListStack에 지정한 값이 존재하는지 확인한다.
/// </summary>
/// <param name="value">LinkedListStack에서 찾을 값</param>
/// <returns>값의 존재 여부</returns>
bool LinkedListStack::Contains(int value)
{
	return m_items.Contains(value);
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void LinkedListStack::PrintInfo()
{
	std::cout << "Top: " << m_items.Count() - 1 << std::endl;
	m_items.PrintInfo();
}
#pragma endregion