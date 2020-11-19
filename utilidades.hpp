#include <iostream>
#include <iomanip>
using namespace std;


void hr(){
    cout <<  setw( 75 ) << setfill( '-' ) << '\n' << setfill( ' ' );
}

void br(){
    cout <<  '\n';
}

void nombre_sistema(){
    cout << "\n**************************************************************************\n";
    cout << "\t\t * Sistema de Inventario y Facturación *";
    cout << "\n**************************************************************************\n";
}

void menu_principal(){

    cout << "\n";
    cout << "\t 1) Administrar productos.\n";
    cout << "\t 2) Vender productos.\n";
    cout << "\t 3) Salir.\n";
    cout << "\n Opción : ";
}

void opcion_novalida(){
    cout << "\n*----------------------------------------------------------------------*\n";
    cout << "|\t\t **** Upps! la opción no es válida. ****\t\t|";
    cout << "\n*----------------------------------------------------------------------*\n";
}


void menu_facturar(){

    cout << "\n";
    cout << "\t 1) Agregar otro producto.\n";
    cout << "\t 2) Mostrar inventario.\n";
    cout << "\t 3) Salir.\n";
    cout << "\n Opción : ";
}

