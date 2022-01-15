#include <iostream>
using namespace std;

//Defining a vector class - user defined vector
class Vector
{
    //Data members and some functions
    int *arr;
    int cs; //Current size
    int maxsize;

public:
    Vector(int defaultSize = 4)
    {
        maxsize = defaultSize;
        cs = 0;
        arr = new int[maxsize];
    }
    void pushback(int data)
    {
        if (cs == maxsize)
        {
            //Dobling of the array size operation
            int *oldArr = arr;
            arr = new int[2 * maxsize];
            maxsize *= 2;
            //Copying all the elements of the old array into the new larger array
            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldArr[i];
            }
            //deleting the old array
            delete[] oldArr;
        }
        //else loop operation
        arr[cs] = data;
        cs++;
    }
    bool empty()
    {
        return cs == 0;
    }
    void pop_back()
    {
        if (!empty())
        {
            cs--;
        }
    }
    void print() const
    {
        for (int i = 0; i < cs; i++)
        {
            cout << arr[i] << " ";
        }
    }
    int at(int i) const
    {
        return arr[i];
    }
    int getcurrentsize() const
    {
        return cs;
    }
    int getmaxsize() const
    {
        return maxsize;
    }
    void operator()(string s)
    {
        cout << s << " is an awesome place " << endl;
    }
    int operator[](int i)
    {
        return arr[i];
    }
    ostream &operator<<(ostream &os)
    {
        v.print();
        return os;
    }
};

int main()
{
    Vector v(1000);
    v("Dehradun");
    Vector fun;
    //Looking like a function but , it is an object [Functor = Functional object]
    fun("Nainital");

    for (int i = 0; i <= 3; i++)
    {
        v.pushback(i * i);
    }
    cout << v.getmaxsize() << endl;
    v.pushback(7);
    cout << v.getmaxsize() << endl;
    v.print();
    cout << endl;
    for (int i = 0; i < v.getcurrentsize(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << v;
    return 0;
}