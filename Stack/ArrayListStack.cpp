#include "ArrayListStack.h"

#pragma region 생성자
/// <summary>
/// 비어있고 초기 용량을 가지는 ArrayListStack를 생성한다.
/// </summary>
/// <param name="capacity">생성할 공간의 크기(기본: 10)</param>
ArrayListStack::ArrayListStack(int capacity)
	: m_top(0), m_items(capacity)
{
}

/// <summary>
/// 다른 ArrayListStack와 동일한 값을 가지는 ArrayListStack를 생성한다.
/// </summary>
/// <param name="other">기준이 될 ArrayListStack</param>
ArrayListStack::ArrayListStack(const ArrayListStack& other)
	: m_top(other.m_top), m_items(other.m_items)
{
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void ArrayListStack::PrintInfo()
{
	std::cout << "Top: " << m_items.Item(m_top) << std::endl;
	std::cout << "Items: ";
	for (size_t i = 0; i< m_items.Count(); i++)
	{
		std::cout << m_items.Item(i) << ", ";
	}
	std::cout << std::endl;
}
#pragma endregion