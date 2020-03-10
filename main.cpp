#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

ifstream fin("ecuatie.in");

class Fractie
{
    int numarator;
    int numitor;

public:
    Fractie(int a=0,int b=1);///constructor de initializare
    Fractie(const Fractie &source);///constructor de copiere
    ~Fractie();///destructor
    int get_numarator();
    void set_numarator(int nr);
    int get_numitor();
    void set_numitor(int nr);
    void simplificare();
    void afisare();
    Fractie operator+(Fractie f);
    Fractie operator-(Fractie f);
    Fractie operator*(Fractie f);
    Fractie operator/(Fractie f);
    Fractie operator*(int n);
    friend istream& operator>>(istream& in, Fractie &f);
    friend ostream& operator<<(ostream& o,Fractie &f);


};

ostream&operator<<(ostream &o,Fractie&f)
{
    f.afisare();
    return o;
}

istream& operator>>(istream &in, Fractie &f)
{
    in>>f.numarator>>f.numitor;
    return in;
}


Fractie::Fractie(int a,int b)
{
    numarator=a;
    numitor=b;
}

Fractie::Fractie(const Fractie &source)
{
    numarator=source.numarator;
    numitor=source.numitor;
}

Fractie::~Fractie()
{
    ///cout<<"Destructor"<<endl;
}

int Fractie::get_numarator()
{
    return numarator;
}

void Fractie::set_numarator(int nr)
{
    numarator=nr;
}

int Fractie::get_numitor()
{
    return numitor;
}

void Fractie::set_numitor(int nr)
{
    numitor=nr;
}

void Fractie::simplificare()
{
    int n,d,a,b;
    if (numarator==0)
    {
        numarator=0;
        numitor=1;
    }
    else
    {
        a=numarator;
        b=numitor;
        n=abs(a);
        d=abs(b);
        while (n!=d)
            if (n>d)
                n=n-d;
            else
                d=d-n;
        if(a<0&&b<0)
        {
            numarator=abs(a/d);
            numitor=abs(b/d);
        }
        else
        {
            numarator=a/d;
            numitor=b/d;
        }
    }
}

void Fractie::afisare()
{
    if (numitor==1)
        cout<<numarator<<endl;
    else if ((numarator<0)^(numitor<0))
        cout<<'-'<<abs(numarator)<<'/'<<abs(numitor)<<endl;
    else
        cout<<numarator<<'/'<<numitor<<endl;

}

Fractie Fractie::operator+(Fractie f)
{
    Fractie rez;
    rez.numarator=(this->numarator)*f.numitor+(this->numitor)*f.numarator;
    rez.numitor=this->numitor*f.numitor;
    return rez;
}

Fractie Fractie::operator-(Fractie f)
{
    Fractie rez;
    rez.numarator=(this->numarator)*f.numitor-(this->numitor)*f.numarator;
    rez.numitor=this->numitor*f.numitor;
    return rez;
}

Fractie Fractie::operator*(Fractie f)
{
    Fractie rez;
    rez.numarator=(this->numarator)*f.numarator;
    rez.numitor=(this->numitor)*f.numitor;
    return rez;
}

Fractie Fractie::operator/(Fractie f)
{
    if (f.numarator==0)
    {
        Fractie ex;
        cout<<"Eroare-impartire la 0"<<endl;
        ex.set_numarator(1);
        ex.set_numitor(0);
        return ex;
    }
    Fractie rez;
    rez.numarator=(this->numarator)*f.numitor;
    rez.numitor=(this->numitor)*f.numarator;
    return rez;
}

Fractie Fractie::operator*(int n)
{
    Fractie rez;
    rez.numarator=(this->numarator)*n;
    rez.numitor=this->numitor;
    return rez;
}

int main()
{
    Fractie cx1,cy1,cx2,cy2,r1,r2,sub1,sub2,sub3,sub4,x,y;
    fin>>cx1>>cy1>>r1>>cx2>>cy2>>r2;
    fin.close();
    if (cx1.get_numarator()==0)
    {
        y=r1/cy1;           /// cum coeficientul lui x in prima ecuatie este 0, gasim direct y
        x=(r2-y*cy2)/cx2;   /// gasim x din a doua ecuatie, inlocuind y
        x.simplificare();
        y.simplificare();
        cout<<"x=";
        x.afisare();
        cout<<"y=";
        y.afisare();

    }
    else
    {
        sub1=r1/cx1;        ///
        sub2=(cy1*-1)/cx1;  /// scoatem x in functie de y din prima ecuatie
        sub3=cx2*sub1;      ///
        sub4=cx2*sub2;      /// inlocuim x in a doua ecuatie
        sub3=r2-sub3;       ///
        sub4=cy2+sub4;      /// trecem termenii liberi in partea dreapta
        y=sub3/sub4;
        x=sub1+sub2*y;
        x.simplificare();
        y.simplificare();
        cout<<"x=";
        x.afisare();
        cout<<"y=";
        y.afisare();
    }

    return 0;
}
