
#include "unit.h"
#include <iostream>
#include <math.h>

double Mittelpunktpunktregel (double a,double b, ) {
    return (b -a) * f ((a+b)/2.);
}
int intervalle ( double epsilon, )

int main (){
    std::cout << " Welches Beispiel soll ausgefuehrt werden?" << std::endl;
    int bsp, pause;
    std::cin >> bsp;
    double epsilon, a, b;
    bool Grafik;
    Start ( Bsp, a, b, epsilon, Grafik, pause);

    int intervalle;
    double IM = 0;
    double IT = 0;
    double differenz = 1000;
    int n = 0;
    
    while (differenz >= epsilon ){
        n++;
        IM = 0;
        IT = 0;
        h = (b -a) / n;
        for (int j = 0; j < n ; j ++){
            IM +=  h *  f(  a + j*h + h/2. );
            IT +=  h/2. * ( f ( a+ j+h) + f(a + (j+1)*h) );
        }
        differenz = fabs( IM - IT);
    }
    double I = 0
    I += h/6. *( f(a) + f(b));
    for (int i = 0 ; i < n ;  i++){
        I += 4*h/6. * f(a+ i*h);
    }
    Ergebnis ( I);
    return 0;
}