#ifndef EYAX_GAMESTATE_HPP
#define EYAX_GAMESTATE_HPP

/**SFML and OpenGL**/
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

/**Standard library**/
#include <iostream>

namespace eyax {

class Application;

class GameState
{
    public:
        GameState(Application * parentApplication);

        void run();

        virtual bool init() = 0;

        virtual void update(const sf::Time& dt) = 0; /**For game mechanics code**/
        virtual void render(const sf::Time& dt) = 0; /**Only rendering code**/

        virtual void handleEvents(const sf::Event& e) = 0; /**For handling events**/
        /**NOTE : The engine is already handling window closing through sf::Event::Closed**/

        virtual void cleanup() = 0;

        void quit();

    protected:

    Application * application;

    private:

        sf::Clock m_clock;
        sf::Time m_time;
        sf::Event m_event;

        bool m_isRunning;
};

} // namespace eyax

#endif // EYAX_GAMESTATE_HPP
