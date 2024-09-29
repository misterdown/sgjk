/*  sgjk_head.hpp
    MIT License

    Copyright (c) 2024 Aidar Shigapov

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

// SGJK - "SIMPLE"(NO) GJK

#ifndef SGJK_HEAD_HPP_
#define SGJK_HEAD_HPP_ 1

#if (!(defined SGJK_ASSERT))
#   include <cassert>
#   define SGJK_ASSERT(expr__) assert(expr__)
#endif // !defined SGJK_ASSERT

#if (!(defined SGJK_DEFAULT_CONTAINER))
#   include <vector>
#   define SGJK_DEFAULT_CONTAINER ::std::vector
#endif // !defined SGJK_DEFAULT_CONTAINER

#if (!(defined SGJK_MOVE))
#   include <utility>
#   define SGJK_MOVE(obj__) (::std::move(obj__))
#endif // !defined SGJK_MOVE

#if (!(defined SGJK_SIZE_TYPE))
#   include <cstdint>
#   define SGJK_SIZE_TYPE size_t // long long a BIT faster with O2 or O3
#endif // !defined SGJK_SIZE_TYPE

#if (!(defined SGJK_MAX_VALUE_OF))
#   include <limits>
#   define SGJK_MAX_VALUE_OF(T__) (::std::numeric_limits<T__>::max())
#endif // !defined SGJK_MAX_VALUE_OF

#if (!(defined SGJK_ABS))
#   include <cmath>
#   define SGJK_ABS(val__) (::std::abs(val__))
#endif // !defined SGJK_ABS

#if (!(defined SGJK_COS))
#   include <cmath>
#   define SGJK_COS(val__) (::std::cos(val__))
#endif // !defined SGJK_COS

#if (!(defined SGJK_SIN))
#   include <cmath>
#   define SGJK_SIN(val__) (::std::cos(val__))
#endif // !defined SGJK_SIN

#if (!(defined SGKJ_NOT_IMPLEMENT_VECTORS)) /////////////////////////////////////////////////////////////
#if (!(defined SGJK_DEFAULT_VEC2D))
#      define SGJK_DEFAULT_VEC2D ::sgjk::linear::vec2
#   endif // !defined SGJK_VEC2D
#   if (!(defined SGJK_DEFAULT_VEC3D))
#      define SGJK_DEFAULT_VEC3D ::sgjk::linear::vec3
#endif // !defined SGJK_VEC3D


#if (!(defined SGJK_SQRT))
#   include <cmath>
#   define SGJK_SQRT(v__) (::std::sqrt(v__))
#endif // !defined( SGJK_SQR )

#define SGJK__2D_OPER_SCALAR_MUT(oper) template<class ScalarType> vec2T<ScalarType>& operator oper (vec2T<ScalarType>& vec, const ScalarType& scalar) noexcept { vec.x oper scalar; vec.y oper scalar; return vec;}
#define SGJK__2D_OPER_SCALAR_CONST(oper) \
    template<class ScalarType> [[nodiscard]] vec2T<ScalarType> operator oper (const vec2T<ScalarType>& vec, const ScalarType& scalar) noexcept { return vec2T<ScalarType>(vec.x oper scalar, vec.y oper scalar); }\
    template<class ScalarType> [[nodiscard]] vec2T<ScalarType> operator oper (const ScalarType& scalar, const vec2T<ScalarType>& vec) noexcept { return vec2T<ScalarType>(scalar oper vec.x, scalar oper vec.y); }
#define SGJK__2D_OPER_SCALAR_BOOL(oper, del) \
    template<class ScalarType> [[nodiscard]] bool operator oper (const vec2T<ScalarType>& vec, const ScalarType& scalar) noexcept { return ((vec.x oper scalar) del (vec.y oper scalar));}\
    template<class ScalarType> [[nodiscard]] bool operator oper (const ScalarType& scalar, const vec2T<ScalarType>& vec) noexcept { return ((scalar oper vec.x) del (scalar oper vec.y));}
#define SGJK__2D_OPER_VEC_MUT(oper) template<class ScalarType> vec2T<ScalarType>& operator oper (vec2T<ScalarType>& vec, const vec2T<ScalarType>& other) noexcept { vec.x oper other.x; vec.y oper other.y; return vec;}
#define SGJK__2D_OPER_VEC_CONST(oper) template<class ScalarType> [[nodiscard]] vec2T<ScalarType> operator oper (const vec2T<ScalarType>& vec, const vec2T<ScalarType>& other) noexcept { return vec2T<ScalarType>(vec.x oper other.x, vec.y oper other.y); }
#define SGJK__2D_OPER_VEC_BOOL(oper, del) template<class ScalarType> [[nodiscard]] bool operator oper (const vec2T<ScalarType>& left, const vec2T<ScalarType>& rigth) noexcept { return ((left.x oper rigth.x) del (left.y oper rigth.y));}
/*GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG*/
/*GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG*/
/*GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG*/
#define SGJK__3D_OPER_SCALAR_MUT(oper) template<class ScalarType> vec3T<ScalarType>& operator oper (vec3T<ScalarType>& vec, const ScalarType& scalar) noexcept { vec.x oper scalar; vec.y oper scalar; vec.z oper scalar; return vec;}
#define SGJK__3D_OPER_SCALAR_CONST(oper) \
    template<class ScalarType> [[nodiscard]] vec3T<ScalarType> operator oper (const vec3T<ScalarType>& vec, const ScalarType& scalar) noexcept { return vec3T<ScalarType>(vec.x oper scalar, vec.y oper scalar, vec.z oper scalar); }\
    template<class ScalarType> [[nodiscard]] vec3T<ScalarType> operator oper (const ScalarType& scalar, const vec3T<ScalarType>& vec) noexcept { return vec3T<ScalarType>(scalar oper vec.x, scalar oper vec.y, scalar oper vec.z); }
#define SGJK__3D_OPER_SCALAR_BOOL(oper, del) \
    template<class ScalarType> [[nodiscard]] bool operator oper (const vec3T<ScalarType>& vec, const ScalarType& scalar) noexcept { return ((vec.x oper scalar) del (vec.y oper scalar) del (vec.z oper scalar));}\
    template<class ScalarType> [[nodiscard]] bool operator oper (const ScalarType& scalar, const vec3T<ScalarType>& vec) noexcept { return ((scalar oper vec.x) del (scalar oper vec.y) del (scalar oper vec.z));}
#define SGJK__3D_OPER_VEC_MUT(oper) template<class ScalarType> vec3T<ScalarType>& operator oper (vec3T<ScalarType>& vec, const vec3T<ScalarType>& other) noexcept { vec.x oper other.x; vec.y oper other.y; vec.z oper other.z; return vec;}
#define SGJK__3D_OPER_VEC_CONST(oper) template<class ScalarType> [[nodiscard]] vec3T<ScalarType> operator oper (const vec3T<ScalarType>& vec, const vec3T<ScalarType>& other) noexcept { return vec3T<ScalarType>(vec.x oper other.x, vec.y oper other.y, vec.z oper other.z); }
#define SGJK__3D_OPER_VEC_BOOL(oper, del) template<class ScalarType> [[nodiscard]] bool operator oper (const vec3T<ScalarType>& left, const vec3T<ScalarType>& rigth) noexcept { return ((left.x oper rigth.x) del (left.y oper rigth.y) del (left.z oper rigth.z));}

namespace sgjk  {
    namespace linear {
        /**
         * @brief a 2D vector class template.
         * 
         * @tparam ScalarType the type of the scalar components.
         */
        template<class ScalarType>
        struct vec2T {
            public:
            typedef ScalarType value_type; 
            
            public:
            union {
                struct {
                    value_type x, y;
                };
                value_type data_[2];
            };

            public:
            vec2T() : x((ScalarType)0), y((ScalarType)0) {

            }
            vec2T(const value_type& scalar) noexcept : x(scalar), y(scalar) {

            }
            vec2T(const value_type& x_, const value_type& y_) noexcept : x(x_), y(y_) {

            }

            public:
            [[nodiscard]] value_type& operator[](SGJK_SIZE_TYPE i) {
                return data_[i];
            }
            [[nodiscard]] const value_type& operator[](SGJK_SIZE_TYPE i) const {
                return data_[i];
            }

            public:
            [[nodiscard]] constexpr SGJK_SIZE_TYPE size() const noexcept {
                return 2;
            }
            [[nodiscard]] value_type* data() noexcept {
                return data_;
            }
            [[nodiscard]] const value_type* data() const noexcept {
                return data_;
            }
 
        };
        /**
         * @brief Calculates the dot product of two vectors. @tparam ScalarType the type of the scalar components. @param first the first vector.  @param second the second vector. @return The dot product of the two vectors.
         */
        template<class ScalarType>
        [[nodiscard]] ScalarType dot(const vec2T<ScalarType>& first, const vec2T<ScalarType>& second) noexcept {
            return (first.x * second.x) + (first.y * second.y);
        }
        /**
         * @brief Calculates the length of a vector. @tparam ScalarType the type of the scalar components. @param vec the vector. @return The length of the vector.
         */
        template<class ScalarType>
        [[nodiscard]] ScalarType length(const vec2T<ScalarType>& vec) noexcept {
            return SGJK_SQRT(dot(vec, vec));
            //return SGJK_SQRT(vec.x * vec.x + vec.y * vec.y);

            // no differens on O0
        }
        /**
         * @brief Normalizes a vector. @tparam ScalarType the type of the scalar components. @param vec the vector.
         */
        template<class ScalarType>
        void normalize(vec2T<ScalarType>& vec) noexcept {
            const ScalarType len = length(vec);
            if (len == (ScalarType)0)
                return;
            vec.x /= len;
            vec.y /= len;
        }
        /**
         * @brief Normalizes a vector. @tparam ScalarType the type of the scalar components. @param vec the vector. @return The normalized vector.
         */
        template<class ScalarType>
        [[nodiscard]] vec2T<ScalarType> normalized(const vec2T<ScalarType>& vec) noexcept {
            const ScalarType len = length(vec);
            if (len == (ScalarType)0)
                return vec2T<ScalarType>();
            return vec / len;
        }
        /**
         * @brief Calculates the cross product of two vectors. @tparam ScalarType the type of the scalar components. @param a the first vector. @param b the second vector. @return The cross product of the two vectors.
         */
        template<class ScalarType>
        [[nodiscard]] ScalarType cross(const vec2T<ScalarType>& a, const vec2T<ScalarType>& b) noexcept {
            return (a.x * b.y) - (a.y * b.x);
        }

        SGJK__2D_OPER_SCALAR_MUT(+=)
        SGJK__2D_OPER_SCALAR_MUT(-=)
        SGJK__2D_OPER_SCALAR_MUT(*=)
        SGJK__2D_OPER_SCALAR_MUT(/=)
        SGJK__2D_OPER_SCALAR_CONST(+)
        SGJK__2D_OPER_SCALAR_CONST(-)
        SGJK__2D_OPER_SCALAR_CONST(*)
        SGJK__2D_OPER_SCALAR_CONST(/)

        SGJK__2D_OPER_SCALAR_BOOL(==, &&);
        SGJK__2D_OPER_SCALAR_BOOL(!=, ||);

        SGJK__2D_OPER_VEC_MUT(+=)
        SGJK__2D_OPER_VEC_MUT(-=)
        SGJK__2D_OPER_VEC_MUT(*=)
        SGJK__2D_OPER_VEC_MUT(/=)
        SGJK__2D_OPER_VEC_CONST(+)
        SGJK__2D_OPER_VEC_CONST(-)
        SGJK__2D_OPER_VEC_CONST(*)
        SGJK__2D_OPER_VEC_CONST(/)

        SGJK__2D_OPER_VEC_BOOL(==, &&);
        SGJK__2D_OPER_VEC_BOOL(!=, ||);
        
        template<class ScalarType>
        [[nodiscard]] vec2T<ScalarType> operator-(const vec2T<ScalarType>& vec) noexcept {
            return vec2T<ScalarType>(-vec.x, -vec.y);
        }
        typedef vec2T<float> vec2;

        /**
         * @brief a 3D vector class template.
         * 
         * @tparam ScalarType the type of the scalar components.
         */
        template<class ScalarType>
        struct vec3T {
            public:
            typedef ScalarType value_type; 
            
            public:
            union {
                struct {
                    value_type x, y, z;
                };
                value_type data_[3];
            };

            public:
            vec3T() : x((ScalarType)0), y((ScalarType)0), z((ScalarType)0) {

            }
            vec3T(const value_type& scalar) noexcept : x(scalar), y(scalar), z(scalar) {

            }
            vec3T(const value_type& x_, const value_type& y_, const value_type& z_) noexcept : x(x_), y(y_), z(z_) {

            }

            public:
            [[nodiscard]] value_type& operator[](SGJK_SIZE_TYPE i) {
                return data_[i];
            }
            [[nodiscard]] const value_type& operator[](SGJK_SIZE_TYPE i) const {
                return data_[i];
            }

            public:
            [[nodiscard]] constexpr SGJK_SIZE_TYPE size() const noexcept {
                return 3;
            }
            [[nodiscard]] value_type* data() noexcept {
                return data_;
            }
            [[nodiscard]] const value_type* data() const noexcept {
                return data_;
            }
 
        };
        /**
         * @brief Calculates the dot product of two vectors. @tparam ScalarType the type of the scalar components. @param first the first vector.  @param second the second vector. @return The dot product of the two vectors.
         */
        template<class ScalarType>
        [[nodiscard]] ScalarType dot(const vec3T<ScalarType>& first, const vec3T<ScalarType>& second) noexcept {
            return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
        }
        /**
         * @brief Calculates the length of a vector. @tparam ScalarType the type of the scalar components. @param vec the vector. @return The length of the vector.
         */
        template<class ScalarType>
        [[nodiscard]] ScalarType length(const vec3T<ScalarType>& vec) noexcept {
            return SGJK_SQRT(dot(vec, vec));
        }
        /**
         * @brief Normalizes a vector. @tparam ScalarType the type of the scalar components. @param vec the vector.
         */
        template<class ScalarType>
        void normalize(vec3T<ScalarType>& vec) noexcept {
            const ScalarType len = length(vec);
            if (len == (ScalarType)0)
                return;
            vec.x /= len;
            vec.y /= len;
            vec.z /= len;
        }
        /**
         * @brief Normalizes a vector. @tparam ScalarType the type of the scalar components. @param vec the vector. @return The normalized vector.
         */
        template<class ScalarType>
        [[nodiscard]] vec3T<ScalarType> normalized(const vec3T<ScalarType>& vec) noexcept {
            const ScalarType len = length(vec);
            if (len == (ScalarType)0)
                return vec3T<ScalarType>();
            return vec / len;
        }
        /**
         * @brief Calculates the cross product of two vectors. @tparam ScalarType the type of the scalar components. @param a the first vector. @param b the second vector. @return The cross product of the two vectors.
         */
        template<class ScalarType>
        [[nodiscard]] vec3T<ScalarType> cross(const vec3T<ScalarType>& a, const vec3T<ScalarType>& b) noexcept {
            return vec3T<ScalarType>(
                (a.y * b.z) - (a.z * b.y),
                (a.z * b.x) - (a.x * b.z),
                (a.x * b.y) - (a.y * b.x)
            );
        }

        SGJK__3D_OPER_SCALAR_MUT(+=)
        SGJK__3D_OPER_SCALAR_MUT(-=)
        SGJK__3D_OPER_SCALAR_MUT(*=)
        SGJK__3D_OPER_SCALAR_MUT(/=)
        SGJK__3D_OPER_SCALAR_CONST(+)
        SGJK__3D_OPER_SCALAR_CONST(-)
        SGJK__3D_OPER_SCALAR_CONST(*)
        SGJK__3D_OPER_SCALAR_CONST(/)

        SGJK__3D_OPER_SCALAR_BOOL(==, &&);
        SGJK__3D_OPER_SCALAR_BOOL(!=, ||);

        SGJK__3D_OPER_VEC_MUT(+=)
        SGJK__3D_OPER_VEC_MUT(-=)
        SGJK__3D_OPER_VEC_MUT(*=)
        SGJK__3D_OPER_VEC_MUT(/=)
        SGJK__3D_OPER_VEC_CONST(+)
        SGJK__3D_OPER_VEC_CONST(-)
        SGJK__3D_OPER_VEC_CONST(*)
        SGJK__3D_OPER_VEC_CONST(/)

        SGJK__3D_OPER_VEC_BOOL(==, &&);
        SGJK__3D_OPER_VEC_BOOL(!=, ||);
        
        template<class ScalarType>
        [[nodiscard]] vec3T<ScalarType> operator-(const vec3T<ScalarType>& vec) noexcept {
            return vec3T<ScalarType>(-vec.x, -vec.y, -vec.z);
        }

        typedef vec3T<float> vec3;
    };
};


#if (!(defined SGJK_DOT))
#   define SGJK_DOT(first__, second__) (::sgjk::linear::dot(first__, second__)) // define default dot.
#endif // !defined SGJK_DOT
#if (!(defined SGJK_LENGTH))
#   define SGJK_LENGTH(vec__) (::sgjk::linear::length(vec__)) // define default length.
#endif // !defined SGJK_LENGTH
#if (!(defined SGJK_NORMALIZE))
#   define SGJK_NORMALIZE(vec__) (::sgjk::linear::normalize(vec__)) // define default normalize.
#endif // !defined SGJK_NORMALIZE
#if (!(defined SGJK_NORMALIZED))
#   define SGJK_NORMALIZED(vec__) (::sgjk::linear::normalized(vec__)) // define default normalized.
#endif // !defined SGJK_NORMALIZED
#if (!(defined SGJK_CROSS))
#   define SGJK_CROSS(first__, second__) (::sgjk::linear::cross(first__, second__)) // define default normalized.
#endif // !defined SGJK_NORMALIZED

#else

#if (!(defined SGJK_DEFAULT_VEC2D))
    static_assert(false, "implement your own vec2 class")
#endif // !defined SGJK_VEC2D
#if (!(defined SGJK_DEFAULT_VEC3D))
    static_assert(false, "implement your own vec3 class")
#endif // !defined SGJK_VEC3D

#if (!(defined SGJK_DOT))
    static_assert(false, "define own SGJK_DOT");
#endif // !defined SGJK_DOT
#if (!(defined SGJK_LENGTH))
    static_assert(false, "define own SGJK_LENGTH");
#endif // !defined SGJK_LENGTH
#if (!(defined SGJK_NORMALIZE))
#   define SGJK_NORMALIZE(vec__) (::sgjk::linear::normalize(vec__)) // define default normalized.
#endif // !defined SGJK_NORMALIZE
#if (!(defined SGJK_NORMALIZED))
    static_assert(false, "define own SGJK_NORMALIZED");
#endif // !defined SGJK_NORMALIZED
#if (!(defined SGJK_CROSS))
    static_assert(false, "define own SGJK_CROSS");
#endif // !defined SGJK_NORMALIZED
#endif // !defined SGKJ_NOT_IMPLEMENT_VECTORS

namespace sgjk  {
    // avoid std.
    template<class T1__, class T2__>
    struct is_realy_the_same {
        static constexpr bool value = false;
    };
    template<class T__>
    struct is_realy_the_same<T__, T__> {
        static constexpr bool value = true;
    };
    // avoid std.
    template<class T__>
    struct really_remove_referens {
        typedef T__ type;
    };
    template<class T__>
    struct really_remove_referens<T__&> {
        typedef T__ type;
    };
    template<class T__>
    struct really_remove_referens<T__&&> {
        typedef T__ type;
    };
    template<class T__>
    struct really_remove_referens<const T__&> {
        typedef const T__ type;
    };
    template<class T__>
    struct really_remove_referens<const T__&&> {
        typedef const T__ type;
    };

    template<class T1__, class T2__>
    struct simple_pair {
        public:
        T1__ first;
        T2__ second;

        public:
        simple_pair(const T1__& f, const T2__& s) : first(f), second(s) {

        }
        simple_pair(T1__&& f, T2__&& s) : first(SGJK_MOVE(f)), second(SGJK_MOVE(s)) {

        }
    };
    
    template<class T__>
    struct single_t_pair {
        public:
        typedef T__ value_type;

        public:
        value_type first;
        value_type second;

        single_t_pair(const value_type& f, const value_type& s) : first(f), second(s) {

        }
        single_t_pair(value_type&& f, value_type&& s) : first(SGJK_MOVE(f)), second(SGJK_MOVE(s)) {

        }
    };
    template<class MathVectorAnyDT_>
    struct transform_wrapper_anydt {
        public:
        typedef MathVectorAnyDT_ math_vector_type;
        typedef typename MathVectorAnyDT_::value_type scalar_type;

        private:
        struct transform_wrapper_support {
            public:
            virtual ~transform_wrapper_support() = default;

            public:
            [[nodiscard]] virtual math_vector_type transformed(const math_vector_type& point) const noexcept = 0;
            [[nodiscard]] virtual transform_wrapper_support* clone() const = 0;
        };

        template<class ToWrappT_>
        struct transform_wrapper_support_t : transform_wrapper_support {
            public:
            ToWrappT_ transform_;

            public:
            transform_wrapper_support_t(const ToWrappT_& transform) : transform_(transform) {

            }
            transform_wrapper_support_t(ToWrappT_&& transform) noexcept : transform_(SGJK_MOVE(transform)) {

            }

            public:
            [[nodiscard]] math_vector_type transformed(const math_vector_type& point) const noexcept override {
                return transform_.transformed(point);
            }
            [[nodiscard]] transform_wrapper_support* clone() const override { 
                return new transform_wrapper_support_t(*this);
            }
        };

        private:
        transform_wrapper_support* wrapped_;

        public:
        transform_wrapper_anydt() noexcept : wrapped_(nullptr) {

        }
        transform_wrapper_anydt(const transform_wrapper_support& other) {
            if (other.wrapped_ != nullptr) {
                wrapped_ = other.wrapped_->clone();
                SGJK_ASSERT(wrapped_ != nullptr);
            } else {
                wrapped_ = nullptr;
            }
        }
        transform_wrapper_anydt(transform_wrapper_anydt&& other) noexcept : wrapped_(other.wrapped_) {
            other.wrapped_ = nullptr;
        }
        template<class TransfromT_>
        transform_wrapper_anydt(const TransfromT_& transform) : wrapped_(new transform_wrapper_support_t<TransfromT_>(transform)) {
            static_assert(is_realy_the_same<typename TransfromT_::math_vector_type, math_vector_type>::value, "math_vector_type of transform must be same as math_vector_type of wrapper");
            SGJK_ASSERT(wrapped_ != nullptr);
        }
        template<class TransfromT_>
        transform_wrapper_anydt(typename really_remove_referens<TransfromT_>::type&& transform) noexcept : wrapped_(new transform_wrapper_support_t<TransfromT_>(SGJK_MOVE(transform))) {
            static_assert(is_realy_the_same<typename TransfromT_::math_vector_type, math_vector_type>::value, "math_vector_type of transform must be same as math_vector_type of wrapper");
        }

        public:
        ~transform_wrapper_anydt() {
            if (wrapped_) {
                delete wrapped_;
                wrapped_ = nullptr;
            }
        }
        
        public:
        transform_wrapper_anydt& operator=(const transform_wrapper_anydt& other) {
            if (wrapped_) {
                delete wrapped_;
                wrapped_ = nullptr;
            }

            if (other.transform_ != nullptr) {
                wrapped_ = other.wrapped_->clone();
                SGJK_ASSERT(wrapped_ != nullptr);
            }
            return *this;
        }
        transform_wrapper_anydt& operator=(transform_wrapper_anydt&& other) {
            if (wrapped_)
                delete wrapped_;
            wrapped_ = other.wrapped_;
            other.wrapped_ = nullptr;
            return *this;
        }
        
        public:
        [[nodiscard]] math_vector_type transformed(const math_vector_type& point) const noexcept {
            return wrapped_->transformed(point);
        }
    };
    template<class MathVectorAnyDT_>
    struct empty_transform {
        public:
        typedef MathVectorAnyDT_ math_vector_type;

        public:
        empty_transform() {

        }

        public:
        [[nodiscard]] math_vector_type transformed(const math_vector_type& point) const noexcept {
            return point;
        }
    };

    template<class MathVector2T_>
    struct transform_2dt {
        public:
        typedef MathVector2T_ math_vector_type;
        typedef typename MathVector2T_::value_type scalar_type;

        private:
        math_vector_type position_;
        scalar_type radians_;

        public:
        transform_2dt() : position_(), radians_() {

        }
        transform_2dt(const math_vector_type& position, const scalar_type& radians) : position_(position), radians_(radians) {

        }

        public:
        [[nodiscard]] math_vector_type transformed(const math_vector_type& point) const noexcept {
            const scalar_type cos_theta = SGJK_COS(radians_);
            const scalar_type sin_theta = SGJK_SIN(radians_);

            return math_vector_type(
                cos_theta * point.x - sin_theta * point.y,
                sin_theta * point.x + cos_theta * point.y
            ) + position_;
        }

        public:
        void move(const math_vector_type& vel) noexcept {
            position_ += vel;
        }
        void rotate(const scalar_type& radDelta) noexcept {
            radians_ += radDelta;
        }
        
        public:
        [[nodiscard]] const math_vector_type& get_position() const noexcept {
            return position_;
        }
        [[nodiscard]] math_vector_type& get_position() noexcept {
            return position_;
        }
        [[nodiscard]] const scalar_type& get_rotation() const noexcept {
            return radians_;
        }
        [[nodiscard]] scalar_type& get_rotation() noexcept {
            return radians_;
        }
    };
    /// @brief specialization of transform_3dt for default vector2d class.
    typedef transform_2dt<SGJK_DEFAULT_VEC2D> transform2d;

    template<class MathVector3T_>
    struct transform_3dt {
        public:
        typedef MathVector3T_ math_vector_type;
        typedef typename MathVector3T_::value_type scalar_type;

        private:
        math_vector_type position_;
        math_vector_type radians_;

        public:
        transform_3dt() : position_(), radians_() {

        }
        transform_3dt(const math_vector_type& position, const math_vector_type& radians) : position_(position), radians_(radians) {

        }

        public:
        [[nodiscard]] math_vector_type transformed(const math_vector_type& point) const noexcept {
            // Dear compiler, PLEASE, optimize this
            const scalar_type cosX = SGJK_COS(radians_.x);
            const scalar_type sinX = SGJK_SIN(radians_.x);
            const scalar_type cosY = SGJK_COS(radians_.y);
            const scalar_type sinY = SGJK_SIN(radians_.y);
            const scalar_type cosZ = SGJK_COS(radians_.z);
            const scalar_type sinZ = SGJK_SIN(radians_.z);

            // MUHAHA. im crying.
            return math_vector_type(
                (cosY * cosZ * point.x) +
                (cosY * sinZ * point.y) -
                (sinY * point.z),

                (sinX * sinY * cosZ - cosX * sinZ * point.x) +
                (sinX * sinY * sinZ + cosX * cosZ * point.y) +
                (sinX * cosY * point.z),

                (cosX * sinY * cosZ + sinX * sinZ * point.x) +
                (cosX * sinY * sinZ - sinX * cosZ * point.y) +
                (cosX * cosY * point.z)
            ) + position_;
        }

        public:
        void move(const math_vector_type& vel) noexcept {
            position_ += vel;
        }
        void rotate(const math_vector_type& radDelta) noexcept {
            radians_ += radDelta;
        }

        public:
        [[nodiscard]] const math_vector_type& get_position() const noexcept {
            return position_;
        }
        [[nodiscard]] math_vector_type& get_position() noexcept {
            return position_;
        }
        [[nodiscard]] const math_vector_type& get_rotation() const noexcept {
            return radians_;
        }
        [[nodiscard]] math_vector_type& get_rotation() noexcept {
            return radians_;
        }
    };
    /// @brief specialization of transform_3dt for default vector3d class.
    typedef transform_3dt<SGJK_DEFAULT_VEC3D> transform3d;
    

    /**
     * @brief a wrapper for any collider type.
     *
     * @tparam MathVectorAnyDT_ the type of the math vector to use. The vector must implement math operators, 'dot', 'cross', and 'normalized'.
     */
    template<class MathVectorAnyDT_>
    struct collider_wrapper_anyd final {
        public:
        typedef MathVectorAnyDT_ math_vector_type;

        private:
        struct collider_wrapper_support {
            public:
            virtual ~collider_wrapper_support() = default;

            public:
            [[nodiscard]] virtual math_vector_type get_furthest_point(const math_vector_type& direction, const transform_wrapper_anydt<math_vector_type>& transform) const noexcept = 0;
            [[nodiscard]] virtual math_vector_type get_some_point(const transform_wrapper_anydt<math_vector_type>& transform) const noexcept = 0;
            [[nodiscard]] virtual bool is_valid() const noexcept = 0;
            [[nodiscard]] virtual collider_wrapper_support* clone() const = 0;
        };

        template<class ToWrappT_>
        struct collider_wrapper_support_t : collider_wrapper_support {
            public:
            ToWrappT_ collider_;

            public:
            collider_wrapper_support_t(const ToWrappT_& collider) : collider_(collider) {

            }
            collider_wrapper_support_t(ToWrappT_&& collider) noexcept : collider_(SGJK_MOVE(collider)) {

            }

            public:
            [[nodiscard]] math_vector_type get_furthest_point(const math_vector_type& direction, const transform_wrapper_anydt<math_vector_type>& transform) const noexcept override { return collider_.get_furthest_point(direction, transform); }
            [[nodiscard]] math_vector_type get_some_point(const transform_wrapper_anydt<math_vector_type>& transform) const noexcept override { return collider_.get_some_point(transform); }
            [[nodiscard]] bool is_valid() const noexcept override { return collider_.is_valid();};
            [[nodiscard]] collider_wrapper_support* clone() const override { return new collider_wrapper_support_t(*this);};

        };

        private:
        collider_wrapper_support* wrapped_;

        public:
        collider_wrapper_anyd() noexcept : wrapped_(nullptr) {

        }
        collider_wrapper_anyd(const collider_wrapper_anyd& other) {
            if (other.wrapped_ != nullptr) {
                wrapped_ = other.wrapped_->clone();
                SGJK_ASSERT(wrapped_ != nullptr);
            } else {
                wrapped_ = nullptr;
            }
        }
        collider_wrapper_anyd(collider_wrapper_anyd&& other) noexcept : wrapped_(other.wrapped_) {
            other.wrapped_ = nullptr;
        }
        template<class ColliderT_>
        collider_wrapper_anyd(const ColliderT_& collider) : wrapped_(new collider_wrapper_support_t<ColliderT_>(collider)) {
            static_assert(is_realy_the_same<typename ColliderT_::math_vector_type, math_vector_type>::value, "math_vector_type of collider must be same as math_vector_type of wrapper");
            SGJK_ASSERT(wrapped_ != nullptr);
        }
        template<class ColliderT_>
        collider_wrapper_anyd(typename really_remove_referens<ColliderT_>::type&& collider) noexcept : wrapped_(new collider_wrapper_support_t<ColliderT_>(SGJK_MOVE(collider))) {
            static_assert(is_realy_the_same<typename ColliderT_::math_vector_type, math_vector_type>::value, "math_vector_type of collider must be same as math_vector_type of wrapper");
        }

        public:
        ~collider_wrapper_anyd() {
            if (wrapped_) {
                delete wrapped_;
                wrapped_ = nullptr;
            }
        }
        
        public:
        collider_wrapper_anyd& operator=(const collider_wrapper_anyd& other) {
            if (wrapped_) {
                delete wrapped_;
                wrapped_ = nullptr;
            }

            if (other.collider_ != nullptr) {
                wrapped_ = other.wrapped_->clone();
                SGJK_ASSERT(wrapped_ != nullptr);
            }
            return *this;
        }
        collider_wrapper_anyd& operator=(collider_wrapper_anyd&& other) {
            if (wrapped_)
                delete wrapped_;
            wrapped_ = other.wrapped_;
            other.wrapped_ = nullptr;
            return *this;
        }
        
        public:
        template<class Transform2DT_>
        [[nodiscard]] math_vector_type get_furthest_point(const math_vector_type& direction, const Transform2DT_& transform) const noexcept {
            return wrapped_->get_furthest_point(direction, transform);
        }
        template<class Transform2DT_>
        [[nodiscard]] math_vector_type get_some_point(const Transform2DT_& transform) const noexcept {
            return wrapped_->get_some_point(transform);
        }
        [[nodiscard]] bool is_valid() const noexcept {
            return (wrapped_ != nullptr) && (wrapped_->is_valid());
        }
    };
    /// @brief specialization of collider_wrapper_anyd for 2d.
    typedef collider_wrapper_anyd<SGJK_DEFAULT_VEC2D> collider_wrapper_2d;
    /// @brief specialization of collider_wrapper_anyd for 3d.
    typedef collider_wrapper_anyd<SGJK_DEFAULT_VEC3D> collider_wrapper_3d;

    /**
     * @brief a polygon collider for any dimension.
     *
     * @tparam MathVectorAnyDT_ the type of the math vector to use. The vector must implement math operators, 'dot', 'cross', and 'normalized'.
     * @tparam ContainerT_ the type of the container to use for storing simplex_. The container type must implement '[]' operator, 'empty', 'size', work with iterators.
     */
    template<class MathVectorAnyDT_, class ContainerT_ = SGJK_DEFAULT_CONTAINER<MathVectorAnyDT_>>
    struct polygon_collider_anydt final {
        public:
        typedef MathVectorAnyDT_ math_vector_type;
        typedef typename MathVectorAnyDT_::value_type scalar_type;
        typedef ContainerT_ container_type;

        private:
        container_type vertices_;

        public:
        polygon_collider_anydt() : vertices_() {

        }
        polygon_collider_anydt(const container_type& verteces) : vertices_(verteces) {

        }
        polygon_collider_anydt(container_type&& verteces) : vertices_(SGJK_MOVE(verteces)) {

        }
        polygon_collider_anydt(const polygon_collider_anydt& other) : vertices_(other.vertices_) {

        }
        polygon_collider_anydt(polygon_collider_anydt&& other) : vertices_(SGJK_MOVE(other.vertices_)) {

        }

        public:
        polygon_collider_anydt& operator=(const polygon_collider_anydt& other) {
            vertices_ = other.vertices_;
            return *this;
        }
        polygon_collider_anydt& operator=(polygon_collider_anydt&& other) {
            vertices_ = SGJK_MOVE(other.vertices_);
            return *this;
        }

        public:
        template<class Transform2DT_>
        [[nodiscard]] math_vector_type get_furthest_point(const math_vector_type& direction, const Transform2DT_& transform) const noexcept {
            math_vector_type furthestPoint = transform.transformed(vertices_[0]);
            scalar_type maxProjection = SGJK_DOT(furthestPoint, direction); 
            for (SGJK_SIZE_TYPE i = 1; i < (SGJK_SIZE_TYPE)vertices_.size(); ++i) {
                const math_vector_type currentPoint = transform.transformed(vertices_[i]);
                const scalar_type projection = SGJK_DOT(currentPoint, direction);
                if (projection > maxProjection) {
                    maxProjection = projection;
                    furthestPoint = currentPoint;
                }
            }   
            return furthestPoint;
        }
        template<class Transform2DT_>
        [[nodiscard]] math_vector_type get_some_point(const Transform2DT_& transform) const noexcept {
            return transform.transformed(vertices_[0]);
        }
        [[nodiscard]] bool is_valid() const noexcept {
            return !vertices_.empty();
        }

        [[nodiscard]] container_type& get_vertices() noexcept {
            return vertices_;
        }
        [[nodiscard]] const container_type& get_vertices() const noexcept {
            return vertices_;
        }
    };
    /// @brief specialization of polygon_collider_anydt for 2d.
    typedef polygon_collider_anydt<SGJK_DEFAULT_VEC2D> polygon_collider_2d;
    /// @brief specialization of polygon_collider_anydt for 3d.
    typedef polygon_collider_anydt<SGJK_DEFAULT_VEC3D> polygon_collider_3d;

    /**
     * @brief a circle collider for any dimension.
     *
     * @tparam MathVectorAnyDT_ the type of the math vector to use. The vector must implement math operators, 'dot', 'cross', and 'normalized'.
     */
    template<class MathVectorAnyDT_>
    struct circle_collider_anydt final {
        public:
        typedef MathVectorAnyDT_ math_vector_type;
        typedef typename MathVectorAnyDT_::value_type scalar_type;

        private:
        math_vector_type centre_;
        scalar_type radius_;

        public:
        circle_collider_anydt() : centre_(), radius_() {

        }
        circle_collider_anydt(const math_vector_type& centre, const scalar_type& radius) : centre_(centre), radius_(radius) {

        }
        circle_collider_anydt(const circle_collider_anydt& other) : centre_(other.centre_), radius_(other.radius_) {

        }
        circle_collider_anydt(circle_collider_anydt&& other) noexcept : centre_(SGJK_MOVE(other.centre_)), radius_(SGJK_MOVE(other.radius_)) {

        }
        public:
        circle_collider_anydt& operator=(const circle_collider_anydt& other) {
            centre_ = other.centre_;
            radius_ = other.radius_;
            return *this;
        }
        circle_collider_anydt& operator=(circle_collider_anydt&& other) {
            centre_ = SGJK_MOVE(other.centre_);
            radius_ = SGJK_MOVE(other.radius_);
            return *this;
        }

        public:
        template<class Transform2DT_>
        [[nodiscard]] math_vector_type get_furthest_point(const math_vector_type& direction, const Transform2DT_& transform) const noexcept {
            return transform.transformed(centre_) + SGJK_NORMALIZED(direction) * radius_;
        }
        template<class Transform2DT_>
        [[nodiscard]] math_vector_type get_some_point(const Transform2DT_& transform) const noexcept {
            return transform.transformed(centre_);
        }
        [[nodiscard]] bool is_valid() const noexcept {
            return true;
        }

        [[nodiscard]] math_vector_type& get_centre() noexcept {
            return centre_;
        }
        [[nodiscard]] const math_vector_type& get_centre() const noexcept {
            return centre_;
        }
        [[nodiscard]] scalar_type& get_radius() noexcept {
            return radius_;
        }
        [[nodiscard]] const scalar_type& get_radius() const noexcept {
            return radius_;
        }
    };
    /// @brief specialization of circle_collider_anydt for 2d.
    typedef circle_collider_anydt<SGJK_DEFAULT_VEC2D> circle_collider_2d;
    /// @brief specialization of circle_collider_anydt for 3d.
    typedef circle_collider_anydt<SGJK_DEFAULT_VEC3D> circle_collider_3d;


    template<class FirstColliderT_, class SecondColliderT_, class FirstTransformT_ = empty_transform<typename FirstColliderT_::math_vector_type>, class SecondTransformT_ = empty_transform<typename SecondColliderT_::math_vector_type>>
    [[nodiscard]] static typename FirstColliderT_::math_vector_type support(
            const typename FirstColliderT_::math_vector_type& direction,
            const FirstColliderT_& first,
            const SecondColliderT_& second,
            const FirstTransformT_& firstTransform = FirstTransformT_{},
            const SecondTransformT_& secondTransform  = SecondTransformT_{}) {
        static_assert(is_realy_the_same<typename FirstColliderT_::math_vector_type, typename SecondColliderT_::math_vector_type>::value, "FirstColliderT_::math_vector_type and SecondColliderT_::math_vector_type must be equal");
        return first.get_furthest_point(direction, firstTransform) - second.get_furthest_point(-direction, secondTransform);
    }

    /**
     * @brief a collision detector for 2D vectors.
     *
     * @tparam MathVector2DT_ the type of the math vector to use.
     */
    template<class MathVector2DT_>
    struct collision_detecter_2dt final {
        private:
        typedef MathVector2DT_ math_vector_type;
        typedef typename MathVector2DT_::value_type scalar_type;
        
        private:
        SGJK_SIZE_TYPE iteration_;
        math_vector_type simplex_[3u];

        public:
        /**  
         * @brief Checks for collision between 2D colliders. Does not check the validity of the colliders before starting the algorithm. Check 'is_collide' for safety.
         * 
         * @tparam FirstCollider2DT_ the first type of collider. Must have method "get_furthest_point" that do not modify the object's state.
         * @tparam SecondCollider2DT_ the second type of collider. Must have method "get_furthest_point" that do not modify the object's state.
         * @param first first collider.
         * @param second second collider.
         * @param maxIterationCount the maximum number of iterations, after which false will be returned.
         * @return Whether a collision is present.
         */ 
        template<class FirstCollider2DT_, class SecondCollider2DT_, class FirstTransform2DT_ = empty_transform<math_vector_type>, class SecondTransform2DT_ = empty_transform<math_vector_type>>
        [[nodiscard]] bool is_collide_unsafe(
            const FirstCollider2DT_& first,
            const SecondCollider2DT_& second,
            const SGJK_SIZE_TYPE maxIterationCount = 16,
            const FirstTransform2DT_& firstTransform = FirstTransform2DT_{},
            const SecondTransform2DT_& secondTransform = SecondTransform2DT_{}) {

            static_assert(is_realy_the_same<typename FirstCollider2DT_::math_vector_type, math_vector_type>::value,  "vector types must be the same");
            static_assert(is_realy_the_same<typename SecondCollider2DT_::math_vector_type, math_vector_type>::value, "vector types must be the same");

            iteration_ = 0;

            math_vector_type direction = first.get_some_point(firstTransform) - second.get_some_point(secondTransform);
            math_vector_type supportPoint = support(direction, first, second, firstTransform, secondTransform);
            simplex_[0] = supportPoint;
            SGJK_SIZE_TYPE simplexSize = 1;
            direction = -supportPoint;

            for (; iteration_ < maxIterationCount; ++iteration_) {
                supportPoint = support(direction, first, second, firstTransform, secondTransform);
                /// Оно работает ПОДОЗРИТЕЛЬНО ХОРОШО. Мне СТРАШНО. TODO: Сделать этот метод хуже
                /// GJK не должен находить правильный ответ с 1 итерации гарантировано, с моим кодом что-то явно не так.

                if (SGJK_DOT(supportPoint, direction) <= (scalar_type)0)
                    return false; // false
                simplex_[simplexSize] = supportPoint;
                ++simplexSize;
                if (simplexSize == 2) {
                    const math_vector_type ao = -simplex_[0];
                    const math_vector_type ab = simplex_[1] - simplex_[0];
                    math_vector_type abPerp = math_vector_type(-ab.y, ab.x);
                    if (SGJK_DOT(abPerp, ao) < (scalar_type)0)
                        abPerp = -abPerp;
                    direction = abPerp;
                } else if (simplexSize == 3) {
                    const math_vector_type ab = simplex_[1] - simplex_[0];
                    const math_vector_type ao = -simplex_[0];
                    const math_vector_type bc = simplex_[2] - simplex_[1];
                    const math_vector_type bo = -simplex_[1];
                    const math_vector_type ca = simplex_[0] - simplex_[2];
                    const math_vector_type co = -simplex_[2];
                    if ((SGJK_CROSS(ab, ao) >= (scalar_type)0 && SGJK_CROSS(bc, bo) >= (scalar_type)0 && SGJK_CROSS(ca, co) >= (scalar_type)0) ||
                        (SGJK_CROSS(ab, ao) <= (scalar_type)0 && SGJK_CROSS(bc, bo) <= (scalar_type)0 && SGJK_CROSS(ca, co) <= (scalar_type)0)) {
                        return true;
                    } else {
                        simplex_[1] = simplex_[0];
                        simplex_[0] = simplex_[2];
                        simplexSize = 2;
                        const math_vector_type aon = -simplex_[0];
                        const math_vector_type abn = simplex_[1] - simplex_[0];
                        math_vector_type abnPerp = math_vector_type(-abn.y, abn.x);
                        if (SGJK_DOT(abnPerp, aon) < (scalar_type)0)
                            abnPerp = -abnPerp;
                        direction = abnPerp;
                    }
                } else {
                    SGJK_ASSERT(false);
                    return false;
                }
            }
            return false;
        }
        /**  
         * @brief Checks for collision between 2D colliders. Checks the validity of the colliders before starting the algorithm.
         * 
         * @tparam FirstCollider2DT_ the first type of collider. Must have method and "get_furthest_point" that do not modify the object's state.
         * @tparam SecondCollider2DT_ the second type of collider. Must have method "get_furthest_point" that do not modify the object's state.
         * @param first first collider.
         * @param second second collider.
         * @param maxIterationCount the maximum number of iterations, after which false will be returned.
         * @return Whether a collision is present.
         */ 
        template<class FirstCollider2DT_, class SecondCollider2DT_, class FirstTransform2DT_ = empty_transform<math_vector_type>, class SecondTransform2DT_ = empty_transform<math_vector_type>>
        [[nodiscard]] bool is_collide(
            const FirstCollider2DT_& first,
            const SecondCollider2DT_& second,
            const SGJK_SIZE_TYPE maxIterationCount = 16,
            const FirstTransform2DT_& firstTransform = FirstTransform2DT_{},
            const SecondTransform2DT_& secondTransform = SecondTransform2DT_{}) {

            static_assert(is_realy_the_same<typename FirstCollider2DT_::math_vector_type, math_vector_type>::value,  "vector types must be the same");
            static_assert(is_realy_the_same<typename SecondCollider2DT_::math_vector_type, math_vector_type>::value, "vector types must be the same");
            
            if (!(first.is_valid() && second.is_valid())) {
                iteration_ = 0;
                return false;
            }

            return is_collide_unsafe(first, second, maxIterationCount, firstTransform, secondTransform);
        }
        template<class FirstCollider2DT_, class SecondCollider2DT_, class FirstTransform2DT_ = empty_transform<math_vector_type>, class SecondTransform2DT_ = empty_transform<math_vector_type>>
        [[nodiscard]] math_vector_type get_penetration_vector_unsafe(
            const FirstCollider2DT_& first,
            const SecondCollider2DT_& second, 
            const scalar_type toleranceDistance = 0.001,
            const SGJK_SIZE_TYPE maxIterationCount = 16,
            const FirstTransform2DT_& firstTransform = FirstTransform2DT_{},
            const SecondTransform2DT_& secondTransform = SecondTransform2DT_{}) {

            static_assert(is_realy_the_same<typename FirstCollider2DT_::math_vector_type, math_vector_type>::value,  "vector types must be the same");
            static_assert(is_realy_the_same<typename SecondCollider2DT_::math_vector_type, math_vector_type>::value, "vector types must be the same");

            iteration_ = 0;

            SGJK_SIZE_TYPE minIndex = 0;
            scalar_type minDistance = SGJK_MAX_VALUE_OF(scalar_type);
            math_vector_type minNormal;

            SGJK_DEFAULT_CONTAINER<math_vector_type> polytope(simplex_, simplex_ + 3);

            for (; (iteration_ < maxIterationCount) && (minDistance == SGJK_MAX_VALUE_OF(scalar_type)); ++iteration_) {
                for (SGJK_SIZE_TYPE i = 0; i < polytope.size(); ++i) {
                    SGJK_SIZE_TYPE j = (i + 1) % polytope.size();

                    const math_vector_type vertexI = polytope[i];
                    const math_vector_type vertexJ = polytope[j];

                    const math_vector_type ij = vertexJ - vertexI;

                    math_vector_type normal = SGJK_NORMALIZED(math_vector_type(-ij.y, ij.x));
                    scalar_type distance = SGJK_DOT(normal, vertexI);

                    if (distance < (scalar_type)0) {
                        distance = -distance;
                        normal = -normal;
                    }

                    if (distance < minDistance) {
                        minDistance = distance;
                        minNormal = normal;
                        minIndex = j;
                    }
                }
                const math_vector_type supportPoint = support(minNormal, first, second, firstTransform, secondTransform);
                const scalar_type sDistance = SGJK_DOT(minNormal, supportPoint);

                if (SGJK_ABS(sDistance - minDistance) > toleranceDistance) {
                    minDistance = SGJK_MAX_VALUE_OF(scalar_type);
                    polytope.insert(polytope.begin() + minIndex, {supportPoint});
                }
            }

            return minNormal * (minDistance + toleranceDistance);
        }

        [[nodiscard]] SGJK_SIZE_TYPE get_iteration_count() const noexcept {
            return iteration_ + 1;
        }
        [[nodiscard]] const math_vector_type* get_simplex_data() const noexcept {
            return simplex_;
        }
    };
    typedef collision_detecter_2dt<SGJK_DEFAULT_VEC2D> collision_detecter_2d;

    /**
     * @brief a collision detector for 3D vectors.
     *
     * @tparam MathVector3DT_ the type of the math vector to use.
     */
    template<class MathVector3DT_>
    struct collision_detecter_3dt final {
        private:
        typedef MathVector3DT_ math_vector_type;
        typedef typename MathVector3DT_::value_type scalar_type;
        
        private:
        SGJK_SIZE_TYPE iteration_;
        math_vector_type simplex_[4u];

        public:
        /**  
         * @brief Checks for collision between 3D colliders. Does not check the validity of the colliders before starting the algorithm. Check 'is_collide' for safety.
         * 
         * @tparam FirstCollider3DT_ the first type of collider. Must have method  and "get_furthest_point" that do not modify the object's state.
         * @tparam SecondCollider3DT_ the second type of collider. Must have method  and "get_furthest_point" that do not modify the object's state.
         * @param first first collider.
         * @param second second collider.
         * @param maxIterationCount the maximum number of iterations, after which false will be returned.
         * @return Whether a collision is present.
         */ 
        template<class FirstCollider3DT_, class SecondCollider3DT_, class FirstTransform3DT_ = empty_transform<math_vector_type>, class SecondTransform3DT_ = empty_transform<math_vector_type>>
        [[nodiscard]] bool is_collide_unsafe(
            const FirstCollider3DT_& first,
            const SecondCollider3DT_& second, 
            const SGJK_SIZE_TYPE maxIterationCount = 32,
            const FirstTransform3DT_& firstTransform = FirstTransform3DT_{},
            const SecondTransform3DT_& secondTransform = SecondTransform3DT_{}) {

            static_assert(is_realy_the_same<typename FirstCollider3DT_::math_vector_type, math_vector_type>::value,  "vector types must be the same");
            static_assert(is_realy_the_same<typename SecondCollider3DT_::math_vector_type, math_vector_type>::value, "vector types must be the same");

            iteration_ = 0;

            math_vector_type direction = first.get_some_point(firstTransform) - second.get_some_point(secondTransform);
            math_vector_type supportPoint = support(direction, first, second, firstTransform, secondTransform);
            simplex_[0] = supportPoint;
            SGJK_SIZE_TYPE simplexSize = 1;
            direction = -supportPoint;

            for (; iteration_ < maxIterationCount; ++iteration_) {
                supportPoint = support(direction, first, second, firstTransform, secondTransform);
                if (SGJK_DOT(supportPoint, direction) <= (scalar_type)0) {
                    return false;
                }
                simplex_[simplexSize] = supportPoint;
                ++simplexSize;
                if (simplexSize == 2) {
                    const math_vector_type ab = simplex_[1] - simplex_[0];
                    const math_vector_type ao = -simplex_[0];
                    if (SGJK_DOT(ab, ao) > 0) {
                        direction = SGJK_CROSS(SGJK_CROSS(ab, ao), ab);
                        if (direction == math_vector_type(0, 0, 0)) { // paralel vectors. Collision detect. If colliders intersect, then simplex must be valid. Fill simplex with something. 
                            const math_vector_type abPerp = math_vector_type(-ab.y, ab.x, ab.z);
                            simplex_[2] = support(abPerp, first, second, firstTransform, secondTransform);
                            const math_vector_type ac = simplex_[2] - simplex_[0];
                            simplex_[3] = support(SGJK_CROSS(ab, ac), first, second, firstTransform, secondTransform);
                            return true;
                        }
                    } else {
                        simplex_[0] = simplex_[1];
                        direction = -simplex_[1];
                        simplexSize = 1;
                    }
                    
                } else if (simplexSize == 3) {
                    const math_vector_type ao = -simplex_[0];
                    const math_vector_type ac = simplex_[2] - simplex_[0];
                    const math_vector_type ab = simplex_[1] - simplex_[0];
                    direction = SGJK_CROSS(ac, ab);

                    if (SGJK_DOT(direction, ao) < (scalar_type)0) 
                        direction = -direction;
                } else if (simplexSize == 4) {
                    const math_vector_type da = simplex_[3] - simplex_[0];
                    const math_vector_type db = simplex_[3] - simplex_[1];
                    const math_vector_type dc = simplex_[3] - simplex_[2];
                    const math_vector_type d0 = -simplex_[3];

                    const math_vector_type abdPerp = SGJK_CROSS(da, db);
                    const math_vector_type bcdPerp = SGJK_CROSS(db, dc);
                    const math_vector_type cadPerp = SGJK_CROSS(dc, da);

                    if (SGJK_DOT(abdPerp, d0) > (scalar_type)0) {
                        simplex_[2] = simplex_[3];
                        simplexSize = 3; // Old siplex [A, B, C, D] - new [A, B, D]
                        direction = abdPerp;
                    } else if (SGJK_DOT(bcdPerp, d0) > (scalar_type)0) {
                        simplex_[0] = simplex_[1];
                        simplex_[1] = simplex_[2];
                        simplex_[2] = simplex_[3];
                        simplexSize = 3; // Old siplex [A, B, C, D] - new [B, C, D]
                        direction = bcdPerp;
                    } else if (SGJK_DOT(cadPerp, d0) > (scalar_type)0) {
                        simplex_[1] = simplex_[2];
                        simplex_[2] = simplex_[3];
                        simplexSize = 3; // Old siplex [A, B, C, D] - new [A, C, D]
                        direction = cadPerp;
                    } else {
                        return true;
                    }
                } else {
                    SGJK_ASSERT(false);
                    return false;
                }
            }
            return false;
        }
        /**  
         * @brief Checks for collision between 3D colliders. Checks the validity of the colliders before starting the algorithm.
         * 
         * @tparam FirstCollider3DT_ the first type of collider. Must have method and "get_furthest_point" that do not modify the object's state.
         * @tparam SecondCollider3DT_ the second type of collider. Must have method  and "get_furthest_point" that do not modify the object's state.
         * @param first first collider.
         * @param second second collider.
         * @param maxIterationCount the maximum number of iterations, after which false will be returned.
         * @return Whether a collision is present.
         */ 
        template<class FirstCollider3DT_, class SecondCollider3DT_, class FirstTransform3DT_ = empty_transform<math_vector_type>, class SecondTransform3DT_ = empty_transform<math_vector_type>>
        [[nodiscard]] bool is_collide(
            const FirstCollider3DT_& first,
            const SecondCollider3DT_& second, 
            const SGJK_SIZE_TYPE maxIterationCount = 32,
            const FirstTransform3DT_& firstTransform = FirstTransform3DT_{},
            const SecondTransform3DT_& secondTransform = SecondTransform3DT_{}) {

            static_assert(is_realy_the_same<typename FirstCollider3DT_::math_vector_type, math_vector_type>::value,  "vector types must be the same");
            static_assert(is_realy_the_same<typename SecondCollider3DT_::math_vector_type, math_vector_type>::value, "vector types must be the same");
            
            if (!(first.is_valid() && second.is_valid())) {
                iteration_ = 0;
                return false;
            }

            return is_collide_unsafe(first, second, maxIterationCount, firstTransform, secondTransform);
        }

        template<class FirstCollider3DT_, class SecondCollider3DT_, class FirstTransform3DT_ = empty_transform<math_vector_type>, class SecondTransform3DT_ = empty_transform<math_vector_type>>
        [[nodiscard]] math_vector_type get_penetration_vector_unsafe(
            const FirstCollider3DT_& first,
            const SecondCollider3DT_& second, 
            const scalar_type toleranceDistance = 0.001,
            const SGJK_SIZE_TYPE maxIterationCount = 32,
            const FirstTransform3DT_& firstTransform = FirstTransform3DT_{},
            const SecondTransform3DT_& secondTransform = SecondTransform3DT_{}) {

            static_assert(is_realy_the_same<typename FirstCollider3DT_::math_vector_type, math_vector_type>::value,  "vector types must be the same");
            static_assert(is_realy_the_same<typename SecondCollider3DT_::math_vector_type, math_vector_type>::value, "vector types must be the same");

            const auto addEndgeIfUnique = [](SGJK_DEFAULT_CONTAINER<single_t_pair<SGJK_SIZE_TYPE>>& edges, SGJK_DEFAULT_CONTAINER<SGJK_SIZE_TYPE>& faces, SGJK_SIZE_TYPE i, SGJK_SIZE_TYPE j) {
                const auto simpleFind = [](const SGJK_DEFAULT_CONTAINER<single_t_pair<SGJK_SIZE_TYPE>>& edges, SGJK_DEFAULT_CONTAINER<SGJK_SIZE_TYPE>& faces, SGJK_SIZE_TYPE i, SGJK_SIZE_TYPE j) {
                    auto it = edges.begin();
                    for (;it != edges.end(); ++it) {
                        const auto& val = *it;
                        if ((val.first == faces[j]) && (val.second == faces[i]))
                            return it;
                    }
                    return it;
                };
                auto reverse = simpleFind(edges, faces, i, j);

                if (reverse != edges.end())
                    edges.erase(reverse);
                else
                    edges.push_back(single_t_pair<SGJK_SIZE_TYPE>(faces[i], faces[j]));
            };

            /// @return simple_pair<SGJK_DEFAULT_CONTAINER<simple_pair<math_vector_type, scalar_type>>, SGJK_SIZE_TYPE> 
            const auto getFaceNormals = [](const SGJK_DEFAULT_CONTAINER<math_vector_type>& polytope, const SGJK_DEFAULT_CONTAINER<SGJK_SIZE_TYPE>& faces) {
                SGJK_DEFAULT_CONTAINER<simple_pair<math_vector_type, scalar_type>> normals;
                SGJK_SIZE_TYPE minTriangle = 0;
                scalar_type minDistance = SGJK_MAX_VALUE_OF(scalar_type);

                for (SGJK_SIZE_TYPE i = 0; i < faces.size(); i += 3) {
                    const math_vector_type& a = polytope[faces[i]];
                    const math_vector_type& b = polytope[faces[i + 1]];
                    const math_vector_type& c = polytope[faces[i + 2]];

                    math_vector_type normal = SGJK_NORMALIZED(SGJK_CROSS((b - a), (c - a)));
                    float distance = SGJK_DOT(normal, a);

                    if (distance < (scalar_type)0) {
                        normal = -normal;
                        distance = -distance;
                    }

                    normals.push_back(simple_pair<math_vector_type, scalar_type>{normal, distance});
            
                    if (distance < minDistance) {
                        minTriangle = i / 3;
                        minDistance = distance;
                    }
                }
                return simple_pair<SGJK_DEFAULT_CONTAINER<simple_pair<math_vector_type, scalar_type>>, SGJK_SIZE_TYPE>(normals, minTriangle);
            };

            iteration_ = 0;

            SGJK_DEFAULT_CONTAINER<math_vector_type> polytope(simplex_, simplex_ + 4);
            SGJK_DEFAULT_CONTAINER<SGJK_SIZE_TYPE> faces{
                0, 1, 2,
                0, 3, 1,
                0, 2, 3,
                1, 3, 2
            };

            scalar_type minDistance = SGJK_MAX_VALUE_OF(scalar_type);
            math_vector_type minNormal;

            auto defaultNormalsData = getFaceNormals(polytope, faces);
            auto& normals = defaultNormalsData.first;
            auto minFace = defaultNormalsData.second;

            for (; (iteration_ < maxIterationCount) && (minDistance == SGJK_MAX_VALUE_OF(scalar_type)); ++iteration_) {
                minNormal = normals[minFace].first;
                minDistance = normals[minFace].second;

                const math_vector_type supportPoint = support(minNormal, first, second, firstTransform, secondTransform);
                const scalar_type sDistance = SGJK_DOT(minNormal, supportPoint);

                if (SGJK_ABS(sDistance - minDistance) > toleranceDistance) {
                    minDistance = SGJK_MAX_VALUE_OF(scalar_type);
                    SGJK_DEFAULT_CONTAINER<single_t_pair<SGJK_SIZE_TYPE>> uniqueEdges;

                    for (SGJK_SIZE_TYPE i = 0; i < normals.size(); ++i) {
                        if (SGJK_DOT(normals[i].first, supportPoint) > (scalar_type)0) {
                            SGJK_SIZE_TYPE f = i * 3;

                            addEndgeIfUnique(uniqueEdges, faces, f, f + 1);
                            addEndgeIfUnique(uniqueEdges, faces, f + 1, f + 2);
                            addEndgeIfUnique(uniqueEdges, faces, f + 2, f);

                            faces[f + 2] = faces.back(); faces.pop_back();
                            faces[f + 1] = faces.back(); faces.pop_back();
                            faces[f] = faces.back(); faces.pop_back();

                            normals[i] = normals.back(); normals.pop_back();

                            --i;
                        }
                    }
                    SGJK_DEFAULT_CONTAINER<SGJK_SIZE_TYPE> newFaces;
                    for (auto i : uniqueEdges) {
                        SGJK_SIZE_TYPE edgeIndex1 = i.first;
                        SGJK_SIZE_TYPE edgeIndex2 = i.second;
                        newFaces.push_back(edgeIndex1);
                        newFaces.push_back(edgeIndex2);
                        newFaces.push_back(polytope.size());
                    }

                    polytope.push_back(supportPoint);

                    auto normalData = getFaceNormals(polytope, newFaces);
                    auto& newNormals = normalData.first;
                    auto newMinFace = normalData.second;
                    scalar_type oldMinDistance = SGJK_MAX_VALUE_OF(scalar_type);
                    for (SGJK_SIZE_TYPE i = 0; i < normals.size(); i++) {
                        if (normals[i].second < oldMinDistance) {
                            oldMinDistance = normals[i].second;
                            minFace = i;
                        }
                    }

                    if (newNormals[newMinFace].second < oldMinDistance) {
                        minFace = newMinFace + normals.size();
                    }

                    faces.insert(faces.end(), newFaces.begin(), newFaces.end());
                    normals.insert(normals.end(), newNormals.begin(), newNormals.end());
                }
            }
            if (minDistance == SGJK_MAX_VALUE_OF(scalar_type))
                minDistance = normals[minFace].second;

            return minNormal * (minDistance + toleranceDistance);
        }

        [[nodiscard]] SGJK_SIZE_TYPE get_iteration_count() const noexcept {
            return iteration_ + 1;
        }
        [[nodiscard]] const math_vector_type* get_simplex_data() const noexcept {
            return simplex_;
        }
    };
    typedef collision_detecter_3dt<SGJK_DEFAULT_VEC3D> collision_detecter_3d;
};

#endif // ifndef SGJK_HEAD_HPP_
