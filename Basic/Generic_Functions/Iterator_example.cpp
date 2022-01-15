#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

/*template <typename T>
int search(T a[], int n, T key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return p;
        }
    }
    return n;
}
*/

/*
//Template +Iterators
template <class ForwardIterator, class T> //either we can write typename or we can write class (it is the same thing )
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key)
{
    while (start != end)
    {
        if (*start == key)
        {
            return start;
        }
        start++;
    }
    return end;
}
*/

//Template +Iterators + comparators
template <class ForwardIterator, class T, class Compare> //either we can write typename or we can write class (it is the same thing )
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while (start != end)
    {
        if (*start, key)
        {
            return start;
        }
        start++;
    }
    return end;
}

class Book
{
public:
    string name;
    int price;

    Book()
    {
    }
    Book(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
};

class bookcompare
{

public:
    bool operator()(Book A, Book B)
    {
        if (A.name == B.name)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Book b1("C++", 100); //Old edition of the book
    Book b2("Python", 200);
    Book b3("Java", 150);

    vector<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book booktofind("C++", 110); //new edition of the book

    bookcompare cmp;
    auto it = search(l.begin(), l.end(), booktofind, cmp);
    if (it != l.end())
    {
        cout << "Book found in the library" << endl;
    }
    else
    {
        cout << "Book not found in the library" << endl;
    }
    /*
    //Code for Templates + Iterators
    if (cmp(b1, booktofind))
    {
        cout << "True same books" << endl;
    }
    else
    {
        cout << "False , Not the same books" << endl;
    }
    */
    /*
    int a[] = {1, 3, 4, 6, 8, 10, 12};
    int n = sizeof(a) / sizeof(int);
    int key = 10;
    cout << search(a, n, key) << endl;
    */
    /*list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(3);
    auto it = search(l.begin(), l.end(), 5);
    if (it == l.end())
    {
        cout << " Element not present" << endl;
    }
    else
    {

        cout << *it << endl;
    }
    */
    return 0;
}