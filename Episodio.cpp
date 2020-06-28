#include "Episodio.h"

using namespace std;

bool fits(string line, int verificar);

//Constructores/Destructores
Episodio::Episodio() :Video()
{
    idEpisodio_ = "";
    temporada_ = 0;
}

Episodio::Episodio(string id, string idEpisodio, string nombre, string duracion, double calificacion, int temporada) :Video(id, nombre, duracion, calificacion)
{
    idEpisodio_ = idEpisodio;
    temporada_ = temporada;
}


//Acceso
string Episodio::getIdEpisodio()
{
    return idEpisodio_;
}

int Episodio::getTemporada()
{
    return temporada_;
}

void Episodio::setIdEpisodio(string idEpisodio)
{
    idEpisodio_ = idEpisodio;
}

void Episodio::setTemporada(int tmeporada)
{
    temporada_ = tmeporada;
}

//Otros
void Episodio::postCalificacion(double calificacion, string filename)
{
    ifstream ifile;
    string line;
    int linecounter = 0;
    int lineidentifier;
    string values[5];
    int counter = 0;
    string current = "";

    
    //Identificamos dónde está la película en cuestión
    ifile.open(filename);
    while (getline(ifile, line)){
        if (fits(line, 5)){
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
            if (nombre_ == values[2]){
                lineidentifier = linecounter;
            }
        }


        linecounter += 1;
    }
    ifile.close();
    //Reset values
    counter = 0;
    current = "";

    double califAnterior = calificacion_;
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

    string replacing = id_ + "," + idEpisodio_ + "," + nombre_ + "," + duracion_ + ","  + strcalificacion + "," + to_string(temporada_);
    lines[lineidentifier] = replacing;

    //Reemplazar archivo
    ofstream ofile;
    ofile.open(filename);
    for (int i = 0; i < counter; i++){
        ofile << lines[i] << "\n";
    }

    ofile.close();
}