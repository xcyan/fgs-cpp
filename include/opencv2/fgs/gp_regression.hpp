/*
 * gp_regression.hpp
 *
 *  Created on: Nov 15, 2015
 *      Author: zhangyuting
 */

#ifndef INCLUDE_OPENCV2_FGS_GP_REGRESSION_HPP_
#define INCLUDE_OPENCV2_FGS_GP_REGRESSION_HPP_

#include <string>
#include "opencv2/fgs/gp_regression.hpp"
#include "opencv2/opencv.hpp"

namespace cv2 {

// argmax z on joint probability of the existing boxes
// argmax yNp1 on conditional probability

class fgs_gp_box_reg {
public:
	void Load( const std::string& model_path );
	void SetDetector( fgs_base_detector& );
	cv::Rect2d ProposeBox( std::vector< std::pair<cv::Rect2d,double> > known_boxes );
	// function for generate new proposals
	// input: current existing boxes:  std::vector< cv::Rect2d >
	// output: list of box cv::Rect2d
};

}

#endif /* INCLUDE_OPENCV2_FGS_GP_REGRESSION_HPP_ */
