#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Queue
{
private:
    stack<T> s1, s2;

public:
    void push_rear(T x)
    {
        s1.push(x);
    }
    void pop()
    {
        //if the stack 1 is already empty we cannot pop out any elemt as there is no element
        if (s1.empty())
        {
            return;
        }
        //else we need to first transfer n-1 elements in the other stack then we need to pop the last element in stack 1
        while (s1.size() > 1)
        {
            T element = s1.top();
            s1.pop();
            s2.push(element);
        }
        s1.pop();
        swap(s1, s2);
    }

    T front()
    {
        if (s1.empty())
        {
            return NULL;
        }
        //else we need to first transfer n-1 elements in the other stack then we need to pop the last element in stack 1
        while (s1.size() > 1)
        {
            T element = s1.top();
            s1.pop();
            s2.push(element);
        }
        T temp = s1.top();
        s2.push(temp);
        s1.pop();
        swap(s1, s2);
        return temp;
    }
    bool empty()
    {
        return (s1.size() + s2.size()) == 0;
    }
};

int main()
{
    Queue<int> q;
    q.push_rear(1);
    q.push_rear(2);
    q.push_rear(2);
    q.push_rear(3);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}