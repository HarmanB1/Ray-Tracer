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

struct Ray{
    Vec origin; //< ray origin 
    Vec direction; //< ray direction

    /**
     * @brief uses R(t) = O + tD to calculate point along ray
     * 
     * @param t float that is a point along ray
     * @return Vec struct instance of point t
     */
    Vec rayFormula(float t) const{
        return origin + (direction*t);
    }
};


/* Random numb gen(monte carlo)*/

class Random{
    private:
        /*member variables*/
        std::mt19937 gen; //< random number generator
        std::uniform_real_distribution<float> distribution;

    public:
    /**
     * @brief Construct a new Random object, and initialzies generator with random seed
     * sets distruciton from 0 to 1
     * 
     * 
     */
     Random(): gen(std::random_device{}()), distribution(0.0f, 1.0f){}

     float next(){
        return distribution(gen);
     }

     /**
      * @brief returns vector inside unit circle 
      * by generating and continoulsy checking to see if in circle
      * 
      * @return Vec struct instance 
      */
     Vec randSphereVec(){
        Vec v; 
        do{
            v = {next()*2 -1,next()*2 -1,next()*2 -1, }; ///generates in range of 0 to 1

        }while(v.dot(v)>= 1.0f);///used instead of lengthvec>1 as 
        ///this is equiavlaent to inequailty dotvec>1
     }
     


};