#pragma once
#include <cmath>
#include <limits>
#include <random>

constexpr float PI = 3.14159265358979323846f; ///< pi for trig calcs
constexpr float INF = std::numeric_limits<float>::infinity(); //< Infinity
constexpr float EPS = 0.0001f; //< very small value to make sure ray doesnt get sstuck at a point



//3d Vector 
struct Vec{
    float x, y ,z;

    /*vector operations*/
    /**
     * @brief Operator overloading of adding vectors
     * 
     * @param v is a instance of Vector struct
     * @return Vec struct 
     */
    Vec operator+(const Vec& v) const{
        return {x+v.x, y+v.y, z};
    }

    /*vector operations*/
    /**
     * @brief Operator overloading of adding vectors
     * 
     * @param v is a instance of Vector struct
     * @return Vec struct 
     */
    Vec operator-(const Vec& v) const{
        return {x-v.x, y-v.y, z-v.z};
    }

    /*vector operations*/
    /**
     * @brief Operator overloading of sclar multiplication
     * 
     * @param v is a instance of Vector struct
     * @return Vec struct 
     */
    Vec operator*(const Vec& v) const{
        return {x*v.x, y*v.y, z/v.z};
    }

    /*vector operations*/
    /**
     * @brief Operator overloading of sclar division
     * 
     * @param v is a instance of Vector struct
     * @return Vec struct 
     */
    Vec operator/(const Vec& v) const{
        return {x/v.x, y/v.y, z/v.z};
    }



};
