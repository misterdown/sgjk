# SGJK: Simple GJK Collision Detection Library

SGJK is a single .hpp file C++11 library for collision detection using the Gilbert-Johnson-Keerthi (GJK) algorithm. This library provides a flexible and efficient way to detect collisions between convex shapes in both 2D and 3D spaces.

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [License](#license)

## Features

- Supports 2D and 3D collision detection.
- Uses the GJK algorithm for efficient collision detection.
- Provides a flexible and extensible framework for defining custom colliders.
- Supports various mathematical operations on vectors.
- Includes predefined colliders for polygons and circles.
## Installation

To use SGJK in your project, simply include the `sgjk_head.hpp` header file in your source code. Additionally, you can customize various aspects of the library by defining specific macros before including the header.

### Including the Header

```cpp
#include "sgjk_head.hpp"
```

### Customizing Macros

SGJK allows you to customize various aspects of the library by defining specific macros before including the header. This can help you avoid dependencies and tailor the library to your specific needs.

#### Assertions

By default, SGJK uses the standard `assert` macro for assertions. You can override this by defining the `SGJK_ASSERT` macro before including the header.

```cpp
#define SGJK_ASSERT(expr__) your_custom_assert(expr__)
```

#### Default Container

SGJK uses `std::vector` as the default container. You can override this by defining the `SGJK_DEFAULT_CONTAINER` macro before including the header.

```cpp
#define SGJK_DEFAULT_CONTAINER your_custom_container
```

#### Move Semantics

SGJK uses `std::move` for move semantics. You can override this by defining the `SGJK_MOVE` macro before including the header.

```cpp
#define SGJK_MOVE(obj__) your_custom_move(obj__)
```

#### Size Type

SGJK uses `size_t` as the default size type. You can override this by defining the `SGJK_SIZE_TYPE` macro before including the header.

```cpp
#define SGJK_SIZE_TYPE your_custom_size_type
```

#### Vector Types

SGJK provides default vector types for 2D and 3D vectors. You can override these by defining the `SGJK_DEFAULT_VEC2D` and `SGJK_DEFAULT_VEC3D` macros before including the header.

```cpp
#define SGJK_DEFAULT_VEC2D your_custom_vec2d
#define SGJK_DEFAULT_VEC3D your_custom_vec3d
```

#### Mathematical Operations

SGJK provides default implementations for mathematical operations such as `dot`, `length`, `normalized`, and `cross`. You can override these by defining the `SGJK_DOT`, `SGJK_LENGTH`, `SGJK_NORMALIZED`, and `SGJK_CROSS` macros before including the header.

```cpp
#define SGJK_DOT(first__, second__) your_custom_dot(first__, second__)
#define SGJK_LENGTH(vec__) your_custom_length(vec__)
#define SGJK_NORMALIZED(vec__) your_custom_normalized(vec__)
#define SGJK_CROSS(first__, second__) your_custom_cross(first__, second__)
```

By customizing these macros, you can avoid dependencies and tailor the SGJK library to your specific needs.

## Usage

### Vector Operations

SGJK provides a `vec2T` and `vec3T` template class for 2D and 3D vectors, respectively. These classes support various mathematical operations such as addition, subtraction, dot product, cross product, and normalization.

```cpp
sgjk::linear::vec2 v1(1.0f, 2.0f);
sgjk::linear::vec2 v2(3.0f, 4.0f);

sgjk::linear::vec2 v3 = v1 + v2;
float dotProduct = sgjk::linear::dot(v1, v2);
```

### Colliders

SGJK provides predefined colliders for polygons, circles and wapper for any collider type. You can also define your own custom colliders by implementing the required methods.

#### Polygon Collider

```cpp
std::vector<sgjk::linear::vec2> vertices = {
    sgjk::linear::vec2(0.0f, 0.0f),
    sgjk::linear::vec2(1.0f, 0.0f),
    sgjk::linear::vec2(1.0f, 1.0f),
    sgjk::linear::vec2(0.0f, 1.0f)
};

sgjk::polygon_collider_2d polygonCollider(vertices);
```

#### Circle Collider

```cpp
sgjk::linear::vec2 center(0.0f, 0.0f);
float radius = 1.0f;

sgjk::circle_collider_2d circleCollider(center, radius);
```
#### Wrapper

```cpp
std::vector<sgjk::linear::vec2> vertices = {
    sgjk::linear::vec2(0.0f, 0.0f),
    sgjk::linear::vec2(1.0f, 0.0f),
    sgjk::linear::vec2(1.0f, 1.0f),
    sgjk::linear::vec2(0.0f, 1.0f)
};
sgjk::polygon_collider_2d polygonCollider(vertices);

sgjk::linear::vec2 center(0.0f, 0.0f);
float radius = 1.0f;
sgjk::circle_collider_2d circleCollider(center, radius);

sgjk::collider_wrapper_2d wrapper(circleCollider);
wrapper = polygonCollider;
```

### Collision Detection

SGJK provides collision detectors for 2D and 3D spaces. You can use these detectors to check for collisions between two colliders.

```cpp
sgjk::collision_detecter_2d collisionDetector;

bool isColliding = collisionDetector.is_collide(polygonCollider, circleCollider);
```

## Examples

### 2D Collision Detection

```cpp
#include "sgjk_head.hpp"
#include <iostream>

int main() {
    const std::vector<sgjk::linear::vec2> vertices1{
        sgjk::linear::vec2(0.0f, 0.0f),
        sgjk::linear::vec2(1.0f, 0.0f),
        sgjk::linear::vec2(1.0f, 1.0f),
        sgjk::linear::vec2(0.0f, 1.0f)
    };

    const std::vector<sgjk::linear::vec2> vertices2{
        sgjk::linear::vec2(2.0f, 2.0f),
        sgjk::linear::vec2(3.0f, 2.0f),
        sgjk::linear::vec2(3.0f, 3.0f),
        sgjk::linear::vec2(2.0f, 3.0f)
    };

    sgjk::polygon_collider_2d collider1(vertices1);
    sgjk::polygon_collider_2d collider2(vertices2);

    sgjk::collision_detecter_2d collisionDetector;

    if (collisionDetector.is_collide(collider1, collider2)) {
        std::cout << "Shapes intersect\n";
    } else {
        std::cout << "Shapes do not intersect\n";
    }

    return 0;
}
```

### 3D Collision Detection

```cpp
#include "sgjk_head.hpp"
#include <iostream>

int main() {
    const std::vector<sgjk::linear::vec3> vertices1{
        sgjk::linear::vec2(0.0f, 0.0f, 0.0f),
        sgjk::linear::vec2(1.0f, 0.0f, 0.0f),
        sgjk::linear::vec2(1.0f, 1.0f, 0.0f),
        sgjk::linear::vec2(0.0f, 1.0f, 0.0f),
        sgjk::linear::vec2(0.0f, 0.0f, 1.0f),
        sgjk::linear::vec2(1.0f, 0.0f, 1.0f),
        sgjk::linear::vec2(1.0f, 1.0f, 1.0f),
        sgjk::linear::vec2(0.0f, 1.0f, 1.0f)
    };
    sgjk::polygon_collider_3d collider1(vertices1);

    sgjk::linear::vec3 center(0.0f);
    float radius = 1.0f;
    sgjk::circle_collider_3d collider2(center, radius);

    sgjk::collision_detecter_3d collisionDetector;

    if (collisionDetector.is_collide(collider1, collider2)) {
        std::cout << "Shapes intersect\n";
    } else {
        std::cout << "Shapes do not intersect\n";
    }

    return 0;
}
```

### 2D Collision Detection With Wappers
```cpp
int main() {
    const std::vector<sgjk::vec2> vertices{
        sgjk::linear::vec2(0.1f),
        sgjk::linear::vec2(0.1f, -0.1f),
        sgjk::linear::vec2(-0.1f, 0.1f),
        sgjk::linear::vec2(-0.1f),
    };
    sgjk::linear::vec2 center(0.0f);
    float radius = 1.0f;

    sgjk::collider_wrapper_2d collider1 = sgjk::circle_collider_2d(center, radius);
    sgjk::collider_wrapper_2d collider2 = sgjk::polygon_collider_2d(vertices);

    if (collisionDetector.is_collide(collider1, collider2)) {
        std::cout << "Shapes intersect\n";
    } else {
        std::cout << "Shapes do not intersect\n";
    }
    
    return 0;
}
```

## License

SGJK is released under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Acknowledgments

SGJK is inspired by the GJK algorithm and various implementations of collision detection libraries. Special thanks to the authors of these algorithms.
