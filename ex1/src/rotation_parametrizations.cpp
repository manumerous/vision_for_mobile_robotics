/**
 * @file rotation_parametrizations.cpp
 *
 * @brief functions concerning the transformation between different rotation parametrizations. 
 *
 * @author Manuel Galliker
 * Contact: manuel.galliker@gmx.ch
 *
 */

#include <eigen3/Eigen/Dense>
#include <math.h>

#define _USE_MATH_DEFINES

Eigen::Matrix3d angleAxisToRotMat(Eigen::Vector3d angle_axis_vec)
{
    float theta = angle_axis_vec.norm();
    Eigen::Vector3d k = angle_axis_vec / theta;
    Eigen::Matrix3d k_skew_mat;
    k_skew_mat << 0, -k[2], k[1],
        k[2], 0, -k[0],
        -k[1], k[0], 0;

    Eigen::Matrix3d rot_mat = Eigen::Matrix3d::Identity() + sin(theta) * k_skew_mat + (1 - cos(theta)) * k_skew_mat * k_skew_mat;
    return rot_mat;
}