#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

int main()
{
    unordered_map<string, vector<string>> phonebook;
    phonebook["Rahul"].push_back("9110");
    phonebook["Rahul"].push_back("9111");
    phonebook["Rahul"].push_back("9112");
    phonebook["Rahul"].push_back("9113");
    phonebook["Kajal"].push_back("8110");
    phonebook["Kajal"].push_back("8111");
    phonebook["Kajal"].push_back("8112");

    for (auto s : phonebook)
    {
        cout << s.first << " -> ";
        for (auto n : s.second)
        {
            cout << n << ",";
        }
        cout << endl;
    }

    string name;
    cin >> name;

    if (phonebook.count(name) == 0)
    {
        cout << "Absent" << endl;
    }
    else
    {
        for (auto p : phonebook[name])
        {
            cout << p << endl;
        }
    }
    return 0;
}