#include "eyax/Application.hpp"

namespace eyax {

Application::Application(const wchar_t* title, unsigned int width, unsigned int height,
                         const sf::Uint32& style, const sf::ContextSettings& settings)
                            : window(new sf::Window(sf::VideoMode(width, height), title, style, settings)), m_isRunning(true)
{ }

Application::Application(const char* title, unsigned int width, unsigned int height,
                         const sf::Uint32& style, const sf::ContextSettings& settings)
                            : window(new sf::Window(sf::VideoMode(width, height), title, style, settings)), m_isRunning(true)
{ }

Application::~Application()
{
    delete window;
}

bool Application::init()
{
    return true;
}

void Application::cleanup()
{ }

int Application::run()
{
    if(!init())
    {
        std::cerr << "Error while initializing application [1]" << std::endl;
        return 1;
    }

    while(m_isRunning)
    {
        if(!m_states.empty())
        {
            m_states.top()->run();
        }
        else
        {
            std::cerr << "No game states to run [3]" << std::endl;
            return 3;
        }
    }

    return 0;
}

void Application::quit()
{
    m_isRunning = false;
    window->close();
}
void Application::pushState(GameState* state)
{
    m_states.push(state);
}

void Application::popState()
{
    m_states.pop();
}



} // namespace eyax
