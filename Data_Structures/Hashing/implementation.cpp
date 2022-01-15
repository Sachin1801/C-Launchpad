#include <iostream>
#include <cstring>
using namespace std;

// Impplement a Hash class
// Separate chaining technique
template <typename T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;
    Node(string key, T val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class Hashtable
{
    Node<T> **table; // double star becasue it is a pointer to a array of pointers
    int current_size;
    int table_size;

    int hashFn(string key)
    {
        int idx = 0;
        int p = 1;
        for (int j = 0; j < key.length(); j++)
        {
            idx = idx + (key[j] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }

    void Rehash()
    {
        Node<T> **oldTable = table;
        int oldtablesize = table_size;
        table_size = 2 * table_size;
        table = new Node<T> *[table_size];

        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
        current_size = 0;

        // shift the elements from the old table to the new one
        for (int i = 0; i < oldtablesize; i++)
        {
            Node<T> *temp = oldTable[i];
            if (temp != NULL)
            {
                insert(temp->key, temp->value);
            }
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    Hashtable(int ts = 7) // ts= table size
    {
        table_size = ts;
        table = new Node<T> *[table_size];
        current_size = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }
    void insert(string key, T value)
    {
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, value);
        // Insert at the head of the linked list at id- idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        // rehash..
        float load_factor = current_size / (1.0 * table_size);
        if (load_factor > 0.7)
        {
            Rehash();
        }
    }

    void Print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << "->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T *search(string key) // return type is a pointer value
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value; // we are returning here the address because if the key is not present then null is not the value
            }
            temp = temp->next;
        }
        return NULL; // type- T*
    }

    void erase(string key)
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
            }
        }
    }
    T &operator[](string key)
    {
        T *f = search(key);
        if (f == NULL)
        {
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return *f;
    }
};

int main()
{
    Hashtable<int> price_menu(7);
    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Roll", 100);
    price_menu.insert("Coke", 40);
    price_menu.Print();

    int *price = price_menu.search("Noodles");
    if (price == NULL)
    {
        cout << "Not Found";
    }
    else
    {
        cout << "Price of the item is " << *price;
    }

    // Treating it like a map with operator overloading
    // Insert
    price_menu["Dosa"] = 60;
    // Update
    price_menu["Dosa"] += 10;
    // Search
    cout << endl
         << "Price of Dosa is ";
    cout << price_menu["Dosa"] << endl;
    return 0;
}