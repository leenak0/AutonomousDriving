#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int arc, char**argv) {
	VideoCapture cap("C:/Users/leenak0/Desktop/ConsoleApplication1/1.mp4");
	Mat frame;

	if (!cap.isOpened()) {
		cout << "no camera!" << endl;
		return -1;
	}

	int key, fr_no = 0;
	bool capture = true;
	for (;;) {
		cap >> frame;
		if (frame.empty()) {
			break;
		}
		if ((key = waitKey(30)) == 27) {
			break;
		}
		fr_no++;
		resize(frame, frame, Size(320, 240));
		Mat roi(frame, Rect(0, 120, 320, 120));
		Mat edge;
		Canny(roi, edge, 60, 120, 3);
		imshow("edge", edge);
		imshow("ROI", roi);
		imshow("test", frame);
	}
}