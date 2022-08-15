#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;


template<class t>
class vec{
    t* arr{nullptr};
    int size{0}; //user size
    int capacity{0}; //actual size
    void expandCap()
    {
        capacity*=2;
        t* temp=new t[capacity];
        for(int i=0;i<size;i++)
            temp[i]=arr[i];
        arr=temp;
        delete[] temp;
        temp=nullptr;
    }
public:
    vec(int size):size(size)
    {
        assert(size>=0);
        capacity=size+10;
        arr=new t[capacity];
    }
    vec(int size,t val):size(size)
    {
        assert(size>=0);
        capacity=size+10;
        arr=new t[capacity]{val};
    }
    ~vec()
    {
        delete[] arr;
        arr=nullptr;
    }
    void push_back(t val)
    {
        if(size==capacity)
            expandCap();
        arr[size++]=val;
    }
    void pop()
    {
        size--;
    }
    void insert(int idx,t val)
    {
        assert(idx>=0&&idx<size);
        if(size==capacity)
            expandCap();
        for(int i=size-1;i>idx;i--)
            arr[i]=arr[i-1];
        arr[idx]=val;
        size++;
    }
    t& operator[](int idx) //We must return by reference in function because an expression like “arr[i]” can be used an lvalue.
    {
        assert(idx>=0&&idx<size);
        return arr[idx];
    }
};

int main()
{
    fastIO();
    vec<int> v(5);
    for(int i=0;i<5;i++)
    {
        v[i]=i;
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.pop();
    v.push_back(77);
    cout<<v[4];
    return 0;
}
