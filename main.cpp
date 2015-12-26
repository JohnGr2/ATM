/*Programa ATM que registra transacciones de depósito, retiro y balance en una cuenta*/
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

COORD coord={0,0};

void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

void  menu(){
    
    cout << "Probando que todo esté funcionando de maravilla!";
    cout << "Todo bien por estos lados!";
    cout << "\tBienvenido al ATM  " << endl << endl << endl;
    cout << "Ingrese una de las siguientes opciones: " << endl << endl;
    cout << "1. Depositar " << endl << "2. Retirar" << endl << "3. Mostrar balance" << endl << "4. Salir" << endl;
}

void login()
{
    string user, pass;

    cout << "-------------------------" << endl;
    cout << "Usuario: " << endl;
    cout << "Contraseña: " << endl;
    cout << "-------------------------" << endl;
    gotoxy(10,1);
    cin >> user;
    gotoxy(12,2);
    cin >> pass;


    if(user == "john" && pass == "123")
    {
        menu();
    }
    else
    {
        cout<<"Nombre o contraseña incorrectos" << endl;
        login();
    }
}


int main()
{

    int dep, ret, opcion;
    int balance = 0;

    login();

    do
    {
        cout << endl << "Seleccion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 1 :
            cout <<"Ingrese cantidad a depositar: ";
            cin >> dep;

            if(dep <= 0)
            {
                cout << "Error, No puede agregar cantidad menor a 0" << endl;
            }

            else
            {
                balance = balance + dep;
                cout << "Operacion registrada" << endl;

            }
            break;

        case 2 :

            cout << "Ingrese cantidad a retirar: ";
            cin >> ret;

            if( ret >= balance)
            {

                cout << "Error, No puede retirar una cantidad mayor a la de su balance actual" << endl;

            }
            else
            {
                balance = balance - ret;
                cout << "Operacion registrada" << endl;
            }
            break;

        case 3:

            cout << "Su balance es de: " << balance << " cordobas" << endl;
            break;

        case 4:

            return 0;

        default :

            cout << endl <<  "Opcion Invalida" << endl;

        }

    }
    while(opcion != 4);

    return 0;
}
