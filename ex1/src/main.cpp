/**
 * @file main.cpp
 *
 * @brief main file for vision algorithms for mobile robot class exercise 1. 
 *
 * @author Manuel Galliker
 * Contact: manuel.galliker@gmx.ch
 *
 */

// Libraries
#include <SFML/Graphics.hpp>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Cholesky>
#include <opencv2/opencv.hpp>

// Standart Libraries
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// Local Files
#include "utils.cpp"
#include "file_manager.cpp"
#include "rotation_parametrizations.cpp"

Eigen::Matrix4d tranformMatFromPoseVec(Eigen::VectorXd pose_vec)
{
    Eigen::Vector3d angle_axis_vec(pose_vec.head(3));
    Eigen::Vector3d translation_vec(pose_vec.tail(3));
    Eigen::Matrix3d R = angleAxisToRotMat(angle_axis_vec);
    Eigen::Matrix4d T;
    T << R, translation_vec,
        0, 0, 0, 1;
    return T;
}

int main(int argc, char **argv)
{
    std::string base_path("/home/manu/Documents/github/vision_for_mobile_robotics/ex1");
    std::cout << "application base path: " << base_path << "\n";

    std::string current_cpp_version(getCPP_Version());
    std::cout << "current C++ version: " << current_cpp_version << "\n";

    std::string k_mat_filename = "/data/K.txt";
    Eigen::MatrixXd K = getMatrixFromTXT((base_path + k_mat_filename).c_str());
    // std::cout << "K = " << K << "\n";

    std::string d_mat_filename = "/data/D.txt";
    Eigen::MatrixXd D = getMatrixFromTXT((base_path + d_mat_filename).c_str());
    // std::cout << "D = " << D << "\n";

    std::string poses_mat_filename = "/data/poses.txt";
    Eigen::MatrixXd poses = getMatrixFromTXT((base_path + poses_mat_filename).c_str());
    // std::cout << "poses = " << poses << "\n";

    // Eigen::Vector3d angle_axis_1(poses(0, 0), poses(0, 1), poses(0, 2));
    // // Eigen::Vector3d angle_axis_test(0, M_PI / 2, 0);
    // // std::cout << "poses = " << angle_axis_test << "\n";
    // Eigen::Matrix3d rot_mat_1 = angleAxisToRotMat(angle_axis_1);
    // std::cout << "rot_mat_1 = " << rot_mat_1 << "\n";

    // for (i = 0; i < 5; i++)
    // {
    //     Eigen::VectorXd pose_vec_test = poses.row(0);
    //     Eigen::Matrix4d T = tranformMatFromPoseVec(pose_vec_test);
    //     std::cout << T << "\n";
    // }

    Eigen::VectorXd pose_vec_test = poses.row(0);
    std::cout << "pose_vec_test = " << pose_vec_test << "\n";
    Eigen::Matrix4d T = tranformMatFromPoseVec(pose_vec_test);
    std::cout << T << "\n";

    std::string first_image_path = "../data/images_undistorted/img_0001.jpg";
    // std::string first_image_path = "bouncer.jpeg";
    cv::Mat img1 = loadImage(first_image_path);
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", img1);
    cv::waitKey(0);

        return 0;
}