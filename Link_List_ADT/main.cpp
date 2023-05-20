#include <iostream>
#include "Link_List_ADT.hpp"

int main()
{
	int arr[]={3,8,7,10,-2,-5};
	List<int> a(arr, 6); 
	a.merge_sort();
	a.output();
	std::cout << a.length()<< std::endl;
	return 0;
}