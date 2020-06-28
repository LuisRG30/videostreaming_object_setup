#include "Pelicula.h"

using namespace std;

bool fits(string line, int verificar);
//Constructores/Destructores
Pelicula::Pelicula() :Video()
{

}

Pelicula::Pelicula(string id, string nombre, string duracion, double calificacion, string genero) :Video(id, nombre, duracion, calificacion)
{
    genero_ = genero;
}

//Acceso
string Pelicula::getGenero()
{
    return genero_;
}

void Pelicula::setGenero(string genero)
{
    genero_ = genero;
}


//Otros
void Pelicula::postCalificacion(double calificacion, string filename)
{
    ifstream ifile;
    string line;
    int linecounter = 0;
    int lineidentifier;
    string values[4];
    int counter = 0;
    string current = "";

    
    //Identificamos dónde está la película en cuestión
    ifile.open(filename);
    while (getline(ifile, line)){
        if (fits(line, 4)){
        //Iteramos sobre line
            counter = 0;
            for (int  i = 0; i < line.length(); i++){
                //Recopilamos texto hasta llegar a una coma
                if (line[i] == ','){
                    values[counter] = current;
                    current = "";
                    counter += 1;
                }
                else{
                    current += line[i];
                }
            }
            values[counter] = current;
            if (nombre_ == values[1]){
                lineidentifier = linecounter;
            }
        }


        linecounter += 1;
    }
    ifile.close();
    //Reset values
    counter = 0;
    current = "";

    //Reescribir linea calificada
    calificacion_ = calificacion;
    
    string strcalificacion;


    //Ajustar strings para reemplazar
    strcalificacion = to_string(calificacion_);
    strcalificacion = strcalificacion.substr(0,3);

    string *lines;
    ifile.open(filename);
    while (getline(ifile, line)){
        counter++;
    }
    ifile.close();
    lines = new string[counter];
    ifile.open(filename);
    counter = 0;
    while (getline(ifile, line)){
        lines[counter] = line;
        counter++;
    }
    ifile.close();

    string replacing = id_ + "," + nombre_ + "," + duracion_ + "," + genero_ + "," + strcalificacion;
    lines[lineidentifier] = replacing;

    //Reemplazar archivo
    ofstream ofile;
    ofile.open(filename);
    for (int i = 0; i < counter; i++){
        ofile << lines[i] << "\n";
    }

    ofile.close();
    
}
