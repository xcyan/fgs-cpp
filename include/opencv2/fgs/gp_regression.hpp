/*
 * gp_regression.hpp
 *
 *  Created on: Nov 15, 2015
 *      Author: zhangyuting
 */

#ifndef INCLUDE_OPENCV2_FGS_GP_REGRESSION_HPP_
#define INCLUDE_OPENCV2_FGS_GP_REGRESSION_HPP_

#include <string>
#include "base_detector.hpp"
#include "opencv2/opencv.hpp"

namespace cv2 {

// argmax z on joint probability of the existing boxes
// argmax yNp1 on conditional probability

//	kNp1: 1 x N; KN: N x N; psiNp1: 4 x N

class fgs_gp_box_reg {
protected:
	/**
	 * variables
	 */
 	struct GPmodel_dfn {
		double m0;
		cv::Mat diagSqrtLambda;
		double normCov;
		double noiseSigma2;
		cv::Mat idxbScaleEnabled;
	} GPmodel;
	cv2::fgs_base_detector& detector;

	/**
	 * private/protected functions
	 */
	//	kNp1 = sgp_kNp1( psiNp1, PsiN, GPmodel );
	cv::Mat sgp_kNp1_forward(const cv::Mat &, const cv::Mat &, const GPmodel_dfn &);
	cv::Mat sgp_kNp1_backward(const cv::Mat &, const cv::Mat &, const GPmodel_dfn &);
	//	mu   = sgp_posterior_mu( kNp1, KN, fN, GPmodel );
	double sgp_posterior_mu_forward(const cv::Mat &, const cv::Mat &, const double &, const GPmodel_dfn &);
	double sgp_posterior_mu_backward(const cv::Mat &, const cv::Mat &, const double &, const GPmodel_dfn &);
	//	s2   = sgp_posterior_s2( kNp1, KN, GPmodel );
	double sgp_posterior_s2_forward(const cv::Mat &, const cv::Mat &, const GPmodel_dfn &);
	double sgp_posterior_s2_backward(const cv::Mat &, const cv::Mat &, const GPmodel_dfn &);
	//	a    = sgp_ei( mu, s2, fN_hat );
	double sgp_ei_forward(const double &, const double &, const double &);
	double sgp_ei_backward(const double &, const double &, const double &);
	// 	KN = sgp_KN( PsiN, GPmodel );
	cv::Mat sgp_KN_forward(const cv::Mat &, const GPmodel_dfn &);
	cv::Mat sgp_KN_backward(const cv::Mat &, const GPmodel_dfn &);
	//	Cnoisy = sgp_cov(GPmodel, z, Psi1);
	cv::Mat sgp_cov_forward(const GPmodel_dfn &, const double &, const cv::Mat &);
	cv::Mat sgp_cov_backward(const GPmodel_dfn &, const double &, const cv::Mat &);
	//	a = sgp_neg_acquisition_ei(GPmodel, psiNp1, PsiN, fN, fN_hat, KN)
	double sgp_neg_acquisition_ei_forward(const GPmodel_dfn &, const cv::Mat &, const cv::Mat &, const )

public:
	void Load( const std::string& model_path );
	void SetDetector( cv2::fgs_base_detector& );
	cv::Rect ProposeBox( std::vector< std::pair<cv::Rect,double> > known_boxes );
	// function for generate new proposals
	// input: current existing boxes:  std::vector< cv::Rect2d >
	// output: list of box cv::Rect2d
};

}

#endif /* INCLUDE_OPENCV2_FGS_GP_REGRESSION_HPP_ */
