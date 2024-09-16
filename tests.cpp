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

// success or not
bool basic_collision_test() {
    std::cout << "basic collision test\n";

    sgjk::polygon_collider_2d collider1(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(-1.0f, 1.0),
        sgjk::linear::vec2(0.0f, -1.0f),
        sgjk::linear::vec2(1.0f, 1.0),
        sgjk::linear::vec2(1.0f, -1.0),
    }));
    sgjk::polygon_collider_2d collider2(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(-1.0f, -1.0),
        sgjk::linear::vec2(0.0f, 1.0f),
        sgjk::linear::vec2(1.0f, -1.0),
        sgjk::linear::vec2(1.0f, 1.0),
    }));
    for (auto& i : collider2.get_vertices()) {
        i.x += 0.3f;
        i.y += 0.0f;
    }

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        const auto simplex = collisionDetector.get_simplex_data();
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration. Simplex: { (" 
        << simplex[0].x << ", " << simplex[0].y << "), ("
        << simplex[1].x << ", " << simplex[1].y << "), ("
        << simplex[2].x << ", " << simplex[2].y << ") "
        << "}\n\n";
        return true;
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n\n";
        return false;
    }
    return false;
}

// success or not
bool basic_second_collision_test() {
    std::cout << "second basic collision test\n";

    sgjk::circle_collider_2d collider1 = sgjk::circle_collider_2d(sgjk::linear::vec2(20.0f), 4.0f);
    sgjk::polygon_collider_2d collider2(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(-1.0f),
        sgjk::linear::vec2(-1.0f, 1.0f),
        sgjk::linear::vec2(1.0f),
        sgjk::linear::vec2(1.0f, -1.0f),
    }));

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        const auto simplex = collisionDetector.get_simplex_data();
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration. Simplex: { (" 
        << simplex[0].x << ", " << simplex[0].y << "), ("
        << simplex[1].x << ", " << simplex[1].y << "), ("
        << simplex[2].x << ", " << simplex[2].y << ") "
        << "}\n\n";
        return false;
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n\n";
        return true;
    }
    return false;
}

// success or not
bool basic_thrird_collision_test() {
    std::cout << "third basic collision test\n";

    sgjk::polygon_collider_2d collider1(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(-1.0f),
        sgjk::linear::vec2(-1.0f, 1.0f),
        sgjk::linear::vec2(1.0f),
    }));
    /*
     * ._.
     * |/
     * `
     */
    sgjk::polygon_collider_2d collider2(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(0.9f, -0.9), 
        sgjk::linear::vec2(-0.9f, 0.9f),
        sgjk::linear::vec2(0.9f),
    }));
    /*
     * ._.
     *  \|
     *   `
     */
    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        const auto simplex = collisionDetector.get_simplex_data();
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration. Simplex: { (" 
        << simplex[0].x << ", " << simplex[0].y << "), ("
        << simplex[1].x << ", " << simplex[1].y << "), ("
        << simplex[2].x << ", " << simplex[2].y << ") "
        << "}\n\n";
        return true;
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n\n";
        return false;
    }
}

// success or not
bool epa_test() {
    std::cout << "epa test\n";

    sgjk::polygon_collider_2d collider1(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(1.0f),
        sgjk::linear::vec2(-1.0f, 1.0f),
        sgjk::linear::vec2(-1.0f), 
    }));
    sgjk::polygon_collider_2d collider2(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(1.0f),
        sgjk::linear::vec2(1.0f, -1.0f),
        sgjk::linear::vec2(-1.0f), 
    }));
    for (auto& i : collider2.get_vertices()) {
        i.x -= 0.5f;
        i.y += 0.0f;
    }

    sgjk::collision_detecter_2d collisionDetector;
    sgjk::linear::vec2 p;
    if (collisionDetector.is_collide(collider1, collider2)) {
        const auto simplex = collisionDetector.get_simplex_data();
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration. Simplex: { (" 
        << simplex[0].x << ", " << simplex[0].y << "), ("
        << simplex[1].x << ", " << simplex[1].y << "), ("
        << simplex[2].x << ", " << simplex[2].y << ") "
        << "}\n";
        p = collisionDetector.get_penetration_vector_unsafe(collider1, collider2, 0);
        std::cout << "penetration vector: " <<  p.x << ' ' << p.y << " " << collisionDetector.get_iteration_count() << '\n';
        for (auto& i : collider1.get_vertices()) {
            i -= p;
        }
        
        if (!collisionDetector.is_collide(collider1, collider2)) {
            std::cout << "shapes not intersect on " << collisionDetector.get_iteration_count() << " iteration. Simplex: { (" 
            << simplex[0].x << ", " << simplex[0].y << "), ("
            << simplex[1].x << ", " << simplex[1].y << "), ("
            << simplex[2].x << ", " << simplex[2].y << ") "
            << "}\n\n";

            return true;
        }
        p = collisionDetector.get_penetration_vector_unsafe(collider1, collider2, 0);
        std::cout << "second penetration vector: " <<  p.x << ' ' << p.y << " " << collisionDetector.get_iteration_count() << "\n\n";
        return false;

    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n\n";
        return false;
    }
    return false;
}

// success or not
bool custom_type_collision_test() {
    std::cout << "custom type\n";

    sgjk::circle_collider_2d collider1(sgjk::linear::vec2(0.7f), 1.0f);
    line_2d collider2(sgjk::linear::vec2(-0.1f), sgjk::linear::vec2(0.1f));

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        const auto simplex = collisionDetector.get_simplex_data();
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration. Simplex: { (" 
        << simplex[0].x << ", " << simplex[0].y << "), ("
        << simplex[1].x << ", " << simplex[1].y << "), ("
        << simplex[2].x << ", " << simplex[2].y << ") "
        << "}\n\n";
        return true;
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n\n";
        return false;
    }
    return false;
}

// success or not
bool wrappers_collision_test() {
    std::cout << "wrappers test\n";

    sgjk::collider_wrapper_2d collider1 = sgjk::circle_collider_2d(sgjk::linear::vec2(0.0f), 1.0f);
    sgjk::collider_wrapper_2d collider2 = line_2d(sgjk::linear::vec2(-0.1f), sgjk::linear::vec2(0.1f));

    std::swap(collider1, collider2);
    std::swap(collider1, collider2);

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        const auto simplex = collisionDetector.get_simplex_data();
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration. Simplex: { (" 
        << simplex[0].x << ", " << simplex[0].y << "), ("
        << simplex[1].x << ", " << simplex[1].y << "), ("
        << simplex[2].x << ", " << simplex[2].y << ") "
        << "}\n\n";
        return true;
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n\n";
        return false;
    }
    return false;
}

// success or not
bool edge_collision_test() {
    std::cout << "edge collision test\n";

    sgjk::polygon_collider_2d collider1(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(-1.0f),
        sgjk::linear::vec2(-1.0f, 1.0f),
        sgjk::linear::vec2(1.0f),
        sgjk::linear::vec2(1.0f, -1.0f),
    }));
    sgjk::polygon_collider_2d collider2(sgjk::polygon_collider_2d({
        sgjk::linear::vec2(-1.0f),
        sgjk::linear::vec2(-1.0f, 1.0f),
        sgjk::linear::vec2(1.0f),
        sgjk::linear::vec2(1.0f, -1.0f),
    }));
    for (auto& i : collider2.get_vertices()) {
        i.x += 2.0f;
        i.y += 0.0f;
    }

    sgjk::collision_detecter_2d collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        const auto simplex = collisionDetector.get_simplex_data();
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration. Simplex: { (" 
        << simplex[0].x << ", " << simplex[0].y << "), ("
        << simplex[1].x << ", " << simplex[1].y << "), ("
        << simplex[2].x << ", " << simplex[2].y << ") "
        << "}\n\n";
        return true;
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n\n";
        return false;
    }
    return false;
}

// success or not
bool int_collision_test() {
    using ivec2 = sgjk::linear::vec2T<int>;
    std::cout << "int collision test\n";

    sgjk::polygon_collider_anydt<ivec2> collider1(sgjk::polygon_collider_anydt<ivec2>({
        ivec2(-1),
        ivec2(-1, 1),
        ivec2(1),
        ivec2(1, -1),
    }));
    sgjk::polygon_collider_anydt<ivec2> collider2(sgjk::polygon_collider_anydt<ivec2>({
        ivec2(-1),
        ivec2(-1, 1),
        ivec2(1),
        ivec2(1, -1),
    }));
    for (auto& i : collider2.get_vertices()) {
        i.x += 1;
        i.y += 0;
    }

    sgjk::collision_detecter_2dt<ivec2> collisionDetector;
    if (collisionDetector.is_collide(collider1, collider2)) {
        const auto simplex = collisionDetector.get_simplex_data();
        std::cout << "shapes intersect on " << collisionDetector.get_iteration_count() << " iteration. Simplex: { (" 
        << simplex[0].x << ", " << simplex[0].y << "), ("
        << simplex[1].x << ", " << simplex[1].y << "), ("
        << simplex[2].x << ", " << simplex[2].y << ") "
        << "}\n\n";
        return true;
    } else {
        std::cout << "shapes do not intersect on " << collisionDetector.get_iteration_count() << " iteration\n\n";
        return false;
    }
    return false;
}

template<class FirstColliderT_, class SecondColliderT_>
[[nodiscard]] ::std::vector<sgjk::linear::vec2> build_needed_minkovsky_differens(const FirstColliderT_& first, const SecondColliderT_& second, float eps = 0.01) {
    ::std::vector<sgjk::linear::vec2> points;
    
    for (float radians = 0.0f; radians < (3.14151f * 2.0f); radians += eps) {
        const sgjk::linear::vec2 direction = sgjk::linear::vec2(cos(radians), sin(radians));
        if (points.empty()) {
            ::std::cout << '(' << direction.x << ", " << direction.y << ")\n";
            points.push_back(sgjk::support(first, second, direction));
        } else {
            const sgjk::linear::vec2 newPoint = sgjk::support(first, second, direction);
            if (newPoint != points.back()) {
                ::std::cout << '(' << direction.x << ", " << direction.y << ")\n";
                points.push_back(newPoint);
            }
        }
    }
    return points;
}

int main() {
    int successCount = 0;
    successCount += basic_collision_test();
    successCount += basic_second_collision_test();
    successCount += basic_thrird_collision_test();
    successCount += epa_test();
    successCount += custom_type_collision_test();
    successCount += wrappers_collision_test();
    
    bool edgeCollisionResult = edge_collision_test();
    bool intCollisionResult = int_collision_test();

    ::std::cout << successCount << "/6\n";

    if (edgeCollisionResult)
        ::std::cout << "edge collision test: true\n";
    else
        ::std::cout << "edge collision test: false\n";

    if (intCollisionResult)
        ::std::cout << "int collision test: true\n";
    else
        ::std::cout << "int collision test: false\n";
    return 0;
}
