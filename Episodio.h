#ifndef EPISODIO_H_INCLUDED
#define EPISODIO_H_INCLUDED

#include "Video.h"


class Episodio: public Video
{
    private:
        std::string idEpisodio_;
        int temporada_;

    public:
        //Constructores
        Episodio();
        Episodio(std::string, std::string, std::string, std::string, double, int);


        //Acceso
        std::string getIdEpisodio();
        int getTemporada();
        void setIdEpisodio(std::string);
        void setTemporada(int);


        //Otros
        void postCalificacion(double, std::string);

}
;


#endif