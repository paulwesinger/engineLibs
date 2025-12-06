#include "loadimage.h"
CLoadImage::CLoadImage(string  path)
{
    _Path = path;
}

CLoadImage::~CLoadImage(){}

SDL_Surface * CLoadImage::getSurface(string  path,string obj){

    SDL_Surface * surf = IMG_Load( path.c_str() );
    if ( surf ) {
        logger.loginfo("Succes:  Image " + path + " loaded",obj);
        return surf;
    }
    else {
        surf = loadStandardSurface();
        logger.logwarn("Warning: Image " + path + " not loaded ! created a template image ! Please Check Path.", obj);
        return  surf;
    }
}

SDL_Surface * CLoadImage::loadStandardSurface(){

    return IMG_Load(STANDARDIMAGE.c_str());
}
