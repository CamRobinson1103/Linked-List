#pragma once
class Iterator
{
public:
    Node* myNode;

   Iterator<T>* operator++() { myNode = myNode->next; } // Solves the contiguous issue
    operator*() { return myNode->data; }  // protect the actual pointer

private:

};

