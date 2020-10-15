/**
 * @file file_manager.cpp
 *
 * @brief functions concerning the loading and saving of data to files. 
 *
 * @author Manuel Galliker
 * Contact: manuel.galliker@gmx.ch
 *
 */

#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <fstream>

#define MAXBUFSIZE ((int)1e6)

Eigen::MatrixXd getMatrixFromTXT(const char *filename)
{
    int cols = 0, rows = 0;
    double buff[MAXBUFSIZE];

    // Read numbers from file into buffer.
    std::ifstream current_file;
    current_file.open(filename);
    while (!current_file.eof())
    {
        std::string line;
        getline(current_file, line);

        int temp_cols = 0;
        std::stringstream stream(line);
        while (!stream.eof())
            stream >> buff[cols * rows + temp_cols++];

        if (temp_cols == 0)
            continue;

        if (cols == 0)
            cols = temp_cols;

        rows++;
    }

    current_file.close();

    rows--;

    // Populate matrix with numbers.
    Eigen::MatrixXd result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result(i, j) = buff[cols * i + j];

    return result;
};

cv::Mat loadImage(std::string image_path)
{
    // std::string image_path = samples::findFile("starry_night.jpg");
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
    }
    return img;
}