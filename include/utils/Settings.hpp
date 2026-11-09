#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <string>

struct WindowSettings {
    unsigned int nWidth, nHeight ;
    unsigned int nDefaultFPS ;
    std::string name ;
    // Constructor
    WindowSettings(unsigned int windowWidth = 800, unsigned int windowHeight = 600, std::string windowName = "RunWick", unsigned int FPS = 60)
        : nWidth(windowWidth), nHeight(windowHeight), name(std::move(windowName)), nDefaultFPS(FPS) {}
};

#endif // SETTINGS_HPP