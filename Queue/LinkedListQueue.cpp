﻿#include "LinkedListQueue.h"

#pragma region 생성자
/// <summary>
/// 비어있고 초기 용량을 가지는 LinkedListQueue를 생성한다.
/// </summary>
/// <param name="capacity">생성할 공간의 크기(기본: 10)</param>
LinkedListQueue::LinkedListQueue(int capacity)
	: m_items(capacity)
{
}

/// <summary>
/// 다른 LinkedListQueue와 동일한 값을 가지는 LinkedListQueue를 생성한다.
/// </summary>
/// <param name="other">기준이 될 LinkedListQueue</param>
LinkedListQueue::LinkedListQueue(const LinkedListQueue& other)
	: m_items(other.m_items)
{
}
#pragma endregion

#pragma region 메서드
/// <summary>
/// LinkedListQueue의 끝 부분에 값을 추가한다.
/// </summary>
/// <param name="value">추가할 값</param>
void LinkedListQueue::Enqueue(int value)
{
	m_items.Add(value);
}

/// <summary>
/// LinkedListQueue의 시작 부분을 제거하지 않고 반환한다.
/// </summary>
/// <returns>시작 부분에 있는 값</returns>
int LinkedListQueue::Peek()
{
	if (m_items.Count() <= 0)
	{
		throw std::out_of_range("empty");
	}

	return m_items.Item(0);
}

/// <summary>
/// LinkedListQueue의 시작 부분의 값을 제거한 뒤 반환한다.
/// </summary>
/// <returns>시작 부분에 있던 값</returns>
int LinkedListQueue::Dequeue()
{
	if (m_items.Count() <= 0)
	{
		throw std::out_of_range("empty");
	}

	int data{ m_items.Item(0) };
	m_items.RemoveAt(0);

	return data;
}

/// <summary>
/// LinkedListQueue의 모든 값을 제거한다.
/// </summary>
void LinkedListQueue::Clear()
{
	m_items.Clear();
}

/// <summary>
/// LinkedListQueue에 지정한 값이 존재하는지 확인한다.
/// </summary>
/// <param name="value">LinkedListQueue에서 찾을 값</param>
/// <returns>값의 존재 여부</returns>
bool LinkedListQueue::Contains(int value)
{
	return m_items.Contains(value);
}

/// <summary>
/// 테스트용 리스트 정보 출력 함수
/// </summary>
void LinkedListQueue::PrintInfo()
{
	std::cout << "Front: " << m_items.Count() - 1 << std::endl;
	m_items.PrintInfo();
}
#pragma endregion