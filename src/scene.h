#pragma once
#include "mathUtil.h"
#include <vector>
#include <memory>
#include <mutex>

/**
 * @struct stores info about ray obj intersection
 * 
 */
struct Hit{
    Vec p; //< pooint wherere it hits
    Vec normal; //< normal surface of hit point
    float t; //< ray param at hit point
    bool frontFace = false; //<tur if ray hits front face
    std::shared_ptr<class Mats> mat; //< material pointer at hit point

    /**
     * @brief Determines the correct surface normal based on ray direction.
     * Ensures normal always opposes the incoming ray.
     * 
     * @param ray Incoming ray
     * @param outward_normal Normal pointing out from surface
     */

     void setNorm(const Ray& ray, const Vec& outNorm){
        frontFace = ray.direction.dot(outNorm) <0; ///checks if they are in different direcionts
        normal = frontFace ? outNorm: (-1) * outNorm; /// if they are in diff directions, then outNorm is good, otherwise flip outNorm
     }
};

/**
 * @class for hittable geometry
 * 
 */

 Class Hittable{

 };