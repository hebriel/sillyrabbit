#ifndef EYAX_APPLICATION_HPP
#define EYAX_APPLICATION_HPP

/**SFML and OpenGL**/
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

/**Standard library**/
#include <iostream>
#include <stack>

/**Engine**/
#include <eyax/GameState.hpp>

namespace eyax {

class Application
{
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

    protected:



    private:

        bool m_isRunning;
        std::stack<GameState*> m_states;
};

} // namespace eyax

#endif // EYAX_APPLICATION_HPP
