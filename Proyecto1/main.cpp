/*
  main.cpp
  Proyecto1

  El programa es capaz de validar direcciones IPv4 e IPv6
 
  Created by Ricardo Ramirez on 2/2/18
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool validarIPv6(string linea)
{
    return true;
}

bool validarIPv4(string linea)
{
    long pos;
    string newLine;
    int num[4], count = 0, count2 = 0;
    
    for (int i = 0; i < 3; i++)
    {
        pos = linea.find('.'); //buscando primer punto
        newLine = linea.substr(0, pos); //cortando de 0 a primer punto
        linea.erase(0, pos+1); //eliminando de la direccion de 0 al primer punto
        newLine.erase(pos); //borrando el punto del numero separado
        
//        if (newLine.length() >= 1)
//        {
            if (newLine[0] > '0' && newLine[1] >= '0')
            {
                num[i] = stoi(newLine); //convirtiendolo a int
                
                cout << num[i] << endl;     //---------F L A G--------------
                count ++;
            }
//        }
    }
    
    if (linea.length() >= 1)
    {
        if (linea[0] > '0' && linea[1] > '0')
        {
            num[3] = stoi(linea);
            cout << linea << endl;     //---------F L A G--------------
            count ++;
        }
    }
    
    if (count == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string nomArchEntrada, nomArchSalida, linea;
    ifstream archEntrada;
    bool valido;
    cout << "Nombre del archivo de entrada: \n";
    cin >> nomArchEntrada;
    
    archEntrada.open(nomArchEntrada);
    
    while (getline(archEntrada, linea))
    {
        if (linea.size() > 15) //si es IPv6
        {
            valido = validarIPv6(linea);
        }
        else // es IPv4
        {
            valido = validarIPv4(linea);
        }
    }
    
    return 0;
}
