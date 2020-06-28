#ifndef SERIE_H_INCLUDED
#define SERIE_H_INCLUDED

#include "Episodio.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using std::ostream;

class Serie
{
    friend ostream &operator <<(ostream& salida, Serie&);
    private:
        std::string id_;
        std::string nombre_;
        std::string genero_;
        int temporadas_;
        Episodio *episodios_;
        int nEpisodios_;

    public:
        //Constructores
        Serie();
        Serie(std::string, std::string, std::string, int, int);

        //Acceso
        std::string getId();
        std::string getNombre();
        std::string getGenero();
        int getTemporadas();
        Episodio* getEpisodios();
        int getNEpisodios();

        void setId(std::string);
        void setNombre(std::string);
        void setGenero(std::string);
        void setTemporadas(int);




        //Otros
        void load(std::string filename);
}
;


#endif