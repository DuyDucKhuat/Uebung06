
#include "unit.h"
#include <iostream>
#include <math.h>
#include <vector>
typedef double(*function) (double);
double Trapezregel( double a, double b, double fa, double fb) {return (b-a) * (1./2 * fa + 1./2 * fb);}
double Mittelpunktsregel( double a, double b, double fm){ return (b-a) * fm;}
double Simpsonregel( double a, double b, double fa, double fb, double fm){return (b-a)*(1./6 * fa + 4./6 * fm + 1./6*fb);}
bool fehler( double a, double b, double fa, double fb,double fm, double epsilon){return fabs(Mittelpunktsregel(a,b,fm) - Trapezregel(a,b,fa,fb)) < epsilon;}
void adaptiveMethod(double& I, function f, double a, double b, double fa, double fb, int& Aufwand, double epsilon, int rekTiefe, std::vector<int>& Schrittweite)
{
    double fm;
    if(rekTiefe == 0){
        fa = f(a);
        fb = f(b);
        fm = f((a+b)/2);
        Aufwand += 3;
    }else{
        fm = f((a+b)/2);
        Aufwand++;
    }
    if ( !fehler(a,b,fa,fb, fm, epsilon))
    {
        adaptiveMethod ( I, f, a, (a+b)/2, fa, fm, Aufwand, epsilon/2, rekTiefe + 1, Schrittweite);
        adaptiveMethod ( I, f, (a+b)/2, b, fm, fb, Aufwand, epsilon/2, rekTiefe + 1, Schrittweite);
    }else
        I += Simpsonregel(a, b, fa, fb ,fm);
    Schrittweite.push_back( rekTiefe+ 1);
}
double summierte_Trapezregel(function f, double a, double b, int n)
{
    double sum = 0;
    double h = (b-a) /n ;
    for (int j = 1; j < n; j ++) sum += f(a + j*h);
    return  (h/2) * (f(a) + f(b)) + sum;
}
    

int main (){
    std::vector < int> Schrittweite; //Vektor, der dokumentiert bei welcher Rekursionstiefe jeweils die Bedingung |Im - It | < epsilon erfüllt wurde.
    std::cout << " Welches Beispiel soll ausgefuehrt werden? ( Zwischen 1 und "<< AnzahlBeispiele  << ")" << std::endl;
    int bsp, Aufwand, rekTiefe;
    std::cin >> bsp;
    double epsilon, a, b, I;
    bool Grafik = true;
    Start ( bsp, a, b, epsilon, Grafik);
    
    
    
    adaptiveMethod ( I,f, a,b,0,0, Aufwand, epsilon, rekTiefe, Schrittweite );
    std::cout << "Aufrufe der Funktion f: " << Aufwand << std::endl;
    Ergebnis ( I);
    int max  = 0;
    for ( int v : Schrittweite) if ( max < v) max = v; //größte Rekursionstiefe
    double res = summierte_Trapezregel(f,a,b,max);
    std::cout<<"Größte Rekursionstiefe bei adaptiver Auswertung: " << max <<". \nUnd für die summierte Trapezregel erhalten wir: " << res << ". \nSowieso den Rechenaufwand " <<  max + 1 << std::endl; ;
    
    

    
    
    


    return 0;
}
