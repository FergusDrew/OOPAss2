#pragma once
#include <assert.h> 

template <typename T>
struct node
{
    T data;
    node* next;
};

template <typename T>
class List
{
public:
    ~List();                            //Destructor                            [X]
    bool isEmpty() const;                     //Bool check if list is empty           [X]
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
private: 
    node<T>* start;                     //Points onto first item
    node<T>* end;                       //Return address of last item
    void destroy();                     //Delete all items in list              [X]
    void copy(const List<T>&);          //Make a copy of the list
};

template <typename T>
bool List<T>::isEmpty() const
{
    if (start == nullptr) return true;
    return false;
}

template <typename T>
const T List<T>::first() const
{
    node<T>* temp = new node<T>;
    if (isEmpty()) return;

    temp = start;
    return temp;
}

template <typename T>
const T List<T>::last() const
{
    node<T>* temp = new node<T>;
    if (isEmpty()) return;

    temp = start;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp = end;
    return end;
}

template <typename T>
void List<T>::addInFront(const T& val)
{
    //Create a node with data to add
    node<T> *temp; 
    temp = new node<T>;
    temp->data = val;
    assert(temp != nullptr); //ensure new node is not null
    temp->next = start; //Set the next node of new node as the head
    start = temp; //Set the head to point at new node
}

template <typename T>
void List<T>::addAtPos(int pos, const T& val)
{
    node<T>* prev = new node<T>; //holds previous node
    node<T>* curr = new node<T>; //holds current node
    node<T> *temp;
    temp = new node<T>; //holds new node with data to be added
    temp->data = val;
    curr = start; //set current node at the start
    for (int i = 1; i < pos; i++)
    {
        prev = curr; //previous node stores current node
        curr = curr->next; //current node moves to next node
    }
    temp->next = curr; //once at posiotion, set new node to be added to point at next node
    prev->next = temp; //set previous node to point at new node
}

template <typename T>
void List<T>::addAtEnd(const T& val)
{
    node<T>* temp;
    temp = new node<T>; //holds new node with data to be added
    temp->data = val;
    node<T>* prev = new node<T>; //holds end node

    prev = end; //holds end
    prev->next = temp; //sets old end to point at new node
    end = temp; //sets end to point at new node
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
    node<T>* prev = new node<T>; //holds previous node
    node<T>* curr = new node<T>; //holds current node
    curr = start; //set current node at the start
    for (int i = 1; i <= pos; i++)
    {
        prev = curr; //previous node stores current node
        curr = curr->next; //current node moves to next node
    }

    return curr->data;
}


template <typename T>
void List<T>::destroy()
{
    while (!isEmpty()) //clears list
    {
        deleteFirst();
    }
}

template <typename T>
List<T>::~List()
{
    destroy(); //destructs list when out of scope
}