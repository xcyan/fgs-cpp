/*
 * gp_regression.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: zhangyuting
 */

#include <string>
#include "gp_regression.hpp"
#include "base_detector.hpp"

typedef cv2::fgs_gp_box_reg BoxReg;
/** protected/private functions */
//	kNp1 = sgp_kNp1( psiNp1, PsiN, GPmodel );
cv::Mat BoxReg::sgp_kNp1_forward(const cv::Mat &, const cv::Mat &, const GPmodel_dfn &);
cv::Mat BoxReg::sgp_kNp1_backward(const cv::Mat &, const cv::Mat &, const GPmodel_dfn &);

//	mu   = sgp_posterior_mu( kNp1, KN, fN, GPmodel );
double BoxReg::sgp_posterior_mu_forward(const cv::Mat &, const cv::Mat &, const double &, const GPmodel_dfn &);
double BoxReg::sgp_posterior_mu_backward(const cv::Mat &, const cv::Mat &, const double &, const GPmodel_dfn &);

//	s2   = sgp_posterior_s2( kNp1, KN, GPmodel );
double BoxReg::sgp_posterior_s2_forward(const cv::Mat &, const cv::Mat &, const GPmodel_dfn &);
double BoxReg::sgp_posterior_s2_backward(const cv::Mat &, const cv::Mat &, const GPmodel_dfn &);

//	a    = sgp_ei( mu, s2, fN_hat );
double BoxReg::sgp_ei_forward(const double &, const double &, const double &);
double BoxReg::sgp_ei_backward(const double &, const double &, const double &);

// 	KN = sgp_KN( PsiN, GPmodel );
cv::Mat BoxReg::sgp_KN_forward(const cv::Mat &, const GPmodel_dfn &);
cv::Mat BoxReg::sgp_KN_backward(const cv::Mat &, const GPmodel_dfn &);

//	Cnoisy = sgp_cov(GPmodel, z, Psi1);
cv::Mat BoxReg::sgp_cov_forward(const GPmodel_dfn &, const double &, const cv::Mat &);
cv::Mat BoxReg::sgp_cov_backward(const GPmodel_dfn &, const double &, const cv::Mat &);

//	a = sgp_neg_acquisition_ei(GPmodel, psiNp1, PsiN, fN, fN_hat, KN)
double BoxReg::sgp_neg_acquisition_ei_forward(const GPmodel_dfn &, const cv::Mat &, const cv::Mat &, const double &, const double &, const cv::Mat &);
double BoxReg::sgp_neg_acquisition_ei_backward(const GPmodel_dfn &, const cv::Mat &, const cv::Mat &, const double &, const double &, const cv::Mat &);

//	ll = sgp_neglogik(GPmodel, z, Psi1, f)
double BoxReg::sgp_neglogik_forward(const GPmodel_dfn &, const double &, const cv::Mat &, const cv::Mat &);
double BoxReg::sgp_neglogik_backward(const GPmodel_dfn &, const double &, const cv::Mat &, const cv::Mat &);

//	ll = sgp_neglogik_givenC(GPmodel, C, f)
double BoxReg::sgp_neglogik_givenC_forward(const GPmodel_dfn &, const cv::Mat &, const cv::Mat &);
double BoxReg::sgp_neglogik_givenC_backward(const GPmodel_dfn &, const cv::Mat &, const cv::Mat &);


/** public functions */
void BoxReg::Load( const std::string & model_path ) {

  return;
}

void BoxReg::SetDetector(cv2::fgs_base_detector & detector_) {

  return;
}

cv::Rect BoxReg::ProposeBox(std::vector< std::pair<cv::Rect, double> > known_boxes) {

  return cv::Rect;
}

