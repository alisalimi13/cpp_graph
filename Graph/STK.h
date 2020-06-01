// In The Name Of Allah

class STK
{
private:
	int top;
	int a[10];
	int size;

public:
	STK();
	~STK();
	void push(int);
	int pop();
	int showTop();
	int showTopValue();
};

STK::STK()
{
	top = -1;
	size = 10;
}

STK::~STK()
{
	top = -1;
	size = 0;
}

void STK::push(int n)
{
	if (top >= size - 1)
		return;

	a[++top] = n;
	return;
}

int STK::pop()
{
	if (top < 0)
		return -1;

	return a[top--];
}

int STK::showTop()
{
	return top;
}

int STK::showTopValue()
{
	return a[top];
}