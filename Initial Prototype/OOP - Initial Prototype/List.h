#pragma once
#include <assert.h> 

template <typename T>
struct node
{
    node(const T& data);
    T data;
    node* next;
};

template <class T>
node<T>::node(const T& data) : data(data), next(nullptr)
{
}

template <typename T>
class List
{
public:
    ~List();                            //Destructor                            [X]
    bool isEmpty() const;               //Bool check if list is empty           [X]
    const T first() const;              //Return first item in list             [X]
    const T last() const;               //Return last item in list              [X]
    void addInFront(const T&);          //Insert an item infront                [X]
    void addAtPos(int pos, const T&);   //Insert at specif position             [X]
    void addAtEnd(const T&);            //Insert Item at end                    [X]
    void deleteFirst();                 //Delete first item                     [X]
    void deleteLast();                  //Delete last item                      [ ]
    void deleteAtPos(int pos);          //Delete item at position               [ ]
    void deleteOne(const T&);           //Delete first occurrence of item       [ ]
    int length() const;                 //Return Length                         [X]
    bool contains(const T&) const;      //Check if an item is in the list       [ ]
    T getAt(int pos);                   //Get value at position                 [ ]  
    node<T>* getNext(int pos) const;    //Return next node pointer              [X]
private: 
    node<T>* start;                     //Points onto first item
    node<T>* end() const;               //Return address of last item
    void destroy();                     //Delete all items in list              [X]
    void copy(const List<T>&);          //Make a copy of the list
};

template <class T>
bool List<T>::isEmpty() const
{
    return start == nullptr;
}

template <class T>
const T List<T>::first() const
{
    assert(start != nullptr);
    return start->data;
}

template <class T>
const T List<T>::last() const
{
    assert(start != nullptr);
    return end()->item;
}

template <typename T>
void List<T>::addInFront(const T& val)
{
    //Create a node with data to add
    node<T> *temp = new node<T>(val); 
    assert(temp != nullptr); //ensure new node is not null
    temp->next = start; //Set the next node of new node as the head
    start = temp; //Set the head to point at new node
}

template <typename T>
void List<T>::addAtPos(int pos, const T& val)
{
    if (pos == 0)
    {
        addInFront(val);
    }
    else if (pos == 1 && length() == 1)
    {
        addAtEnd(val);
    }
    else 
    {
        node<T>* prev; //holds previous node
        node<T>* curr; //holds current node
        curr = start; //set current node at the start
        prev = start;
        for (int i = 1; i < pos; i++)
        {
            prev = curr; //previous node stores current node
            curr = curr->next; //current node moves to next node
        }
        node<T>* temp = new node<T>(val);
        temp->next = curr; //once at posiotion, set new node to be added to point at next node
        prev->next = temp; //set previous node to point at new node
    }

}

template <typename T>
void List<T>::addAtEnd(const T& val)
{
    //Create a node with data to add
    node<T>* temp = new node<T>(val);
    assert(temp != nullptr); //ensure new node is not null

    if (start == nullptr)
    {
        start = temp;
    }
    else
    {
        end()->next = temp;
    }
}

template <typename T>
void List<T>::deleteFirst()
{
    if (isEmpty()) return; //if there is a first item

    node<T>* temp = start; //store it in temp
    start = start->next; //set start to point at next node

    delete temp; //delete temp off heap
}

template <typename T>
int List<T>::length() const
{
    if (isEmpty()) return 0; //if empty list length must be 0

    int length = 1; //length has to be one because there is a start
    node<T>* temp = start;
    while (temp->next != nullptr) //increase length until you reach end
    {
        length += 1;
        temp = temp->next;
    }
    return length;
}

template <typename T>
T List<T>::getAt(int pos)
{
    node<T>* curr; //holds current node
    curr = start; //set current node at the start
    for (int i = 1; i <= pos; i++)
    {
        curr = curr->next; //current node moves to next node
    }
    
    return curr->data;
}

template <typename T>
node<T>* List<T>::getNext(int pos) const
{
    node<T>* curr; //holds current node
    curr = start; //set current node at the start
    for (int i = 1; i <= pos; i++)
    {
        curr = curr->next; //current node moves to next node
    }

    return curr->next;
}

template <class T>
bool List<T>::contains(const T& val) const
{
    for (node<T>* pn = start; pn != nullptr; pn = pn->next)
    {
        if (pn->data == val)
        {
            return true;
        }
    }

    return false;
}

// private support operations
// --------------------------
template <class T>
node<T>* List<T>::end() const
{
    node<T>* plast = start;

    while (plast->next != nullptr)
    {
        plast = plast->next;
    }

    return plast;
}

template <typename T>
void List<T>::destroy()
{
    while (!isEmpty()) //clears list
    {
        deleteFirst();
    }
}

template <class T>
void List<T>::copy(const List<T>& other)
{
    assert(start == nullptr);

    if (other.start == nullptr) return;

    start = new node<T>(other.start->item);
    assert(start != nullptr);

    node<T>* pnew = start;
    for (node<T>* porig = other.start->next; porig != nullptr; porig = porig->next)
    {
        pnew->next = new node<T>(porig->item);
        assert(pnew->next != nullptr);
        pnew = pnew->next;
    }
}

template <typename T>
List<T>::~List()
{
    destroy(); //destructs list when out of scope
}