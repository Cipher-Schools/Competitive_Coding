#include <bits/stdc++.h>
using namespace std;

// Array Implementation
template <class T>
class ArrayStack
{
  private:
    T *S;
    int capacity;
    int index;

  public:
    ArrayStack(int capacity)
    {
        this->capacity = capacity;
        this->index = -1;
        this->S = new T[this->capacity];
    }

    bool Empty()
    {
        return (this->index == -1);
    }

    bool Full()
    {
        return (this->index >= this->capacity);
    }

    void Push(T data)
    {
        if (this->Full())
        {
            throw "ArrayStack overflow";
        }
        else
        {
            this->S[++this->index] = data;
        }
    }

    void Pop()
    {
        if (this->Empty())
        {
            throw "ArrayStack underflow";
        }
        else
        {
            this->index--;
        }
    }

    T Top()
    {
        if (this->Empty())
        {
            throw "ArrayStack underflow";
        }
        else
        {
            return this->S[this->index];
        }
    }

    int Size()
    {
        return (this->index + 1);
    }
};