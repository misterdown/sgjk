# sgjk - Simple GJK

## Overview

sgjk is a simple implementation of the Gilbert–Johnson–Keerthi (GJK) algorithm. It supports C++11 and higher versions.

- [Features](#features)
- [Personal Experience](#personal-experience)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [License](#license)


## Features

- **No STD Dependencies(optional)**: sgjk can work without any standard library dependencies if you choose to redefine specific macros.
- **Custom Classes**: It supports user-defined vector, collider, and transform classes that meet modest requirements.
- **Collision Detection and Resolution**: sgjk can detect and resolve collisions in both 2D and 3D spaces.

## Personal Experience

The term "simple" is an **ABSOLUTE LIE**. This "simple" implementation has destroyed me from within. I tried to provide all possible ways to customize classes but forgot that in C++, you can customize **EVERYTHING**. Freedom of choice is the enemy of any programmer.

### Lessons Learned

While working on this project, I learned to suffer and do it with a smile. In reality, I learned a lot.

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

#### ETC

just define a macros.

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

####  Interface Requirements
Collider classes must implement an interface with the following methods:

- **get_some_point**: This method should return any point on the surface of the collider, taking into account any applied transformations.
- **get_furthest_point**: This method should find and return the furthest point in a given direction, taking into account any applied transformations.

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
    sgjk::linear::vec2(1.0f, 1.0f)
};
sgjk::polygon_collider_2d polygonCollider(vertices);

sgjk::linear::vec2 center(0.0f, 0.0f);
float radius = 1.0f;
sgjk::circle_collider_2d circleCollider(center, radius);

sgjk::collider_wrapper_2d wrapper;
wrapper = circleCollider;
wrapper = polygonCollider;
```

### Transforms
sgjk provides a flexible transform system that allows you to define and use custom transformations for your vectors. The transform system includes support for both 2D and 3D transformations, as well as a generic wrapper for any type of transformation.

#### Interface Requirements
Transform classes must implement an interface with the following methods:
- **transformed**: method that takes a vector of the corresponding type as input and returns a transformed vector. This method should apply the transformation to the input vector and return the result.

#### Transform Wrapper

The `transform_wrapper_anydt` template class allows you to wrap any transformation class that meets certain requirements. This wrapper provides a unified interface for applying transformations to vectors.

#### Empty Transform

The `empty_transform` template class provides a default transformation that does not modify the input vector.

#### 2D Transform

The `transform_2dt` template class provides a 2D transformation that includes translation and rotation.

#### 3D Transform

The `transform_3dt` template class provides a 3D transformation that includes translation and rotation around multiple axes.

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

## License

SGJK is released under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Acknowledgments

SGJK is inspired by the GJK algorithm and various implementations of collision detection libraries. Special thanks to the authors of these algorithms.
