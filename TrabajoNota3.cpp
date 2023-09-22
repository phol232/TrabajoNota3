#include <iostream>
using namespace std;

const int MAX_REGISTROS = 100;  
const int MAX_NOMBRE = 50;      
const int MAX_APELLIDO = 50;    
const int MAX_DIRECCION = 100;  

struct Registro {
    int id;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    char direccion[MAX_DIRECCION];
    int telefono;
    char genero;
};

void agregarRegistro(Registro registros[], int& numRegistros) {
    if (numRegistros < MAX_REGISTROS) {
        Registro nuevoRegistro;
        nuevoRegistro.id = numRegistros + 1;
        cout << "\nIngrese el nombre: ";
        cin.ignore();
        cin.getline(nuevoRegistro.nombre, MAX_NOMBRE);
        cout << "Ingrese el apellido: ";
        cin.getline(nuevoRegistro.apellido, MAX_APELLIDO);
        cout << "Ingrese la dirección: ";
        cin.getline(nuevoRegistro.direccion, MAX_DIRECCION);
        cout << "Ingrese el número de teléfono: ";
        cin >> nuevoRegistro.telefono;
        cout << "Ingrese el género: ";
        cin >> nuevoRegistro.genero;
        registros[numRegistros++] = nuevoRegistro;
        cout << "\nRegistro agregado correctamente." << endl;
    } else {
        cout << "\nNo es posible agregar más registros, la base de datos está llena." << endl;
    }
}

void mostrarRegistros(const Registro registros[], int numRegistros) {
    cout << "\nRegistros en la base de datos:" << endl;
    for (int i = 0; i < numRegistros; ++i) {
        const Registro& registro = registros[i];
        cout << "\nID: " << registro.id << endl;
        cout << "Nombre: " << registro.nombre << endl;
        cout << "Apellido: " << registro.apellido << endl;
        cout << "Dirección: " << registro.direccion << endl;
        cout << "Número de teléfono: " << registro.telefono << endl;
        cout << "Género: " << registro.genero << endl;
        cout << endl;
    }
}

void buscarPorID(const Registro registros[], int numRegistros, int idBuscar) {
    for (int i = 0; i < numRegistros; ++i) {
        const Registro& registro = registros[i];
        if (registro.id == idBuscar) {
            cout << "\nRegistro encontrado:" << endl;
            cout << "ID: " << registro.id << endl;
            cout << "Nombre: " << registro.nombre << endl;
            cout << "Apellido: " << registro.apellido << endl;
            cout << "Dirección: " << registro.direccion << endl;
            cout << "Número de teléfono: " << registro.telefono << endl;
            cout << "Género: " << registro.genero << endl;
            return;
        }
    }
    cout << "\nNo se encontró un registro con el ID especificado." << endl;
}

void eliminarRegistro(Registro registros[], int& numRegistros, int idEliminar) {
    for (int i = 0; i < numRegistros; ++i) {
        if (registros[i].id == idEliminar) {
            // Mover los registros posteriores hacia atrás para llenar el espacio eliminado
            for (int j = i; j < numRegistros - 1; ++j) {
                registros[j] = registros[j + 1];
            }
            --numRegistros;
            cout << "\nRegistro eliminado correctamente." << endl;
            return;
        }
    }
    cout << "\nNo se encontró un registro con el ID especificado." << endl;
}

int main() {
    setlocale(LC_CTYPE, "Spanish");
    Registro baseDeDatos[MAX_REGISTROS];
    int numRegistros = 0; 

    char opcion;
    do {
        cout << "\nMenú de la base de datos:" << endl;
        cout << "1. Agregar registro" << endl;
        cout << "2. Mostrar registros" << endl;
        cout << "3. Buscar por ID" << endl;
        cout << "4. Eliminar registro" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;     
        switch (opcion) {
            case '1':
                agregarRegistro(baseDeDatos, numRegistros);
                break;
            case '2':
                mostrarRegistros(baseDeDatos, numRegistros);
                break;
            case '3':
                if (numRegistros > 0) {
                    int idBuscar;
                    cout << "Ingrese el ID del registro a buscar: ";
                    cin >> idBuscar;
                    buscarPorID(baseDeDatos, numRegistros, idBuscar);
                } else {
                    cout << "La base de datos está vacía." << endl;
                }
                break;
            case '4':
                if (numRegistros > 0) {
                    int idEliminar;
                    cout << "Ingrese el ID del registro a eliminar: ";
                    cin >> idEliminar;
                    eliminarRegistro(baseDeDatos, numRegistros, idEliminar);
                } else {
                    cout << "La base de datos está vacía." << endl;
                }
                break;
            case '5':
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != '5');  

    return 0;
}

