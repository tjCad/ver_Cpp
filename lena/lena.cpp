#include <opencv2/core/core.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include<opencv2/legacy/legacy.hpp>
#include <iostream>
#include<string>


using namespace cv;
using namespace std;
//int main()
//{
//    
//    Mat image;
//    image = imread("mgk3.jpg"); // Read the file
//	Mat gray;
//	cvtColor(image,gray,CV_RGB2GRAY);
//	imwrite("mk3gr.jpg",gray);
//	SiftFeatureDetector detector;
//	
//	imshow("gray",gray);
//	
//
//	waitKey(0);
//	return 0;
//}
//
void cornerHarris_demo( int, void* )
{

	Mat dst, dst_norm, dst_norm_scaled;
	dst = Mat::zeros( src.size(), CV_32FC1 );

	/// Detector parameters
	int blockSize = 2;
	int apertureSize = 3;
	double k = 0.04;

	/// Detecting corners
	cornerHarris( src_gray, dst, blockSize, apertureSize, k, BORDER_DEFAULT );

	/// Normalizing
	normalize( dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
	convertScaleAbs( dst_norm, dst_norm_scaled );

	/// Drawing a circle around corners
	for( int j = 0; j < dst_norm.rows ; j++ )
	{ for( int i = 0; i < dst_norm.cols; i++ )
	{
		if( (int) dst_norm.at<float>(j,i) > thresh )
		{
			circle( dst_norm_scaled, Point( i, j ), 5,  Scalar(0), 2, 8, 0 );
		}
	}
	}
	/// Showing the result
	namedWindow( corners_window, CV_WINDOW_AUTOSIZE );
	imshow( corners_window, dst_norm_scaled );
}

int main()
{
	Mat src=imread("graySnow.jpg");
	createTrackbar( "Threshold: ", source_window, &thresh, max_thresh, cornerHarris_demo );


	/*Mat img_2=imread("mk3gr.jpg");*/
	//imshow("1",img_1);
	/*imshow("2",img_2);*/
	/*waitKey(0);*/
	/*if(!img_1.data || !img_2.data)
	{
		cout<<"opencv error"<<endl;
		return -1;
	}
	cout<<"open right"<<endl;*/
	imshow("hello",img_1);
	waitKey(0);





	
	//第一步，用SIFT算子检测关键点

	SiftFeatureDetector detector;	//构造函数采用内部默认的
	std::vector<KeyPoint> keypoints_1,keypoints_2;//构造2个专门由点组成的点向量用来存储特征点

	detector.detect(img_1,keypoints_1);//将img_1图像中检测到的特征点存储起来放在keypoints_1中
	//detector.detect(img_2,keypoints_2);//同理

	//在图像中画出特征点
	//Mat img_keypoints_1,img_keypoints_2;
	//cout << keypoints_1.size();
	//drawKeypoints(img_1,keypoints_1,img_keypoints_1,Scalar::all(-1),DrawMatchesFlags::DEFAULT);//在内存中画出特征点
	///*drawKeypoints(img_2,keypoints_2,img_keypoints_2,Scalar::all(-1),DrawMatchesFlags::DEFAULT);*/

	//imshow("sift_keypoints_1",img_keypoints_1);//显示特征点
	/*imshow("sift_keypoints_2",img_keypoints_2);*/

	//计算特征向量
	//SiftDescriptorExtractor extractor;	//定义描述子对象

	//Mat descriptors_1, descriptors_2;//存放特征向量的矩阵

	//extractor.compute(img_1,keypoints_1,descriptors_1);//计算特征向量
	//extractor.compute(img_2,keypoints_2,descriptors_2);

	////用burte force进行匹配特征向量
	//BruteForceMatcher<L2<float>>matcher;//定义一个burte force matcher对象
	//vector<DMatch>matches;
	//matcher.match(descriptors_1,descriptors_2,matches);

	////绘制匹配线段
	//Mat img_matches;
	//drawMatches(img_1,keypoints_1,img_2,keypoints_2,matches,img_matches);//将匹配出来的结果放入内存img_matches中

	////显示匹配线段
	//imshow("sift_Matches",img_matches);//显示的标题为Matches
	waitKey(0);
	return 0;
}

