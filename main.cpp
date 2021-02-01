#include <iostream>

using namespace std;

struct Vektor{
    double x;
    double y;
    double z;

    Vektor( double xx = 0., double yy = 0., double zz=0.) : x(xx), y(yy), z(zz) {}


    double innerProd(const Vektor &v) const {
        return x*v.x + y*v.y + z*v.z;

    }
    Vektor crossProduct(const Vektor &v) const {
        return Vektor(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
    } //Poziva konstruktor sa datim vrednostima u zagradi
};

double innerProd(double x1, double x2, double x3, double y1, double y2, double y3){
     return x1*y1 + x2*y2 + x3*y3;
}
void crossProduct(double x1, double x2, double x3, double y1, double y2, double y3,
                  double &z1, double &z2, double &z3){

                   z1 = x2*y3 - x3*y2;
                   z2 = x3*y1 - x1*y3;
                   z3 = x1*y2 - x2*y1;
}
istream& operator>> (istream &in, Vektor  &v){
    in >> v.x >> v.y >> v.z;
    return in;
}

ostream& operator<< (ostream &out, const Vektor &v){
    out << "( " << v.x << " , " << v.y << " , " << v.z << " ) ";
    return out;
}

int main(){
    while(true){
   // double x1, x2, x3, y1, y2, y3;
    int izbor;
    int n ;
    cout << " \nUnesite broj elemenata niza: " << endl;
    cin >> n;
    Vektor niz[n];

    for (auto i = 0 ; i < n; ++i){
        cout << "Unesite koordinate " << i+1 << " vektora.";
        cin >> niz[i];
    }
    cout << "Uneli ste : " << endl;
    for( auto v: niz )
        cout << v <<endl;


    /*//Vektor v1, v2;
    cout << "Program za rad sa vektorima." << endl;
    cout << "Unesite koordinate prvog vektora. " << endl;
    cin >> niz;

    cout << "Unesite koordinate drugog vektora. " << endl;
    cin >> v2;*/

    cout << " Izaberite opciju:" << endl;
    cout << " 1. Unutrasnji proizvod " << endl;
    cout << " 2. Vektorski proizvod " << endl;
    cout << " 3. Kraj programa" << endl;
    cout << "Izbor:";
    cin >> izbor;

        switch(izbor){
            case 1:
                cout << "Unutrasnji proizvod: " << endl;
                for(auto i =0; i<n-1; ++i){
                    cout << niz[i] << " * " << niz[i+1] << " = " << niz[i].innerProd(niz[i+1]);
                    }
                break;
            case 2:
                {
                //double z1, z2, z3;
               // crossProduct(x1,x2,x3,y1,y2,y3,z1,z2,z3);
                cout << " Vektorski proizvod : V( " ;
                for(auto i=0;i<n-1; ++i){
                    cout << niz[i] << " x " << niz[i+1] << " = " << niz[i].crossProduct(niz[i+1]);
                    }
                }
                break;
            case 3:
                cout << "Kraj programa." << endl;
                return 0;
                //break; Ne mora break, ima return.
            default:
                cout << "Izabrana opcija ne postoji." << endl;
            }
    }
    return 0;
}
