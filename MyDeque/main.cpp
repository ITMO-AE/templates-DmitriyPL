#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class MyDeque
{

public:
    MyDeque();
    ~MyDeque();

    int Size();
    bool Empty();

    void PushBack(T data);
    void PushFront(T data);
    void PopFront();
    void Clear();

    T& At(int index);
    const T& At(int index) const;

    T& Front();
    const T& Front() const;

    T& Back();
    const T& Back() const;

    T& operator[](const int index);
    const T& operator[](const int index) const;

private:

    T& GetDataForIndex(int index);

    class Node
    {
    public:
        Node(T data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }

        T data;
        Node *pNext;
        Node *pPrev;
    };

    int size;
    Node *LeftSide;
    Node *RigthSide;
};


int main()
{
    MyDeque<int> dq;

    dq.PushBack(5);
    dq.PushBack(6);
    dq.PushFront(10);
    dq.PushFront(21);
    dq.PushBack(16);

    for (int i = 0; i < dq.Size(); i++)
        cout << dq[i] << " ";

    cout << endl << "Size dq = " << dq.Size() << endl;

    cout << dq.Front() << endl;
    cout << dq.Back() << endl;

    dq[0] = 100;

    cout << dq[0] << endl;

    dq.PopFront();

    cout << dq[0] << endl;

    for (int i = 0; i < dq.Size(); i++)
        cout << dq[i] << " ";

    cout << endl;

    dq.At(2) = 30;

    cout << dq.At(2) << endl;

    dq.Clear();

    cout << dq.Size() << endl;

    dq.PushBack(50);
    dq.PushBack(60);
    dq.PushFront(100);
    dq.PushFront(210);
    dq.PushBack(160);

    for (int i = 0; i < dq.Size(); i++)
        cout << dq[i] << " ";

    cout << endl;

//    dq.At(20) = 30; //Out of range

    return 0;
}

template<typename T>
MyDeque<T>::MyDeque():
    size(0),
    LeftSide(nullptr),
    RigthSide(nullptr)
{}

template<typename T>
MyDeque<T>::~MyDeque()
{
    Clear();
}

template<typename T>
int MyDeque<T>::Size()
{
    return size;
}

template<typename T>
bool MyDeque<T>::Empty()
{
    return (size == 0);
}

template<typename T>
void MyDeque<T>::PushBack(T data)
{
    if (RigthSide == nullptr)
    {
        RigthSide = new Node(data);
        LeftSide = RigthSide;
    }
    else
    {
        Node *newNode = new Node(data);
        RigthSide->pNext = newNode;
        newNode->pPrev = RigthSide;
        RigthSide = newNode;
    }
    size++;
}

template<typename T>
void MyDeque<T>::PushFront(T data)
{
    if (LeftSide == nullptr)
    {
        LeftSide = new Node(data);
        RigthSide = LeftSide;
    }
    else
    {
        Node *newNode = new Node(data);
        LeftSide->pPrev = newNode;
        newNode->pNext = LeftSide;
        LeftSide = newNode;
    }
    size++;
}

template<typename T>
void MyDeque<T>::PopFront()
{
    if (size == 1)
    {
       Node *tmp = LeftSide;
       LeftSide = nullptr;
       RigthSide = nullptr;
       delete tmp;
    }
    else
    {
        Node *tmp = LeftSide;
        LeftSide = LeftSide->pNext;
        LeftSide->pPrev = nullptr;
        delete tmp;
    }
    size--;
}

template<typename T>
void MyDeque<T>::Clear()
{
    while (size)
    {
        PopFront();
    }
}

template<typename T>
T &MyDeque<T>::Front()
{
    return this->LeftSide->data;
}

template<typename T>
const T &MyDeque<T>::Front() const
{
    return this->LeftSide->data;
}

template<typename T>
T &MyDeque<T>::Back()
{
   return this->RigthSide->data;
}

template<typename T>
const T &MyDeque<T>::Back() const
{
    return this->RigthSide->data;
}

template<typename T>
T &MyDeque<T>::At(int index)
{
    GetDataForIndex(index);
}

template<typename T>
const T &MyDeque<T>::At(int index) const
{
    try {
        GetDataForIndex(index);
    } catch (out_of_range) {}

}

template<typename T>
T &MyDeque<T>::operator[](const int index)
{
    try {
        GetDataForIndex(index);
    } catch (out_of_range) {}
}

template<typename T>
const T &MyDeque<T>::operator[](const int index) const
{
    try {
        GetDataForIndex(index);
    } catch (out_of_range) {}
}

template<typename T>
T &MyDeque<T>::GetDataForIndex(int index)
{
    if (index < 0 || index > size) throw out_of_range{"Invalid index"};

    if (index == 0)
        return LeftSide->data;
    if (index == size-1)
        return RigthSide->data;

    if (index <= size/2)
    {
        int counter = 0;
        Node *current = this->LeftSide;
        while (current != nullptr )
        {
            if (counter == index)
                return current->data;

            current = current->pNext;
            counter++;
        }
    }
    else
    {
        int counter = size-1;
        Node *current = this->RigthSide;
        while (current != nullptr )
        {
            if (counter == index)
                return current->data;

            current = current->pPrev;
            counter--;
        }
    }
}
