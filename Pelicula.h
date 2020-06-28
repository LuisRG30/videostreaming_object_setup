#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

#include "Video.h"



class Pelicula: public Video 
{
    private:

        std::string genero_;

    public:
        //Constructores/Destructores
        Pelicula();
        Pelicula(std::string, std::string, std::string, double, std::string);

        //Acceso
        std::string getGenero();
        void setGenero(std::string);
        //Otros
        void postCalificacion(double, std::string);

}
;




#endif