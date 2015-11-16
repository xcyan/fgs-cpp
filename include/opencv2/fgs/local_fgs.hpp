/*
 * local_fgs.hpp
 *
 *  Created on: Nov 15, 2015
 *      Author: zhangyuting
 */

#ifndef INCLUDE_OPENCV2_FGS_LOCAL_FGS_HPP_
#define INCLUDE_OPENCV2_FGS_LOCAL_FGS_HPP_

#include "opencv2/fgs/base_detector.hpp"

namespace cv2 {

class FGS {
public:
	typedef cv2::fgs_base_detector BaseDetector;
	void Load( const std::string& model_path );
	void SetDetector( fgs_base_detector& );
	std::pair< std::vector<cv::Rect2d>, double > Detect(
			const std::vector< std::vector< cv::Rect2d, double > >& initial_observations );

};

}


#endif /* INCLUDE_OPENCV2_FGS_LOCAL_FGS_HPP_ */
