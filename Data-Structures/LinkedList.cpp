#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

template<class t>
struct Node{
    t data;
    Node* next;
    Node(t data):data(data)
    {
        next=NULL;
    }
};
template<class type>
class LinkedList{
    Node<type>* head=NULL;
    int size;
public:
    bool empty()
    {
        //return head==NULL;
        return size==0;
    }
    void push_front(type val)
    {
        Node<type>* temp=new Node<type>(val);
        temp->next=head;
        head=temp;
        delete temp;
        size++;
    }
    void push_back(type val)
    {
        if(head==NULL)
            head=new Node<type>(val);
        else
        {
            Node<type>* temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=new Node<type>(val);
            //delete temp;
            //temp=NULL;
        }
        size++;
    }
    Node<type>* search(type val)
    {
        Node<type>* temp=head;
        while(temp)
            if(temp->data==val)
                return temp;
            else
                temp=temp->next;
        delete temp;
        return nullptr;
    }
    void print()
    {
        Node<type>* temp=head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        delete temp;
    }
};
int main()
{
    fastIO();
    LinkedList<int> l;
    l.push_back(5);
    l.print();
    l.push_back(6);
    l.print();
    return 0;
}
