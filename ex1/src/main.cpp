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

std::string get_cpp_verion()
{
    std::string version;
    if (__cplusplus == 201703L)
        version = "C++17";
    else if (__cplusplus == 201402L)
        version = "C++14";
    else if (__cplusplus == 201103L)
        version = "C++11";
    else if (__cplusplus == 199711L)
        version = "C++98";
    else
        version = "pre-standard C++";

    return version;
}

int main(int argc, char **argv)
{

    std::string base_path(get_base_directory());
    std::cout << "application base path: " << base_path << "\n";

    std::string k_mat_filename = "/data/K.txt";
    std::cout << k_mat_filename << "\n";
    std::string k_mat_filepath = base_path + k_mat_filename;
    Eigen::MatrixXd K = readMatrix(k_mat_filepath.c_str());
    std::cout << K << "\n";

    // std::cout << get_cpp_verion();

    return 0;
}