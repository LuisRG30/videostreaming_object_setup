#include "Service.h"

using namespace std;


bool fits(string line, int verificar);
void fileException(string error, string exito, string &filename, int &seleccion);

//Constructores
Service::Service()
{
    nPeliculas_ = 0;
    nSeries_ = 0;
}




//Otros
void Service::load(string filename)
{
    
    string line;
    ifstream ifile;
    //Revisar cuántos objetos tendremos de tipo Película y Serie
    int nSeries = 0;
    int nPeliculas = 0;

    ifile.open(filename);
    while (getline(ifile, line)){
        if (fits(line, 3)){
            nSeries += 1;
        }
        if (fits(line, 4)){
            nPeliculas += 1;
        }
    }
    ifile.close();
    //Número de películas y series conocido
    
    //Agregar dichas películas y series 
    nPeliculas_ = nPeliculas;
    nSeries_ = nSeries;

    peliculas_ = new Pelicula[nPeliculas];
    series_ = new Serie[nSeries];
    Pelicula movie;
    Serie series;

    int strSize;
    ifile.open(filename);
    int seriesCounter = 0;
    int movieCounter = 0;
    string current = "";
    while (getline(ifile, line)){
        strSize = line.length();
        string values[5];
        int counter = 0;
        string current = "";
        //Iteramos sobre line
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


        //Series
        if (fits(line, 3)){
            series.setId(values[0]);
            series.setNombre(values[1]);
            series.setGenero(values[2]);
            series.setTemporadas(stoi(values[3]));

            series_[seriesCounter] = series;

            seriesCounter += 1;
        }
        

        //Películas
        if (fits(line, 4)){
            movie.setId(values[0]);
            movie.setNombre(values[1]);
            movie.setDuracion(values[2]);
            movie.setGenero(values[3]);
            movie.setCalificacion(stod(values[4]));

            peliculas_[movieCounter] = movie;
            

            movieCounter += 1;
        }
    }
    ifile.close();
    
    //Llenar las series con episodios
    for (int i = 0; i < nSeries; i++){
        series_[i].load(filename);
    }
    
}

void Service::mostrarVideos(string genero)
{
    bool exists = false;
    cout << "Peliculas:" << endl;

    for (int i = 0; i < nPeliculas_; i++){
        if (peliculas_[i].getGenero() == genero){
            exists = true;
            cout << peliculas_[i] << endl;  
        }
    }

    cout << "Series:" << endl;
    for (int i = 0; i < nSeries_; i++){
        if (series_[i].getGenero() == genero){
            exists = true;
            cout << series_[i].getNombre() << ":" << endl;
            for (int j = 0; j < series_[i].getNEpisodios(); j++){
                cout << "\t" << series_[i].getEpisodios()[j] << endl;
            }

        }
    }
    if (exists == false){
        cout << "No se encontraron videos con genero [" << genero << "]" << endl;
    }
}

void Service::mostrarVideos(double calificacion)
{
    bool exists = false;
    cout << "Peliculas:" << endl;

    for (int i = 0; i < nPeliculas_; i++){
        if (peliculas_[i].getCalificacion() == calificacion){
        exists = true;
        cout << "[" << peliculas_[i].getGenero() << "] " << peliculas_[i] << endl;
        }
    }

    cout << "Series:" << endl;
    for (int i = 0; i < nSeries_; i++){
        for (int j = 0; j < series_[i].getNEpisodios(); j++){
            if (series_[i].getEpisodios()[j].getCalificacion() == calificacion){
                exists = true;
                cout << "{" << series_[i].getNombre() << "} "<< series_[i].getEpisodios()[j] << endl;
            }
        }

    }
    if (exists == false){
        cout << "No se encontraron videos con calificacion [" << calificacion << "]" << endl;
    }
}

void Service::mostrarEpisodios(string nombre, double calificacion)
{
    bool existsAny = false;
    bool existsSerires = false;
    for (int i = 0; i < nSeries_; i++){
        if (series_[i].getNombre() == nombre){
            existsSerires = true;
            for (int j = 0; j < series_[i].getNEpisodios(); j++){
                if (series_[i].getEpisodios()[j].getCalificacion() == calificacion){
                    cout << series_[i].getEpisodios()[j] << endl;
                    existsAny = true;
                }
            }
        }
    }
    if (existsSerires == false){
        cout << "No existe serie con nombre {" << nombre << "}" << endl;
    }
    else if (existsAny == false){
        cout << "No hay episodios de la serie {" << nombre << "} con calificacion " << calificacion << endl;
    }
}

void Service::mostrarPeliculas(double calificacion)
{
    bool exists = false;
    cout << "Peliculas:" << endl;
    for (int i = 0; i < nPeliculas_; i++){
        if (peliculas_[i].getCalificacion() == calificacion){
            exists = true;
            cout << "{" << peliculas_[i].getGenero() << "} " << peliculas_[i] << endl;
        }
    }
    if (exists == false){
        cout << "No se encontraron peliculas con calificacion " << calificacion << endl;
    }
}

void Service::calificar(string nombre, double calificacion, string filename)
{
    bool calificado = false;
    //Método para películas
    for (int i = 0; i < nPeliculas_; i++){
        if (peliculas_[i].getNombre() == nombre){
            peliculas_[i].postCalificacion(calificacion, filename);
            calificado = true;
        }
    }
    for (int i = 0; i < nSeries_; i++){
        for (int j = 0; j < series_[i].getNEpisodios(); j++){
            if (series_[i].getEpisodios()[j].getNombre() == nombre){
                series_[i].getEpisodios()[j].postCalificacion(calificacion, filename);
                calificado = true;
            }
        }
    }

    if (calificado){
        cout << "Video calificado exitosamente" << endl;
    }
    else{
        cout << "No se encontro video llamado {" << nombre << "}" << endl; 
    }
}
