#include <iostream>
#include <vector>		// 배열 첨자가 가능한 vector사용

// Heap으로 간단하게 Binary Tree (배열) 만들기

class Heap
{
	std::vector<int> mHeap;

public:
	void Insert(int value)
	{
		mHeap.push_back(value);

		// 부모보다 크면 바꾸고 -> 위로 올라가서 -> 부모보다 크면 바꾸고 ...

		// 인덱스 0번부터 사용하자 => 부모인덱스 공식 = (자식 - 1) / 2
		int i = static_cast<int>(mHeap.size() - 1);		// 현재 인덱스
		int parent = (i - 1) / 2;						// 정수이므로 소수점 잘려나감

		// root(인덱스 0) 까지 반복
		while (i != 0 && value > mHeap[parent])
		{
			mHeap[i] = mHeap[parent];
			mHeap[parent] = value;
			// Insert하는 값이 이동하므로 별도의 저장변수 temp 필요없이 value 사용가능

			i = parent;
			parent = (i - 1) / 2;
		}
	}
	// Time Complexity  = O(log n)
	// Space Complexity = O(n)

	void Print()
	{
		for (auto& e : mHeap)
		{
			std::cout << e << " ";
		}

		std::cout << std::endl;
	}

	int Pop()
	{
		if (mHeap.size() == 0)		// 아무것도 안들어있으면
		{
			return 0;
		}

		// 1. pop할 원소(인덱스 0번 원소)와 가장 뒤의 원소 change
		int item = mHeap.front();
		mHeap[0] = mHeap.back();
		mHeap.pop_back();

		// 2. 크기 비교를 하며 내려가면서 트리 모양 다시 맞추기
		int i{};		// 현재 인덱스 = 0;
		while (i < mHeap.size())		// 현재인덱스가 사이즈보다 넘지않을때까지
		{
			int child = (i * 2) + 1;	// 인덱스가 0일 때, 왼쪽 자식 인덱스
			if (child >= mHeap.size())	// child 인덱스가 사이즈를 넘을 때
			{
				break;
			}

			if (child + 1 < mHeap.size() && mHeap[child] < mHeap[child + 1])
			{	// child + 1 인덱스가 사이즈를 넘을 때 && 오른쪽 자식이 더 클 때
				child++;				// child = 오른쪽 자식 인덱스
			}

			if (mHeap[i] >= mHeap[child])
			{
				break;
			}

			std::swap(mHeap[i], mHeap[child]);

			i = child;
		}

		return item;
	}
	// Space Complexity : O(n)
	// Time Complexity  : O(log n)
};

int main()
{
	Heap h;

	h.Insert(1);
	h.Insert(2);
	h.Insert(3);
	h.Insert(4);
	h.Insert(5);
	h.Insert(6);
	h.Insert(7);
	h.Insert(8);

	h.Print();

	for (int i = 0; i < 8; i++)		// 정렬의 Time Complexity = n * log n
	{
		std::cout << h.Pop() << " ";
	}
	std::cout << std::endl;
}
