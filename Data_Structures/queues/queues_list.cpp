#include <iostream>
#include <list>
using namespace std;

class Queue
{
private:
    int cs;
    list<int> l;

public:
    Queue()
    {
        cs = 0;
    }

    bool empty()
    {
        return cs == 0;
    }

    void push(int data)
    {
        l.push_back(data);
        cs = cs + 1;
    }
    void pop()
    {
        if (!empty())
        {
            l.pop_front();
            cs--;
        }
    }
    int front()
    {
        return l.front();
    }
};

int main()
{
    Queue q;
    for (int i = 0; i <= 10; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}