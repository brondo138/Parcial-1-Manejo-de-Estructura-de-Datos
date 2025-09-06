/*
Autor: Alex Francisco Lovos Argueta (u20241471)
Autoevaluación: 10/10
Descripción: Parcial 1
Motivo: Cumplo todas las indicaciones. 
Fecha: 6 de septiembre del 2025
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    //Parte 1
    int dias;
    cout << "¿Cuántos días se registrarán? ";
    cin >> dias;

    if (cin.fail() || dias <= 0)
    {
        cout << "Error: Ingrese solo datos numericos mayores a 0" << endl;
        return 1;
    }
    

    vector<float> temperaturas(dias);

    for (int i = 0; i < dias; i++) {
        cout << "Ingrese la temperatura del día " << (i + 1) << ": ";
        cin >> temperaturas[i];
        
        if (cin.fail())
        {
            cout << "Error: Ingrese solo datos numericos" << endl;
            return 1;
        }
        
    }
    //Parte 2
    float* ptr = &temperaturas[0];
    float suma = 0.0;

    cout << "\nTemperaturas registradas: " <<endl;

    for (int i = 0; i < dias; i++)
    {
        cout << "Dia " << i + 1 << ": " << *(ptr + i)<< " grados celsius" <<endl;
        suma += *(ptr + i);
    }
    float promedio = suma/dias;

    cout << "Temperatura promedio: " << promedio << " grados celsius" << endl;
    //Parte 3
    float busqueda;
    cout << "\nIngresa el valor numerico de la temperatura que deseas buscar: ";
    cin >> busqueda;

    if (cin.fail())
        {
            cout << "Error: Ingrese solo datos numericos" << endl;
            return 1;
        }

    bool encontrada = false;

    for (int i = 0; i < dias; i++)
    {
        if (*(ptr + i) == busqueda)
        {
            cout << "La temperatura " << busqueda << " se registro en el dia " << i+1 <<endl;
            encontrada = true;
            
        }
    }

    if (!encontrada)
    {
        cout << "La temperatura " << busqueda << " no se encuentra en los registros" <<endl;
    }
    //Parte 4
    sort(temperaturas.begin(), temperaturas.end());

    cout << "\nTemperaturas ordenada (menor a mayor)" <<endl;
    for (int i = 0; i < dias; i++)
    {
        cout << temperaturas[i] << " grados celsius"<<endl;
    }
    
    //Parte 5
    list<string> equipos;

    int numEquipos;
    cout << "\n¿Cuántos equipos se registrarán? ";
    cin >> numEquipos;

    if (cin.fail() || numEquipos <= 0) {
        cout << "Error: Ingrese solo números mayores a 0" << endl;
        return 1;
    }

    cin.ignore();

    for (int i = 0; i < numEquipos; i++) {
        string nombre;
        cout << "Ingrese el nombre del equipo " << (i + 1) << ": ";
        getline(cin, nombre);
        equipos.push_back(nombre);
    }

    cout << "\nLista de equipos registrados:\n";
    
    for (list<string>::iterator i = equipos.begin(); i != equipos.end(); ++i) {
        cout << *i << endl;
    }

    string equipoBuscado;
    cout << "\nIngrese el nombre del equipo a buscar: ";
    getline(cin, equipoBuscado);

    auto it = find(equipos.begin(), equipos.end(), equipoBuscado);

    if (it != equipos.end()) {
        cout << "El equipo '" << equipoBuscado << "' Si está en la lista.\n";
    } else {
        cout << "El equipo '" << equipoBuscado << "' No está en la lista.\n";
    }

    equipos.sort();
    cout << "\nLista de equipos ordenada:\n";

    for (auto& eq : equipos) {
        cout << eq << endl;
    }

    string equipoEliminar;
    cout << "\nIngrese el nombre del equipo a eliminar: ";
    getline(cin, equipoEliminar);
    equipos.remove(equipoEliminar);

    cout << "\nLista de equipos después de eliminar '" << equipoEliminar << "':\n";

    for (auto& eq : equipos) {
        cout << eq << endl;
    }
    
    return 0;
}
