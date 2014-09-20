#include "SettingsParser.hpp"
#include <iostream>

int main()
{
    SettingsParser settings;
    if(!settings.loadFile("settings.txt"))
    {
        std::cout << "Error loading settings file!" << std::endl;
        return -1;
    }

    int width = 800;
    int height = 600;
    settings.get("width", width);
    settings.get("height", height);
    // if "width" and "height" are not found in the settings file their values are untouched 
    // (meaning you can easily set defaults like shown above)

    std::string str;
    settings.get("title", str);

    float gravity;
    settings.get("g", gravity);

    char ch;
    settings.get("player", ch);

    bool fullscreen;
    settings.get("fullscreen", fullscreen);

    int autoModeDuration;
    settings.get("autoModeDuration", autoModeDuration);

    //....

    settings.set("title", "SFML Settings Parser rocks!");
    settings.saveToFile(); // this is also done in the destructor


    return 0;
}