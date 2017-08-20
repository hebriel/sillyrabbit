#include "states/myState.hpp"

namespace states {

myState::myState(sr::Application* parentApplication)
    : sr::GameState(parentApplication)
{

}

myState::~myState()
{

}

bool myState::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    return true;
}

void myState::update(const sf::Time& dt)
{

}

void myState::render(const sf::Time& dt)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3ub(255, 0, 0); glVertex2f(0.0f, 0.8f);
        glColor3ub(0, 255, 0); glVertex2f(0.8f, -0.8f);
        glColor3ub(0, 0, 255); glVertex2f(-0.8f, -0.8f);
    glEnd();
}

void myState::handleEvents(const sf::Event& e)
{

}

void myState::cleanup()
{

}


} // namespace states
