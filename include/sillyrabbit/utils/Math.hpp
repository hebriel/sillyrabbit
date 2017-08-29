#ifndef SILLYRABBIT_MATH_HPP
#define SILLYRABBIT_MATH_HPP

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define GLM_FORCE_RADIANS //Optional, but GLM will yell on you if you don't put it

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cmath>

namespace sr { namespace utils {

    template<typename T>
    glm::vec2 toGLMVector(sf::Vector2<T> vec) /**Might get deprecated in the future when 100% of the SFML methods will be supported directly by the engine**/
    {
        return glm::vec2(vec.x, vec.y);
    }

    template<typename T>
    glm::vec3 toGLMVector(sf::Vector3<T> vec) /**Might get deprecated in the future when 100% of the SFML methods will be supported directly by the engine**/
    {
        return glm::vec3(vec.x, vec.y, vec.z);
    }

} }

#endif // EYAX_MATH_HPP
