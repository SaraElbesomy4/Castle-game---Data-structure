#ifndef ENEMYHEAP_H
#define ENEMYHEAP_H

#include "..\Enemies\Enemy.h"
#include <iostream>

using namespace std;

template <int const MAX_HEAP_SIZE=100>
class Enemyheap
{

private:
	Enemy*	Elements[MAX_HEAP_SIZE];             // Array of pointers
	int size;									// Number of elements in the heap
public:
	Enemyheap();							// Parameterized constructor
	~Enemyheap();                           // Destructor
	void ReheapDown(int root);				// Reheap after removing item
	void ReheapUp(int child_index);		    // Reheap after inserting item
	bool Enqueue(Enemy *item);				// Add an item to the heap
	Enemy *Dequeue();				       // Get item at the root
	int GetSize();						   // Return number of elements in the heap
	void printPriotity();                  // Print all the elements in the heap
};

template <int const MAX_HEAP_SIZE>
Enemyheap<MAX_HEAP_SIZE>::Enemyheap()
{
	size = 0;
}

//---------------------------------------
// Destructor
//---------------------------------------
template <int const MAX_HEAP_SIZE>
Enemyheap<MAX_HEAP_SIZE>::~Enemyheap()
{

}

//---------------------------------------
// Reheap after removing item
//---------------------------------------
template <int const MAX_HEAP_SIZE>
void Enemyheap<MAX_HEAP_SIZE>::ReheapDown(int root)
{
	int maxChild_index;
	int leftChild_index;
	int rightChild_index;
	Enemy *temp;

	leftChild_index = root * 2 + 1;          // Get index of root's left child
	rightChild_index = root * 2 + 2;          // Get index of root's right child

	// Check base case in recursive calls.  If leftChild's index is less
	// than or equal to the bottom index we have not finished recursively 
	// reheaping.
	if (leftChild_index <= (size-1))
	{
		if (leftChild_index == (size-1))          // If this root has no right child then 
		{
			maxChild_index = leftChild_index;     //     leftChild must hold max key
		}
		else
		{     // Get the one lowest in the tree (highest index in the array)
			if (Elements[leftChild_index]->GetPriority() <= Elements[rightChild_index]->GetPriority())
				maxChild_index = rightChild_index;
			else
				maxChild_index = leftChild_index;
		}
		if (Elements[root]->GetPriority() < Elements[maxChild_index]->GetPriority())
		{
			// Swap these two elements
			temp = Elements[root];
			Elements[root] = Elements[maxChild_index];
			Elements[maxChild_index] = temp;
			// Make recursive call till reheaping completed
			ReheapDown(maxChild_index);
		}
	}
}

//---------------------------------------
// Reheap after inserting item
//---------------------------------------
template <int const MAX_HEAP_SIZE>
void Enemyheap<MAX_HEAP_SIZE>::ReheapUp(int child_index)
{
	int parent_index;
	Enemy *temp;

	// Check base case in recursive calls.  If bottom's index is greater
	// than the root index we have not finished recursively reheaping.
	if (child_index > 0)
	{
		parent_index = (child_index - 1) / 2;
		if (Elements[parent_index]->GetPriority() < Elements[child_index]->GetPriority())
		{
			// Swap these two elements
			temp = Elements[parent_index];
			Elements[parent_index] = Elements[child_index];
			Elements[child_index] = temp;
			// Make recursive call till reheaping completed
			ReheapUp(parent_index);
		}
	}
}

//---------------------------------------
// Add an item to the heap
//---------------------------------------
template <int const MAX_HEAP_SIZE>
bool Enemyheap<MAX_HEAP_SIZE>::Enqueue(Enemy *item)
{
	if (size < MAX_HEAP_SIZE && item != nullptr)
	{
		Elements[size] = item; // Copy item into array
		ReheapUp(size);
		size++;
		return true;
	}
	return false;
}

//---------------------------------------
// Get item at the root
//---------------------------------------
template <int const MAX_HEAP_SIZE>
Enemy *Enemyheap<MAX_HEAP_SIZE>::Dequeue()
{
	if (size <= 0)
		return nullptr;

	Enemy *temp = Elements[0];
	size--;
	// Copy last item into root
		Elements[0] = Elements[size];

		// Reheap the tree
		ReheapDown(0);
	return temp;
}

//---------------------------------------
// Return number of elements in the heap
//---------------------------------------
template <int const MAX_HEAP_SIZE>
int Enemyheap<MAX_HEAP_SIZE>::GetSize()
{
	return size;
}

//---------------------------------------
// Print all the elements in the heap
//---------------------------------------
template <int const MAX_HEAP_SIZE>
void Enemyheap<MAX_HEAP_SIZE>::printPriotity()
{
	for (int i = 0; i<size; i++)
	{
		cout << "Heap element " << i << ". key=" << Elements[i]->GetPriority() << endl;
	}
}


#endif