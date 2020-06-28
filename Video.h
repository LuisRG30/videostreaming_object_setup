#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <string.h>

using std::ostream;

class Video
{
    friend ostream &operator <<(ostream& salida, Video&);
    protected:
        std::string id_;
        std::string nombre_;
        std::string duracion_; //hh:mm
        double calificacion_;

    public:
        //Constructores
         Video();
         Video(std::string, std::string, std::string, double);
         
         //Acceso
         std::string getId();
         std::string getNombre();
         std::string getDuracion();
         double getCalificacion();

         void setId(std::string);
         void setNombre(std::string);
         void setDuracion(std::string);
         void setCalificacion(double);


        //Otros
         virtual void postCalificacion(double calificacion, std::string filename) = 0;
}
;







#endif