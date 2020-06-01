// In The Name Of Allah

class Queue
{
private:
	int a[10];
	int size;
	int front;
	int back;

public:
	Queue();
	void push(int);
	int pop();
	int showFront();
	int showBack();
	int showFrontValue();
	int showBackValue();
};

Queue::Queue()
{
	size = 10;
	front = 0;
	back = -1;
}

void Queue::push(int n)
{
	if (back >= size - 1)
		return;

	a[++back] = n;
	return;
}

int Queue::pop()
{
	if (front > back)
		return -1;

	return a[front++];
}

int Queue::showFront()
{
	return front;
}

int Queue::showBack()
{
	return back;
}

int Queue::showFrontValue()
{
	return a[front];
}

int Queue::showBackValue()
{
	return a[back];
}