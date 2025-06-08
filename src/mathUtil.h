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
     * @return Vec struct instance 
     */
    Vec operator-(const Vec& v) const{
        return {x-v.x, y-v.y, z-v.z};
    }

    /*vector operations*/
    /**
     * @brief Operator overloading of sclar multiplication
     * 
     * @param s is a float that is being multiplied to vector
     * @return Vec struct instance containing multiplied vector
     */
    Vec operator*(float s) const{
        return {x*s, y*s, z*s};
    }

    /*vector operations*/
    /**
     * @brief Operator overloading of sclar division
     * 
     * @param s is a float that is being multiplied to vector
     * @return Vec struct instance containg divided vector
     */
    Vec operator/(float s) const{
        return {x/s, y/s, z/s};
    }

    /*other vec functions*/
    /**
     * @brief dot product of 2 vectors
     * 
     * @param v is a instance of Vector struct
     * @return float containing dot product
     */
    float dot(const Vec& v) const{
        return (x*v.x + y*v.y + z*v.z);
    }


    /**
     * @brief cross product of 2 vectors
     * 
     * @param v is a instance of Vector struct
     * @return Vec struct containg new cross producted vector
     */
    Vec cross(const Vec& v) const{
        return {y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x};
    }

   
    /**
     * @brief returns length of vector using pyathgerous theorem
     * 
     * @return float which is the length of vector
     */
    float length() const {return std::sqrt(x*x + y*y + z*z);}

    /**
     * @brief returns length of vector using pyathgerous theorem
     * 
     * @return returns Vec struct instance containing normalized vector
     */
    Vec normalized() const{
        return (*this / length());
    }









};
