#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;

    //initialising a linked list
    list<int> l1 = {1, 2, 3, 4};
    for (auto it = l1.begin(); it != l1.end(); it++)
    {
        cout << (*it) << ",";
    }
    cout << endl;
    //making a list containing strings
    list<string> l2 = {"apple", "mango", "guava ", "pear"};

    //adding to the end of the list
    l2.push_back("pineapple");
    for (string s : l2)
    {
        cout << s << "-->";
    }
    cout << endl;

    //using inbuilt sort function
    l2.sort();
    for (string s : l2)
    {
        cout << s << "-->";
    }
    cout << endl;

    //usinhg inbuilt reverse function
    l2.reverse();
    for (string s : l2)
    {
        cout << s << "-->";
    }
    cout << endl;

    //removing string from the front of the list
    l2.pop_front();
    cout << l2.front() << endl;

    //add to the front of the list
    l2.push_front("kiwi");
    for (string s : l2)
    {
        cout << s << "-->";
    }
    cout << endl;

    //Printing the last string in the list
    cout << l2.back() << endl;
    l2.pop_back();
    cout << l2.back() << endl;
    return 0;
}