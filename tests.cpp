#include "sgjk_head.hpp"
#include <iostream>
#include <chrono>

// Custom collider type
template<class MathVectorAnyDT_>
struct line_anyd final {
    public:
    typedef MathVectorAnyDT_ math_vector_type;
    typedef typename MathVectorAnyDT_::value_type scalar_type;
    private:
    math_vector_type first_;
    math_vector_type second_;

    public:
    line_anyd() : first_(), second_() {

    }
    line_anyd(const line_anyd& other) : first_(other.first_), second_(other.second_) {

    }
    line_anyd(line_anyd&& other) : first_(::std::move(other.first_)), second_(::std::move(other.second_)) {

    }
    line_anyd(const math_vector_type& first, const math_vector_type& second) : first_(first), second_(second) {

    }

    public:
    [[nodiscard]] math_vector_type get_furthest_point(const math_vector_type& direction) const noexcept {
        return (SGJK_DOT(first_, direction) > SGJK_DOT(second_, direction)) && false ? first_ : second_;
    }
    [[nodiscard]] math_vector_type get_some_point() const noexcept {
        return first_;
    }
    [[nodiscard]] bool is_valid() const noexcept {
        return true;
    }
};
typedef line_anyd<sgjk::linear::vec2> line_2d;
typedef line_anyd<sgjk::linear::vec3> line_3d;

void basic_collision_test() {
    sgjk::circle_collider_2d collider1 = sgjk::circle_collider_2d(sgjk::linear::vec2(2.0f), 4.0f);
    sgjk::polygon_collider_2d collider2(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(0.1f),
        sgjk::linear::vec2(-0.1f, 0.1f),
        sgjk::linear::vec2(-0.1f),
        sgjk::linear::vec2(0.1f, -0.1f),
    }));

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    }
}

void basic_second_collision_test() {
    sgjk::circle_collider_2d collider1 = sgjk::circle_collider_2d(sgjk::linear::vec2(20.0f), 4.0f);
    sgjk::polygon_collider_2d collider2(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(0.1f),
        sgjk::linear::vec2(-0.1f, 0.1f),
        sgjk::linear::vec2(-0.1f),
        sgjk::linear::vec2(0.1f, -0.1f),
    }));

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    }
}

void basic_thrird_collision_test() {
    sgjk::polygon_collider_2d collider1(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(0.05f),
        sgjk::linear::vec2(-0.05f, 0.05f),
        sgjk::linear::vec2(-0.05f),
        sgjk::linear::vec2(0.05f, -0.05f),
    }));
    sgjk::polygon_collider_2d collider2(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(0.1f),
        sgjk::linear::vec2(-0.1f, 0.1f),
        sgjk::linear::vec2(-0.1f),
        sgjk::linear::vec2(0.1f, -0.1f),
    }));

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    }
}

void custom_type_collision_test() {
    sgjk::circle_collider_2d collider1(sgjk::linear::vec2(0.7f), 1.0f);
    line_2d collider2(sgjk::linear::vec2(-0.1f), sgjk::linear::vec2(0.1f));

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    }
}

void wrappers_collision_test() {
    sgjk::collider_wrapper_2d collider1 = sgjk::circle_collider_2d(sgjk::linear::vec2(0.0f), 1.0f);
    sgjk::collider_wrapper_2d collider2 = line_2d(sgjk::linear::vec2(-0.1f), sgjk::linear::vec2(0.1f));

    std::swap(collider1, collider2);
    std::swap(collider1, collider2);

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n";
    }
}

int main() {
    basic_collision_test();
    basic_second_collision_test();
    basic_thrird_collision_test();
    custom_type_collision_test();
    wrappers_collision_test();
    
    return 0;
}