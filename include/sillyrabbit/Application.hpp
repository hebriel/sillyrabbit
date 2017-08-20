#ifndef SILLYRABBIT_APPLICATION_HPP
#define SILLYRABBIT_APPLICATION_HPP

/**SFML and OpenGL**/
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

/**Standard library**/
#include <iostream>
#include <stack>

/**Engine**/
#include "GameState.hpp"

namespace sr {

class Application
{
    friend class GameState;
    public:
        Application(const wchar_t* title, unsigned int width, unsigned int height, const sf::Uint32& style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
        Application(const char* title, unsigned int width, unsigned int height, const sf::Uint32& style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
        ~Application();

        int run();

        void pushState(GameState * state);
        void popState();

        virtual bool init() = 0;
        virtual void cleanup() = 0;

        sf::Window * window;

        void quit();

        void lockMouse(); /**Locks mouse movement. Used for relative mouse movement. You can then use getMouseDelta().**/
        ///WARNING! This functions changes the cursor position to the center of the window///
        ///Avoid getting stuck by preparing a way to unlock the mouse before using this!///

        ///IMPORTANT NOTE : If you're using the debug version of the engine, you can force unlock//
        ///To force unlock, press A and R for 5 seconds///

        void unlockMouse(); /**Unlock mouse movement (see documentation for lockMouse() for more explanation)**/

        sf::Vector2i getMouseDelta() /**Returns relative mouse movement (not 100% reliable if not used each frame)**/
        {return m_mouseDelta;}

        bool isMouseLocked()
        {return m_isMouseLocked;}

    protected:

    private:

        void setMouseDelta(const sf::Vector2i& newDelta);

        bool m_isRunning;
        std::stack<GameState*> m_states;

        bool m_isMouseLocked;
        sf::Vector2i m_mouseDelta;
};

}

#endif
