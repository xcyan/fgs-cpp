/*
 * gp_regression.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: zhangyuting
 */

#include <string>
#include "gp_regression.hpp"
#include "base_detector.hpp"

void fgs_gp_box_reg::Load( const std::string & model_path ) {

  return;
}

void fgs_gp_box_reg::SetDetector(fgs_base_detector & detector_) {

  return;
}

cv::Rect2d fgs_gp_box_reg::ProposeBox(std::vector< std::pair<cv::Rect2d, double>> known_boxes) {

  return;
}

