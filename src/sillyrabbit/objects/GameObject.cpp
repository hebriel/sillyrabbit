#include "sillyrabbit/objects/GameObject.hpp"

namespace sr { namespace objects {

GameObject::GameObject()
 : m_pitch(0), m_yaw(0), m_roll(0)
{ }

GameObject::~GameObject()
{ }

void GameObject::setRotation(glm::vec3 rotation)
{
    m_pitch = rotation.x;
    m_yaw = rotation.y;
    m_roll = rotation.z;
}


} }
