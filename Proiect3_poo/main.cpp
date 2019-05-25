#include <iostream>
#include <cassert>
using namespace std;


template <class T,unsigned n>
class Vector
{
    T* vect;

public:

    // Constructor cu parametru care initializeaza tot vectorul  cu o valoare data
    Vector(T a)
    {
        vect=new T[n];
        for(int i=0; i<n; i++)
            vect[i]=a;
    }


    //constructor de copiere
    Vector(const Vector<T,n> &my_vect)
    {
        vect=new T[n];
        for(int i=0; i<n; i++)
            vect[i]=my_vect.vect[i];
    }

    //metoda care returneaza lungimea vectorului
    unsigned getSize()
    {
        return n;
    }


    // supraincarcarea operatorului + pentru adunarea a doi vectori
    Vector<T,n>& operator+(const Vector <T,n> &my_vect)
    {
        Vector<T,n> *sol=new Vector<T,n>(0);
        for(int i=0; i<n; i++)
            (*sol).vect[i]=(*this).vect[i]+my_vect.vect[i];

        return *sol;
    }

    // supraincarcarea operatorului - pentru adunarea a doi vectori
    Vector<T,n>& operator-(const Vector <T,n> &my_vect)
    {
        Vector<T,n> *sol=new Vector<T,n>(0);
        for(int i=0; i<n; i++)
            (*sol).vect[i]=(*this).vect[i]-my_vect.vect[i];

        return *sol;
    }

    // metoda care returneaza vectorul
    T* getVect()
    {
        return vect;
    }

    //supraincarcarea op [] pentru afisarea elementului de pe o anumita pozitie
    T operator [](int j)
    {
            return vect[j];
    }


    //operatoul * pentru produs vectorial
     T operator *(const Vector <T,n> &my_vect)
    {
        T produs_scalar=0;
        for(int i=0; i<n; i++)
            produs_scalar=produs_scalar + (*this).vect[i]*my_vect.vect[i];

         return produs_scalar;


    }


    // supraincarcarrea operatorului de afisare
    friend ostream &operator <<(ostream &out, const Vector <T,n> &my_vect)
    {
        for(int i=0 ; i < n; i++)
             out<<my_vect.vect[i]<<" ";

    return out;
    }

   // supraincarcarea operatorului de atribuire
   Vector<T,n>  & operator=(const Vector <T,n> &my_vect)
   {
       for(int i=0; i<n; i++)
            (*this).vect[i]=my_vect.vect[i];

        return *this;


   }

    //destructor
    ~Vector(){

    delete vect;

    }
};


// supraicarcarea operaorului * pentru inmultirea cu scalar la stanga
template <class T,unsigned n>
Vector<T,n> operator*(int x, Vector<T,n> my_vect )
{
    Vector<T,n> *sol=new Vector<T,n>(0);
    for(int i=0; i<n; i++)
        (*sol).getVect()[i]=x*my_vect.getVect()[i];

    return *sol;

}


int main()
{
    Vector <int,4>my_vect(3);
    assert(my_vect.getSize()==4);
    cout<<my_vect<<endl;

    Vector<int,4>a(my_vect);
    assert(a.getSize()==4);
    cout<<a<<endl;

    Vector<int,4>b(2*my_vect);
    assert(b.getSize()==4);
    cout<<b<<endl;
    cout<<b.getVect()[2];
    assert(b.getVect()[2]==6);
    cout<<endl;
    cout<<a*b;
    assert(a*b==72);
    cout<<endl;
    cout<<a;
    a=2*a;
    cout<<endl<<a;


    return 0;
}
