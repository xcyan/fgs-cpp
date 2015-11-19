/*
 * base_detector.hpp
 *
 *  Created on: Nov 15, 2015
 *      Author: zhangyuting
 */

#ifndef INCLUDE_OPENCV2_FGS_BASE_DETECTOR_HPP_
#define INCLUDE_OPENCV2_FGS_BASE_DETECTOR_HPP_

#include <string>
#include <opencv2/opencv.hpp> // TODO: replace it with a header file for the specific model

namespace cv2 {

// Base class for detector
class fgs_base_detector {
protected:
	cv::Mat img_;
public:
	virtual void Load( const std::string& model_path ) = 0;
	void SetImage( const cv::Mat img ) { img_ = img; }
	virtual double ScoreAt( cv::Rect box ) = 0;
	virtual ~fgs_base_detector() {};
};


// Oracle detector

class fgs_oracle_detector : public fgs_base_detector {
	std::string img_path_;
public:
	// TODO: implement the member functions in the base class
	virtual void Load( const std::string& model_path ) {} // load the GT annotations for all possible images
	void SetImage( const std::string& img_path ) {
		// a.jpg
		// a.jpg.annotations
		img_path_ = img_path;
		cv::Mat img = cv::imread(img_path);
		this->fgs_base_detector::SetImage(img);
		// Load annotation ( TODO )
		// ......
	}
	virtual double ScoreAt( cv::Rect box );
	virtual ~fgs_oracle_detector() {};
};



// Visualization of the detection result


}

#endif /* INCLUDE_OPENCV2_FGS_BASE_DETECTOR_HPP_ */
