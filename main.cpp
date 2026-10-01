#include "opencv2/opencv.hpp"
#include "iostream"

int main() {
    // 读取上一层目录的 test.jpg
    cv::Mat img = cv::imread("../test.jpg");
    
    // 如果没找到图片，报错退出
    if(img.empty()) { 
        std::cout << "图片读取失败！请检查 test.jpg 是否存在\n"; 
        return -1; 
    }
    
    // 打印图片尺寸，证明 OpenCV 正常工作
    std::cout << "图片读取成功！尺寸: " << img.cols << " x " << img.rows << "\n";
    
    // 将图片另存为 output.png，证明写入功能正常
    cv::imwrite("output.png", img); 
    
    return 0;
}
