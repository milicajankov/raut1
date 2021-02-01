#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

struct Krug {
    double x;
    double y;
    double r;

    //Konstruktor:                                  inicijalizaciona lista
    Krug (double xx=0. , double yy=0., double rr=0.): x(xx), y(yy), r(rr){}
    double obim() const {return 2*r*M_PI;}
    double povrsina() const {return r*r*M_PI;}
    bool overlap(const Krug &k)  const{
         return sqrt((x- k.x)*(x - k.x) + (y - k.y)*(y - k.y)) < r + k.r ;}


};

istream& operator >> (istream& in, Krug &k){
    in >> k.x >> k.y >> k.r; // ucitava iz
        return in ;
}

ostream& operator << (ostream &out, const Krug &k){
    out << "Krug K[(" << k.x << "," << k.y << "), " << k.r << "]";
    return out;
}

double obim(double r){
    return 2*r*M_PI;
}

double povrsina(double r){
    return r*r*M_PI;
}

bool overlap(double x1, double y1, double r1, double x2, double y2, double r2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < r1 + r2 ;
}

int main() {
    char izbor;
    do {
       // double x1, x2, y1, y2, r1, r2;

        int meni;
        Krug k1, k2;

        cout << "Program za rad sa krugovima" << endl << endl;
        cout << "Unesite krug K1 " << endl;
        cout << "Unesite x i y koordinatu centra kruga, kao i njegov poluprecnik: x1, y1, r1: ";
        cin >> k1;

      //  Krug k1(x1, y1, r1);

        cout << "Unesite krug K2 " << endl;
        cout << "Unesite x i y koordinatu centra kruga, kao i njegov poluprecnik: x2, y2, r2: ";
        cin >> k2;

      //  Krug k2(x2, y2, r2);

        cout << endl ;

       /* cout << "Krug K[(" << x1 << "," << y1 << "), " << r1 << "]" << endl;
        cout << "Obim: " << 2*r1*M_PI << endl;
        cout << "Povrsina: " << r1*r1*M_PI << endl;

        cout << endl ;

        cout << "Krug K[(" << x2 << "," << y2 << "), "<< r2 << "]" << endl;
        cout << "Obim: " << 2*r2*r2*M_PI << endl;
        cout << "Povrsina: " << r2*r2*M_PI << endl;*/

        cout << "Izaberite opciju: " << endl;
        cout << "1. Povrsina" << endl;
        cout << "2. Obim" << endl;
        cout << "3. Preklapanje " ;
        cin >> meni;

        switch(meni){
            case 1:
                {
                cout << "Krug " << k1 << endl;
                cout << "Povrsina: " << k1.povrsina() << endl;

                cout << endl;

                cout << "Krug" << k2 << endl;
                cout << "Povrsina: " << k2.povrsina() << endl;
                }
                break;
            case 2:
                {
                cout << "Krug" << k1 << endl;
                cout << "Obim: " << k1.obim() << endl;

                cout <<endl;

                cout << "Krug" << k2 << endl;
                cout << "Obim: " << k2.obim() << endl;
                }
                break;
            case 3:
            {
                cout << "Preklapanje krugova :" << k1 << " i " << k2 <<((k1.overlap(k2))?(": DA"):(": NE")) << endl;
                break;
            default:
            cout << "Nepostojeca opcija, probati ponovo." << endl;
            }
        }
        cout <<  endl << endl;

        cout << "Da li zelite ponovo da unesete krug? (d/n)";
        cin >> izbor;
        } while(izbor == 'd' || izbor == 'D');


        cout << "Kraj programa" << endl;
    return 0;
}
