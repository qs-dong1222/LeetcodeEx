#include<cstdlib>
#include<iostream>

using namespace std;

class P{
public:
    int data;

    int foo(){
        cout << "pppppp" << endl;
        return this->data;
    }
};



class C : public P{
public:
    int data;

    int foo(){
        cout << "ccccc" << endl;
        return this->data + P::data;
    }
};



int main(){
    P p;
    C c;

    p.data = 10;
    c.data = 2;

    cout << c.foo() << endl;
    cout << p.foo() << endl;

    P * pointer_P = (P *)&c;
    cout << pointer_P->foo() << endl;

    return 0;
}
