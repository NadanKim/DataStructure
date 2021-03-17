#include <iostream>
#include "BinarySearchTree/BinarySearchTree.h"

// 생성한 자료구조 테스트용 메인
int main()
{
	BinarySearchTree bst;

	bst.Insert(5);

	bst.Insert(3);

	bst.Insert(1);

	bst.Insert(0);

	bst.Insert(4);

	bst.Insert(8);

	bst.Insert(7);

	bst.Insert(9);
	bst.PrintInfo();
}