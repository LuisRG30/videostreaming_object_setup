#include "Service.h"
#include "DataTypeException.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

bool fileException(string error, string exito, string &filename, int &seleccion);


int main()
{
    Service streaming;
    
    cout << "--Bienvenido a GENERIC_STREAMING.com--" <<endl;
    //Declarar variables necesarias para ejecutar programa
    int seleccion;
    string filename = "";
    string genero = "";
    double calificacion = 0;
    string nombre = "";



    while (seleccion != 0){
        //Desplegar menú
        cout << "1. Cargar archivo de datos" << endl;
        cout << "2. Mostrar videos" << endl;
        cout << "3. Mostrar episodios de una serie" << endl;
        cout << "4. Mostrar peliculas" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "0. Salir" << endl;

        //Solicitar decisión (El proceso de switch la valida por default)
        cin >> seleccion;
            switch (seleccion)
            {
            //Cargar archivo (Almacenar el nombre del archivo en filename)
            case 1:
                cout << "Ingresar nombre del archivo a cargar. formato: nombre.txt" << endl;
                cin >> filename;
                //Verificar .selección (bloque try/catch)
                if (fileException("No existe tal archivo", "Archivo cargado exitosamente", filename, seleccion)){
                    streaming.load(filename);
                }
                break;

            case 2:
                //Verificar si hay archivo cargado
                fileException("No hay archivo cargado", "Listo para leer archivo", filename, seleccion);
                while (seleccion != -1)
                {
                    cout << "1. Buscar videos por genero" << endl;
                    cout << "2. Buscar videos por calificacion" <<endl;
                    cout << "0. Volver al menu principal" << endl;
                    cin >> seleccion;

                    switch (seleccion)
                    {
                    //Búsqueda por género
                    case 1:
                        cout << "Genero:" << endl;
                        cin >> genero;
                        streaming.mostrarVideos(genero);
                        seleccion = -2;
                        break;
                    //Búsqueda por calificaciones
                    case 2:
                        cout << "Calificacion:" << endl;
                        cin >> calificacion;
                        streaming.mostrarVideos(calificacion);
                        seleccion = -2;
                        break;

                    case  0:
                        cout << "Volviendo al menu principal" << endl;
                        seleccion = -1;
                        break;
                    
                    default:
                        cout << "Ingresa una opcion valida" << endl;
                        seleccion = -2;
                        break;
                    }
                }
                break;

            case 3:
                if (fileException("No hay archivo cargado", "Listo para leer archivo", filename, seleccion)){
                    cout << "Nombre:" << endl;
                    cin >> nombre;
                    cout << "Calificacion:" << endl;
                    cin >> calificacion;
                    streaming.mostrarEpisodios(nombre, calificacion);
                }

                break;

            case 4:
                if (fileException("No hay archivo cargado", "Listo para leer archivo", filename, seleccion)){
                    cout << "Calificacion:" << endl;
                    cin >> calificacion;
                    streaming.mostrarPeliculas(calificacion);
                }
                break;

            case 5:
                if (fileException("No hay archivo cargado", "Listo para leer archivo", filename, seleccion)){
                    cout << "Nombre:" << endl;
                    cin >> nombre;
                    cout << "Calificacion:" << endl;
                    cin >> calificacion;
                    streaming.calificar(nombre, calificacion, filename);
                }
                break;

            case 0:
                break;
            
            
            default:
                cout << "Ingrese una opcion valida" << endl;
                seleccion = 6;
                break;
            }
    }
    return 0;
}




bool fileException(string error, string exito, string &filename, int &seleccion){
    try{
        ifstream ifile;
        ifile.open(filename);
        if (ifile.fail()){
            throw error;
        }
        cout << exito << endl;
        ifile.close();
        seleccion = -2;
        return true;
    } catch(string e) {
        //Excepcion en marcha. Determinar reintento o salida
        cout << e << endl;
        cout << "Regresando al menu principal" << endl;
        seleccion = -1;
        return false;
    }
}
