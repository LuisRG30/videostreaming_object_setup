#include "Serie.h"

using namespace std;

//Funcionales
bool fits(string line, int verificar);

//Constructores/Destructores
Serie::Serie()
{
    id_ = "";
    nombre_ = "";
    genero_ = "";
    temporadas_ = 0;
    nEpisodios_ = 0;
}

Serie::Serie(string id, string nombre, string genero, int temporadas, int nEpisodios)
{
    id_ = id;
    nombre_ = nombre;
    genero_ = genero;
    temporadas_ = temporadas;
    episodios_ = new Episodio[nEpisodios];
    nEpisodios_ = nEpisodios;
}

//Acceso
string Serie::getId()
{
    return id_;
}

string Serie::getNombre()
{
    return nombre_;
}

string Serie::getGenero()
{
    return genero_;
}

int Serie::getTemporadas()
{
    return temporadas_;
}

Episodio* Serie::getEpisodios()
{
    return episodios_;
}

int Serie::getNEpisodios()
{
    return nEpisodios_;
}

void Serie::setId(string id)
{
    id_ = id;
}

void Serie::setNombre(string nombre)
{
    nombre_ = nombre;
}

void Serie::setGenero(string genero)
{
    genero_ = genero;
}

void Serie::setTemporadas(int temporadas)
{
    temporadas_ = temporadas;
}

//Otros 

void Serie::load(string filename)
{
    ifstream ifile;
    string line;

    int countEpisodes = 0;
    int strSize;
    ifile.open(filename);
    while (getline(ifile, line)){
        strSize = line.length();
        string values[6];
        int counter = 0;
        string current = "";
        
        //Iteramos sobre line
        if (fits(line, 5)){
            for (int  i = 0; i < strSize; i++){
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
            if (values[0] == id_){
                countEpisodes += 1;
            }
        }
    }
    ifile.close();
//Guardar tamaño de arreglo de espisodios
    nEpisodios_ = countEpisodes;

    episodios_ = new Episodio[countEpisodes];
    countEpisodes = 0;
    ifile.open(filename);
    while (getline(ifile, line)){
        strSize = line.length();
        string values[6];
        int counter = 0;
        string current = "";
        
        //Iteramos sobre line
        if (fits(line, 5)){
            for (int  i = 0; i < strSize; i++){
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

            
            if (values[0] == id_){
                episodios_[countEpisodes].setId(values[0]);
                episodios_[countEpisodes].setIdEpisodio(values[1]);
                episodios_[countEpisodes].setNombre(values[2]);
                episodios_[countEpisodes].setDuracion(values[3]);
                episodios_[countEpisodes].setCalificacion(stod(values[4]));
                episodios_[countEpisodes].setTemporada(stoi(values[5]));

                countEpisodes += 1;
            }
            
        }
    }

    ifile.close();
    
}

ostream &operator <<(ostream& salida, Serie& serie)
{
    salida << "[" << serie.nombre_ << ", " << serie.genero_ << ", Temporadas: " << serie.temporadas_ << "]";
    return salida;
}