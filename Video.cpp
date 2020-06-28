#include "Video.h"

using namespace std;

//Funcionales
bool fits(string line, int verificar);

//Constructores
Video::Video() //Inútil, pues queremos necesariamente cargar archivos con parámetros
{
    id_ = "";
    nombre_ = "";
    duracion_ = "";
    calificacion_ = 0.0;
}

Video::Video(string id, string nombre, string duracion, double calificacion)
{
    id_ = id;
    nombre_ = nombre;
    duracion_ = duracion;

    calificacion_ = calificacion;

}

//Acceso
//Getters
string Video::getId()
{
    return id_;
}

string Video::getNombre()
{
    return nombre_;
}

string Video::getDuracion()
{
    return duracion_;
}

double Video::getCalificacion()
{
    return calificacion_;
}

void Video::setId(string id)
{
    id_ = id;
}
void Video::setNombre(string nombre)
{
    nombre_ = nombre;
}

void Video::setDuracion(string duracion)
{
    duracion_ = duracion;
}

void Video::setCalificacion(double calificacion)
{
    calificacion_ = calificacion;
}

ostream &operator <<(ostream& salida, Video& video)
{
    salida << "[" << video.id_ << ", " << video.nombre_ << ", " << video.duracion_ << ", " << video.calificacion_ << "]";
    return salida;
}



//Funcionales
bool fits(string line, int verificar)
{
    string s = line;
    int nComas = count(s.begin(), s.end(), ',');
    //Verificación: 3 para serie, 4 para película, 5 para episodio
    if(nComas == verificar){
        return true;
    }
    else{
        return false;
    }
}



