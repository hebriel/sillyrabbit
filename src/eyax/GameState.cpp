#include "eyax/GameState.hpp"

/**Engine**/
#include <eyax/Application.hpp>

namespace eyax {

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
        while(application->window->pollEvent(m_event))
        {
            handleEvents(m_event);
            if(m_event.type == sf::Event::Closed)
            {
                quit();
                application->quit();
            }

            m_time = m_clock.restart();

            update(m_time);
            render(m_time);

            application->window->display();
        }
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


} // namespace eyax
