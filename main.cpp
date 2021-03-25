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

	bst.Delete(5);
	bst.PrintInfo();

	std::cout << std::boolalpha << bst.Search(5) << '\n';
	std::cout << std::boolalpha << bst.Search(9) << '\n';

	bst.Clear();
	bst.PrintInfo();
}