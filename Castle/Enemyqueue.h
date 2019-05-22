#pragma once
#include "..\Enemies\Enemy.h"

template <int Array_Size=75>
class Enemyqueue
{
public:
	Enemyqueue();
	bool IsEmpty() const;
	bool Enqueue(Enemy* &newEntry);
	bool Dequeue(Enemy* &frntEntry);
	bool PeekFront(Enemy* &frntEntry)  const;
	void SortFD();	//sort last patch of killed enemies have enqueue recently
	int GetSize();
	void ReverseQueue();
	~Enemyqueue();

private:
	int front, back, size, Last_sorted;
	Enemy* Array[Array_Size];
};

template <int Array_Size>
Enemyqueue<Array_Size>::Enemyqueue()
{
	front = -1;
	back = -1;
	size = 0;
	Last_sorted = 0;
}
template <int Array_Size>
bool Enemyqueue<Array_Size>::IsEmpty() const
{
	return (size == 0);
}

template <int Array_Size>
bool Enemyqueue<Array_Size>::Enqueue(Enemy* &newEntry)
{
	if (size == Array_Size)
		return false;

	back++;
	Array[back % Array_Size] = newEntry;
	if (IsEmpty())
		front = back;
	size++;
	return true;
}



template <int Array_Size>
bool Enemyqueue<Array_Size>::Dequeue(Enemy* &frntEntry)
{
	if (IsEmpty())
		return false;
	
	frntEntry = Array[front % Array_Size];
	front++;
	size--;
	return true;
}

template <int Array_Size>
bool Enemyqueue<Array_Size>::PeekFront(Enemy* &frntEntry)  const
{
	if (IsEmpty())
		return false;

	frntEntry = Array[front % Array_Size];
	return true;
}

template <int Array_Size>
void Enemyqueue<Array_Size>::ReverseQueue()
{
	for (int i = 0; i < size/2; i++)
	{
		T temp = Array[front % Array_Size + i];
		Array[front % Array_Size + i] = Array[back % Array_Size - i];
		Array[back % Array_Size - i] = temp;
	}
}

template <int Array_Size>
void Enemyqueue<Array_Size>::SortFD()
{
	for (int i = Last_sorted; i < size - 1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (Array[i]->GetFD() > Array[j]->GetFD())
			{
				Enemy* temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
				
		}
	}

	Last_sorted = size;
}
template <int Array_Size>
Enemyqueue<Array_Size>::~Enemyqueue()
{

}

template <int Array_Size>
int Enemyqueue<Array_Size>::GetSize()
{
	return size;
}

