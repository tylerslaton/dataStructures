#include <iostream>
#include "ds/ds.h"
using namespace std;

int main()
{
    // Testing ground for new data structures
    BST newBST;
    Stack newStack(4);

    cout << newStack.Peek();
    newStack.Push(1);
    newStack.Push(2);
    newStack.Push(3);
    cout << newStack.Pop();
    cout << newStack.Pop();
    cout << newStack.Pop();
    cout << newStack.Pop();
    cout << newStack.Pop();
    
    return 0;
}