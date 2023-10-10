#include <iostream>
#include <string>
#include <vector>

// MARCO ANTONIO MOTA HERRERA, LEONARDO MICHEL DOMINGO SANCHEZ, JORGE ULISES DEL MORAL MUÑOZ

using namespace std;

//CÓDIGO DEL ESTACIONAMIENTO//
struct Vehiculo {
    string tipo;
    string color;
    double horas_estacionado;
    int id;

    Vehiculo(string _tipo, string _color, double _horas_estacionado, int _id)
        : tipo(_tipo), color(_color), horas_estacionado(_horas_estacionado), id(_id) {}
};

struct ESTACIONAMIENTO {
    const int lon = 10;
    vector<Vehiculo> cola;
    int contador = 0, espacio;

    void ingresarvehiculo() {
        espacio = (lon)-(contador);
        cout << "\nTienes " << espacio << " espacios disponibles" << endl << endl;
        if (cola.size() < lon) {
            int id;
            string tipo, color;
            double horas_estacionado;
            cout << "\nIngresa el ID del vehículo: "; cin >> id;
            cout << "Ingresa el tipo de vehículo: "; cin >> tipo;
            cout << "Ingresa el color del vehículo: "; cin >> color;
            cout << "Ingresa las horas de estacionamiento: "; cin >> horas_estacionado;
            cola.push_back(Vehiculo(tipo, color, horas_estacionado, id));
            cout << "\nVehículo con ID " << id << " ingresado al estacionamiento" << endl;
            contador++; 
            espacio = lon - contador;
        } 
        else {
            cout << "\nEl estacionamiento esta lleno" << endl;
        }
    }

    void sacarvehiculo() {
        if (!cola.empty()) {
            Vehiculo vehiculo = cola.front();
            cola.erase(cola.begin());

            double costo = vehiculo.horas_estacionado * 15.0;  // Precio fijo de 15 pesos por hora
            cout << "\nVehículo con ID " << vehiculo.id << " (Tipo: " << vehiculo.tipo << ", Color: " << vehiculo.color << ", Horas Estacionado: " << vehiculo.horas_estacionado << ") ha salido del estacionamiento." << endl;
            cout << "El costo de estacionamiento es de " << costo << " pesos." << endl;
            contador--;
            espacio = lon - contador;
        } else {
            cout << "\nEl estacionamiento esta vacío" << endl;
        }
    }

   void mostrarvehiculos() {
    if (!cola.empty()) {
        cout << "\nEspacios todavía disponibles: " << (espacio) << endl << endl;
        cout << "\nVehiculos en el estacionamiento:" << endl;
        for (size_t i = 0; i < cola.size(); i++) {
            const Vehiculo& vehiculo = cola[i];
            cout << "ID: " << vehiculo.id << " | Tipo: " << vehiculo.tipo << " | Color: " << vehiculo.color << " | Horas Estacionado: " << vehiculo.horas_estacionado << " | Costo de Estacionamiento: " << (vehiculo.horas_estacionado * 15) << " pesos" << endl;
        }
    } else {
        cout << "\nEl estacionamiento esta vacío" << endl;
    }
}
};

int main() {
    int opc = 0;
    ESTACIONAMIENTO estacionamiento;
                int opc_estacionamiento;
                do {
                    cout << "\n>>> CASETA DE ESTACIONAMIENTO <<<" << endl;
                    cout << "1. INGRESAR VEHÍCULO" << endl;
                    cout << "2. RETIRAR VEHÍCULO" << endl;
                    cout << "3. MOSTRAR VEHÍCULOS" << endl;
                    cout << "4. SALIR" << endl;
                    cin >> opc_estacionamiento;

                    switch (opc_estacionamiento) {
                        case 1:
                            estacionamiento.ingresarvehiculo();
                            break;

                        case 2:
                            estacionamiento.sacarvehiculo();
                            break;

                        case 3:
                            estacionamiento.mostrarvehiculos();
                            break;

                        case 4:
                            cout << "\nSaliendo de ADMON. DE ESTACIONAMIENTO..." << endl;
                            break;

                        default:
                            cout << "\nPor favor digite una opcion valida" << endl;
                    }
                } while (opc_estacionamiento != 4);
        
}
