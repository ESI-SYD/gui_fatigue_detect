/*
* @File_name:  gui_fatigue_detect
* @Description: gui_fatigue_detect
* @Date:   2021-11-05 00:45:30
* @Author: ESI_SYD@Tongji
*/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

#include <dlib\opencv.h>
#include <dlib\image_io.h>
#include <dlib\gui_widgets.h>
#include <dlib\image_processing.h>
#include <dlib\image_processing\frontal_face_detector.h>
#include <dlib\image_processing\render_face_detections.h>
#include <dlib\opencv\cv_image_abstract.h>
#include <dlib\pixel.h>
#include <dlib\opencv\cv_image.h>

/*姿态估计头文件*/
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\calib3d.hpp>
#include <opencv2\imgproc\types_c.h>

using namespace std;
using namespace cv;
using namespace dlib;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_open_camera_clicked();//打开相机

    void on_pushButton_close_camera_clicked();//关闭相机

    void update_window();//显示UI界面

private:
    Ui::Widget *ui;

    QTimer *timer;
    VideoCapture cap;//利用cv::videocapture打开相机，QCamera需要频繁转换格式更加卡顿

    Mat frame;
    QImage qt_image;

    frontal_face_detector face_detector;//dlib人脸检测器
    shape_predictor pre_model_26;//26点预测器

    void show_frame(Mat &);//显示图像帧


    unsigned int blink_cnt = 0;			   //眨眼计数
    unsigned int open_mou_cnt = 0;         //张嘴计数
    unsigned int close_eye_cnt = 0;        //闭眼计数

    //眨眼过程：EAR>0.2-- - EAR<0.2-- - EAR>0.2
    float blink_EAR_before = 0.0;		//眨眼前
    float blink_EAR_now = 0.2;			//眨眼中
    float blink_EAR_after = 0.0;		//眨眼后

    //闭眼最大时长：EAR<0.2的持续时间
    unsigned int eye_close_duration = 1;  //闭眼时长
    unsigned int real_yawn = 1;  //张嘴时长 done!
    unsigned int detect_no_face_duration = 1; //未见人脸时长 done!

    //张嘴：MAR>0.5
    float MAR_THRESH = 0.5;

    //低头检测
    unsigned int nod_cnt = 0; //点头计数
    unsigned int nod_total = 0; //瞌睡点头
    int head_thresh = 8; //低头欧拉角（head）阈值

    //相机坐标系
    double K[9] = { 6.5308391993466671e+002, 0.0, 3.1950000000000000e+002, 0.0, 6.5308391993466671e+002,2.3950000000000000e+002, 0.0, 0.0, 1.0 };
    //图像中心坐标系
    double D[5] = { 7.0834633684407095e-002, 6.9140193737175351e-002, 0.0, 0.0, -1.3073460323689292e+000 };

    //像素坐标系(xy)：填写凸轮的本征和畸变系数
    Mat cam_matrix = Mat(3, 3, CV_64FC1, K);
    Mat dist_coeffs = Mat(5, 1, CV_64FC1, D);

};

#endif // WIDGET_H
