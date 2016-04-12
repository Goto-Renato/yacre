#ifndef RAY_HH_P9QUOIE0
#define RAY_HH_P9QUOIE0

#include <glm/fwd.hpp>

namespace yacre
{
    class Scene;
    class Object;

    class Ray
    {
        public:
            Ray(const glm::vec3 &orign, const glm::vec3 &direction):
                mOrign(orign), mDirection(direction) {}

            glm::vec3 GetOrigin() const {return mOrign;}
            glm::vec3 GetDirection() const {return mDirection;}

            /**
             * Casts a ray to find the color twards that direction.
             *
             * This method will result in recursive calls until bouncesLeft
             * is 0, in which case the color returned shall be the background
             * color.
             *
             * \param scene Scene in which the ray will be cast
             * \param bouncesLeft How many bounces (reflection or transmission)
             * there are left.
             * \return Color value generated by the ray
             */
            glm::vec3 Cast(const Scene &scene, unsigned bouncesLeft) const;

            /**
             * Traces a ray and finds the nearest intersection with an object.
             *
             * \param[in] scene Scene in wich the ray will be traced.
             * \param[out] distance If an intersection is found this will
             * be set to the distance between the ray's origin and the
             * intersection point.
             *
             * \return Pointer to the intersected object or NULL if no
             * intersection.
             */
            const Object* Trace(const Scene &scene, float &distance) const;

        private:
            glm::vec3 mOrign;
            glm::vec3 mDirection;
    };
}

#endif /* end of include guard: RAY_HH_P9QUOIE0 */
