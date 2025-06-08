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

/*Other normal math funcs*/
inline Vec operator*(float s, const Vec& v) { return v * s; }//<commutative multiplcaiton

/**
 * @brief clamps x down if it is passes either min or max
 * 
 * @param x is float being clamped
 * @param min 
 * @param max 
 * @return float which is either min, max or x
 */
inline float clamp(float x, float min, float max) {
    return x < min ? min : (x > max ? max : x);
}


/**
 * @brief Reflects a vector off a surface with a given normal.
 * 
 * This function calculates the reflection of vector `v` across a surface with normal `n`.
 * The reflection is computed using the formula: R = v - 2(v · n)n
 * 
 * @param v The incident vector that is to be reflected.
 * @param n The normal vector of the surface.
 * 
 * @return The reflected vector.
 */
inline Vec reflect(const Vec& v, const Vec& n) {
    return v - 2 * v.dot(n) * n;
}

/**
 * @brief Refracts a vector into a new medium with a given refractive index ratio.
 * 
 * This function calculates the refraction of vector `v` as it passes through a boundary between two materials.
 * It uses Snell's law to calculate the direction of the refracted vector based on the refractive index ratio `etai_over_etat`.
 * 
 * @param v The incident vector (direction of the incoming ray).
 * @param n The normal vector of the surface at the point of intersection.
 * @param etai_over_etat The ratio of the refractive indices of the two media (e.g., air to glass, water to air).
 * 
 * @return The refracted vector, representing the new direction of the ray inside the new medium.
 */
inline Vec refract(const Vec& v, const Vec& n, float etai_over_etat) {
    float cos_theta = fmin(((-1)*v).dot(n), 1.0f);
    Vec r_out_perp = etai_over_etat * (v + cos_theta * n);
    Vec r_out_parallel = -sqrt(fabs(1.0f - r_out_perp.length() * r_out_perp.length())) * n;
    return r_out_perp + r_out_parallel;
}