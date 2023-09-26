#include <stdio.h>
#include <math.h>

#define PI 3.141592



typedef struct{
    float lato;
} datiQuadrato;

typedef struct{
    float base, altezza;
} datiRettangolo;

typedef struct{
    float raggio;
} datiCerchio;

typedef struct{
    float lati[3];
} datiTriangolo;


typedef struct{
    enum{
        Quadrato,
        Rettangolo,
        Cerchio,
        Triangolo
    } TipoFigura;

    union{
        datiQuadrato datiQ;
        datiRettangolo datiR;
        datiCerchio datiC;
        datiTriangolo datiT;
    };
    
} Figura;


void quadrato(Figura *f, float a){
    f->TipoFigura = Quadrato;
    f->datiQ.lato = a;
}

void rettangolo(Figura *f, float b, float h){
    f->TipoFigura = Rettangolo;
    f->datiR.base = b;
    f->datiR.altezza = h;
}

void cerchio(Figura *f, float r){
    f->TipoFigura = Cerchio;
    f->datiC.raggio = r;
}

void triangolo(Figura *f, float l1, float l2, float l3){
    f->TipoFigura = Triangolo;
    f->datiT.lati[0] = l1;
    f->datiT.lati[1] = l2;
    f->datiT.lati[2] = l3;
}

float perimetro(Figura *f){
    switch (f->TipoFigura){

        case Quadrato:{
            return f->datiQ.lato * 4;
        }

        case Rettangolo:{
            return (f->datiR.base * 2) + (f->datiR.altezza * 2);
        }

        case Cerchio:{
            return 2 * PI * f->datiC.raggio;
        }

        case Triangolo:{
            float somma = 0.0;
            int i;

            for(i = 0; i < 3; i++){
                somma += f->datiT.lati[i];
            }

            return somma;
        }
    }
}

float area(Figura *f){
    switch (f->TipoFigura){
        case Quadrato:{
            return pow(f->datiQ.lato, 2);
        }

        case Rettangolo:{
            return (f->datiR.base * f->datiR.altezza) / 2;
        }

        case Cerchio:{
            return pow(f->datiC.raggio, 2) * PI;
        }

        case Triangolo:{
            float p = perimetro(f);
            float somma = 1.0;
            int i;

            for(i = 0; i < 3; i++){
                somma *= (p - f->datiT.lati[i]);
            }

            return sqrt(p * somma);
        }

    }
}


int main(){
    Figura f;

    quadrato(&f, -4.56);
    printf("\nIl perimetro: %f", perimetro(&f));
    printf("\nL'area: %f",area(&f));
    
    cerchio(&f, 1);
    printf("\n\nIl perimetro: %f", perimetro(&f));
    printf("\nL'area: %f",area(&f));

    triangolo(&f, 3, 4, 5);
    printf("\n\nIl perimetro: %f", perimetro(&f));
    printf("\nL'area: %f",area(&f));

    rettangolo(&f, 4.34, 5.8);
    printf("\n\nIl perimetro: %f", perimetro(&f));
    printf("\nL'area: %f",area(&f));


    printf("\n");
    return 0;
}