#include "sillyrabbit/GameState.hpp"

/**Engine**/
#include <sillyrabbit/Application.hpp>

#ifdef SILLYRABBIT_DEBUG
    float debug_forcelock_time = 0;
#endif // SILLYRABBIT_DEBUG

namespace sr {

GameState::GameState(Application* parentApplication)
    : application(parentApplication), m_isRunning(true)
{ }

bool GameState::init()
{
    return true;
}

void GameState::update(const sf::Time& dt)
{ }

void GameState::render(const sf::Time& dt)
{ }

void GameState::handleEvents(const sf::Event& e)
{ }

void GameState::run()
{
    if(!init())
    {
        std::cerr << "Error while initializing game state [2]" << std::endl;
        exit(2);
    }

    while(m_isRunning)
    {
        #ifdef SILLYRABBIT_DEBUG /**If using the Debug version of the engine**/
        ///This code if for force unlocking. To avoid getting the mouse stuck. It's useful but only
        ///accessible in Debug for practical reasons

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                {
                    debug_forcelock_time += m_clock.getElapsedTime().asSeconds();
                    if(debug_forcelock_time >= 5)
                    {
                        application->unlockMouse();
                        debug_forcelock_time = 0;
                        application->window->setMouseCursorVisible(true);
                        std::cout << "SILLYRABBIT DEBUG MODE : Forced unlocked mouse." << std::endl;
                    }
                } else debug_forcelock_time = 0;

            } else debug_forcelock_time = 0;

        #endif // SILLYRABBIT_DEBUG

        while(application->window->pollEvent(m_event))
        {
            handleEvents(m_event);
            if(m_event.type == sf::Event::Closed)
            {
                quit();
                application->quit();
            }
            else if(m_event.type == sf::Event::LostFocus)
            {
                application->unlockMouse();
            }

        }

            m_time = m_clock.restart();

            if(application->isMouseLocked()) //Check for mouse locking.
            {
                application->setMouseDelta(sf::Vector2i(sf::Mouse::getPosition(*application->window).x - application->window->getSize().x/2,
                                          sf::Mouse::getPosition(*application->window).y - application->window->getSize().y/2));
                sf::Mouse::setPosition(sf::Vector2i(application->window->getSize().x/2, application->window->getSize().y/2), *application->window);
            }
            else application->setMouseDelta(sf::Vector2i(0,0));

            update(m_time);
            render(m_time);

            application->window->display();
    }

    cleanup();
}

void GameState::cleanup()
{ }


void GameState::quit()
{
    m_isRunning = false;
    application->popState();
}


}
