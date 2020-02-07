#include <bits/stdc++.h>

class Node
{
    Node next = NULL;
    int data;

    public node(int d)
    {
        data = d;
    }

    void append(int d)
    {
        Node end = new Node(d);
        Node n = this; 

        while(n.next != NULL)
        {
            n = n.next
        }

        n.next = end;
    }
}