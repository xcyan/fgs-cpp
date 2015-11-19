/*
 * gp_regression.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: zhangyuting
 */

#include <string>
#include "gp_regression.hpp"
#include "base_detector.hpp"

void cv2::fgs_gp_box_reg::Load( const std::string & model_path ) {

  return;
}

void cv2::fgs_gp_box_reg::SetDetector(cv2::fgs_base_detector & detector_) {

  return;
}

cv::Rect cv2::fgs_gp_box_reg::ProposeBox(std::vector< std::pair<cv::Rect, double> > known_boxes) {

  return cv::Rect;
}

