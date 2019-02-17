#include <iostream>

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

    T& Front();

    T& operator[](const int index);
    const T& operator[](const int index) const;

private:

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

    int &a = dq.Front();
    cout << a << endl;

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
T &MyDeque<T>::Front()
{
    return *(this->LeftSide);
}

template<typename T>
T &MyDeque<T>::operator[](const int index)
{
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

template<typename T>
const T &MyDeque<T>::operator[](const int index) const
{
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
