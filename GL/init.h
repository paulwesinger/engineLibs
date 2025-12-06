#ifndef INIT_H
#define INIT_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <stdint.h>
#include <glew.h>
#include <SDL.h>
#include <map>
#include <logger.h>
// #include "utils/utils.h"   --> ersetzen durch Converter
#include "shaders/shader.h"
#include "base2d/base2d.h"
#include "camera/camera.h"
#include "defines.h"
#include "defaults.h"
#include "projection/projection.h"
#include "baseobject/baseobject.h"

// static flags for handler in derrived classes
extern bool _ShowSkybox;
extern bool _Animate;
extern bool _UseBlend;
extern bool _ShowCockpit;
extern bool _ShowPanel;   // DrawPanel für 2D
extern bool _QuitGame;

class Init
{
public:
    Init( std::string titel = "OpenGL");
    Init(const Init& orig);

    void setRootPath(std::string path);
    // Create Context and Init SDL2
    bool InitSDL2();
    Shader * getShaderPtr();

    virtual void Run();
    virtual void Done();
    virtual void Quit();
    // Methode zum abbrechen
    void sdl_die( std::string msg);
    virtual ~Init();

    virtual void Prepare2D(); // Flags für Rendern einstellen
    virtual void Restore3D(); // Flags zurücksetzen
    // effects -> deklarien in FXExtensions
    //static void setFog(bool enable = false);
    SDL_Window *getWindow() const;
    void setWindow(SDL_Window *newWindow);

    SDL_GLContext getMaincontext() const;
    void setMaincontext(SDL_GLContext newMaincontext);

protected:
    Logger logger;
    std::vector<std::string> split(std::string const& input, std::string const& separator);
    //----------------------------------
    // Look and feel
    //----------------------------------
    virtual void Render();
    virtual void Render2D();

    virtual void Render2DUserObject();
    virtual void SetResolution(int resx,int resy);
    virtual bool HandleMessage();
    virtual void InitEngineObject();
    virtual void InitUserObjects();

    void SetClearColor(float r, float g, float b, float a);
    void setClearColor(float r, float g, float b);
    void toogleFullScreen();
    void LoadConfiguration();
    static bool toggleVal(bool val); 
    static void QuitStatic();

    // HandlerFuncs for Mouse
    virtual void OnMouseMove(int &x, int &y, Uint32 buttonstate);
    virtual void OnLeftMouseButtonUp(int &x, int &y);
    virtual void OnLeftMouseButtonDown( int &x, int &y);

    virtual void OnMainMenuStateChanged();

    //----------------------------------
    // Object creation
    // ---------------------------------
    void add2List(BaseObject * obj, ShaderType s);
    void add2Dobject(Base2D * obj);
    //void addButton(CButton* obj);
    virtual void ShowFramesPerSec();
    virtual void ShowCameraPos();

    bool _UseBlinn;
    void safeDelete(BaseObject * bo);

    Base2D * base2d;
    Camera * camera;  // = View !!

    fileUtil * filestream = nullptr;
    Projection * projection;
    // Liste für 3D objekte
    std::vector<BaseObject*> list3D;
    // Liste für die 2D Objekte
    std::vector<Base2D *> objects2D;

    // Members for navigating with the  mouse...
    MOUSE _Mouse;
    float MouseResX;
    float MouseResY;
    uint32  _MouseButtons;

/*
    irrklang::ISoundEngine * soundengine;
    irrklang::ISoundEngine * soundengine1;
    irrklang::ISoundEngine * soundengine2;
    irrklang::ISoundEngine * soundengine3;
    irrklang::ISound       * _Sound;
    bool _HasSound;
*/
    // Test Shader
    Shader * shader;
    GLuint glasshader;
    GLuint cubeshaderprog_color;
    GLuint cubeshaderprog_tex;
    GLuint cubeshaderprog_normals;
    GLuint cubeshaderprog_color_normal;
    GLuint sphereshader_color;
    GLuint lighttexture_shader;
    // Derzeit noch nicht verwendbar !!!
    GLuint line2DShader;
   // GLuint textfeldshader, textshader;
    ShaderType _CurrentShader;

    bool _ShaderChanged;
    bool _FullScreen ;


    //Flags for overrides
    bool _ShowFramesPerSecond   = false;
    bool _ShowMousePositions    = false;
    bool _ShowCameraPos         = false;
    uint32_t _Elapsed;

    // Global Resolution vars
    int _ResX;
    int _ResY;
    int _FramerateOut;
    float _CameraSpeed;

    std::string caption;
    FLOAT4 _ClearColor;

    const std::string MAIN_CFG = PATH::ROOT +"config/Engine/engine.cfg";
    const std::string SPACE = " ";

    const int  SD_WIDTH     =  1600;
    const int  SD_HEIGHT    =  1200;
    const int  FULLSCREEN_WIDTH = 3200;//1680.0f//1920.0f
    const int  FULLSCREEN_HEIGHT = 1800;//1050.0f//1200.0f

    SDL_Event       _Event;
    bool _LockClick = false;
private:


    void InitUtils();  // Fileutils,logs ,etc....
    void InitShaders();
    void InitMatrices();
    bool initSoundMachine();
    void DeleteUtils();
    void DeleteMatrices();
    void DeleteShaders();
    void PrintDisplayModes();

    SDL_Window * window;
    SDL_GLContext maincontext;

    SDL_DisplayMode DesktopDisplayMode;
    SDL_DisplayMode newDisplayMode;
};
#endif // INIT_H
