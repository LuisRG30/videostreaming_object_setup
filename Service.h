#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

#include "Pelicula.h"
#include "Serie.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>

class Service
{
    private:
        Pelicula *peliculas_;
        Serie *series_;

        int nPeliculas_;
        int nSeries_;

    public:
         Service();

         void load(std::string);
         void mostrarVideos(std::string);
         void mostrarVideos(double);
         void mostrarEpisodios(std::string, double);
         void mostrarPeliculas(double);
         void calificar(std::string, double, std::string);
}
;






#endif