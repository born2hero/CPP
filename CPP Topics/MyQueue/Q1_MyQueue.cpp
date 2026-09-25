#include <iostream>

#define SIZE 100

class MyQueue
{
private:
    /* data members */
    int size;
    int front;
    int rear;
    int *arr;
    int count;

public:
    MyQueue(int size = SIZE);
    void Push(int);
    int Pop();
    void Display();
    int sizeQueue();
    bool isEmpty();
    bool isFull();
    ~MyQueue();
};

MyQueue::MyQueue(int size)
{
    arr = new int[size];
    size = SIZE;
    front = 0;
    rear = -1;
    count = 0;
}

void MyQueue::Push(int value)
{
    if (isFull())
    {
        std::cout << "Overflow\nProgram Terminated" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Inserting value: " << value << std::endl;
    rear = (rear + 1) % size;
    arr[rear] = value;
    count++;
}

int MyQueue::Pop()
{
    if (isEmpty())
    {
        std::cout << "Empty queue" << std::endl;
        exit(EXIT_FAILURE);
    }

    int x = arr[front];
    front = (front + 1) % size;
    count--;
    return x;
}

void MyQueue::Display()
{
}

int MyQueue::sizeQueue()
{
    return count;
}

bool MyQueue::isEmpty()
{
    if (sizeQueue() == 0)
    {
        std::cout << "Empty queue" << std::endl;
    }
}

bool MyQueue::isFull()
{
    if (sizeQueue() == size)
    {
        std::cout << "Full queue" << std::endl;
    }
}

MyQueue::~MyQueue()
{
    delete[] arr;
}

int main()
{
    MyQueue q(5);

    q.Push(1);
    q.Push(2);
    q.Push(3);

    q.Pop();

    q.Push(4);

    std::cout << "The queue size is " << q.sizeQueue() << std::endl;

    q.Pop();
    q.Pop();
    q.Pop();

    if (q.isEmpty())
    {
        std::cout << "The queue is empty\n";
    }
    else
    {
        std::cout << "The queue is not empty\n";
    }

    return 0;
}