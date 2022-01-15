#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack
{
private:
    queue<T> q1, q2;

public:
    void push(T x)
    {
        q1.push(x);
    }
    void pop()
    {
        //condition if the queue q1 is already empty
        if (q1.empty())
        {
            return;
        }
        //remove the first n-1 elements in the queue q2
        //remove the last element in q1;
        // rename the q1 as q2 and q2 as q1
        while (q1.size() > 1)
        {
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }

    T top()
    {
        //if the queue is empty
        if (q1.empty())
        {
            return NULL;
        }
        while (q1.size() > 1)
        {
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        T temp = q1.front();
        q2.push(temp);
        q1.pop();
        swap(q1, q2);
        return temp;
    }

    T size()
    {
        return q1.size() + q2.size();
    }

    bool empty()
    {
        return size() == 0;
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}