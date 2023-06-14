#ifndef COLOR_TRANSFER_HPP_16_05_2023
#define COLOR_TRANSFER_HPP_16_05_2023
#endif 

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <filesystem>

typedef cv::Point3_<float> Pixel;

/*! 
  \defgroup color_transfer Реализация алгоритма color transfer.
	\brief Библиотека содержит два варианта реалиации алгоритма: с логом работы и тихий. 
*/


void ColorTransfer(const cv::Mat& source, const cv::Mat& target, cv::Mat& result);
void VerboseColorTransfer(const cv::Mat& source, const cv::Mat& target, const std::string& path_to_folder);