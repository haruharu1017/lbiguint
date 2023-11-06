#include "lbiguint.h"
#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

 lbiguint::lbiguint(){
    head=nullptr;
    tail=head;
 }
 lbiguint::lbiguint (const string & s)
 {
    head = nullptr;
    tail=nullptr;
    for(int i=0; i < s.length();i++)
    {
        int num = (int)s[i]-'0';
        head = new node(num, head);
        if(tail==nullptr) tail=head;
    }
 }

lbiguint::~lbiguint()
{
    head=nullptr;
    tail=nullptr;
}

int lbiguint::operator [](int pos) const
 {
    int n=0;
    node *temp = head;
    while(n<pos)
    {
        temp=temp->link();
        n++;
    }
    return temp->data();
 }

 int lbiguint::size() const{
    int s=0;
    for(node* curr=head; curr!=nullptr; curr=curr->link())
    {
        s++;
    }
    return s;
 }

ostream & operator << (ostream & is, const lbiguint & b)
{
    for(int i=0; i<b.size(); i++)
    {
        is<<b[i]<<" ";
    }
    return is;
}

/*
 int biguint::compare(const biguint & b) const{
     for(int i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
 }



 void biguint::operator += (const biguint & b){
     int carry = 0;
     int next = 0;
     for(int i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
string biguint::toStdString() const
 {
     stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
ostream & operator << (ostream & os, const biguint & b)
 {

     for (int i = biguint::CAPACITY - 1; i >= 0; --i)
         os << b[i];
     return os;
 }



 bool operator <(const biguint& a, const biguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) != 0);
 }

//You do > and >=
*/

int main()
{
    lbiguint b1("123");
    cout<<b1[2]<<endl;
    cout<<b1<<endl;

}