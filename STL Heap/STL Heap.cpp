#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	// C++ 20
	std::vector<int> v{ 1,2,3,4,5 };

	std::make_heap(v.begin(), v.end());		// 컨테이너를 heapify(heap화) 

	for (auto& e : v)
	{
		std::cout << e << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;

	while (!v.empty())
	{
		std::cout << v.front() << std::endl;
		std::pop_heap(v.begin(), v.end());
		// heap은 자료구조가 아닌 알고리즘이므로 꺼낸 후, 다시 힙화할 필요가 있다
		// 힙화한 컨테이너는 std::push_heap 과 std::pop_heap 을 통해서
		// 원소가 추가되거나 빠졌음을 알려줘야한다.
		// std::pop_heap는 Pop()을 힙화 한 느낌이다.

		v.pop_back();
		// pop_heap은 실제 원소를 제거하는 것이 아닌 
		// 첫 원소와 마지막 원소를 바꾸는 행위일 뿐
		// 실제 원소를 지우려면 컨테이너의 기능을 이용해야한다.
		// pop은
		// 힙화 후 원소 제거

		// push는
		// v.push_back(1);
		// std::push_heap(v.begin(), v.end());
		// 같이 집어넣고 힙화한다. <pop과 반대>
	}
}