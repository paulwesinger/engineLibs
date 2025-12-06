#ifndef CLOADIMAGE_H
#define CLOADIMAGE_H

#include <string>
#include <SDL_image.h>
#include <SDL.h>
#include <logger.h>

using namespace std;

const string STANDARDIMAGE = "images/error.png";

class CLoadImage
{
public:
    CLoadImage(string  path);
    ~CLoadImage();
    static SDL_Surface * getSurface(string  path, string obj);
protected:
    static Logger logger;
private:
    string _Path;
    static SDL_Surface * loadStandardSurface();  // loads a "error" image to avoid crash in opengl
};

#endif // CLOADIMAGE_H
