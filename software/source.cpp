#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;
//Se usa OpenCV para diferentes funciones de procesamiento de señales y actúa como GUI

enum ThresholdMethods {
	THRESH_MOD = 1
};


Mat src, gradiente;

Mat ReadImage(string imgName) {
	Mat img = imread(imgName, IMREAD_COLOR);
	if (img.empty()) {
		cout << "No se puede leer la imagen: " << imgName << std::endl;
		system("EXIT");
	}
	return img;
}
// Se lee la imagen mediante imgName y sino no se puede leer

// Función de detección de bordes Sobel
Mat SobelDetect(Mat gray) {
	int dx[3][3] = { {1, 0, -1},{2, 0, -2},{1, 0, -1 } };
	int dy[3][3] = { {1, 2, 1},{0, 0, 0},{-1, -2, -1} };

	Mat output = Mat(gray.rows, gray.cols, CV_8U);
	Mat kernel = Mat(3, 3, CV_8U);

	int max = -200, min = 2000;

	for (int i = 1; i < gray.rows - 2; i++) {
		for (int j = 1; j < gray.cols - 2; j++) {
			// aplicar el núcleo en las direcciones X e Y
			int sumX = 0;
			int sumY = 0;
			uchar ker;
			for (int m = -1; m <= 1; m++) {
				for (int n = -1; n <= 1; n++) {
					// obtener el valor del píxel (i,j)
					kernel.at<uchar>(m + 1, n + 1) = gray.at<uchar>(i + m, j + n);
					sumX += kernel.at<uchar>(m + 1, n + 1) * dx[m + 1][n + 1];
					sumY += kernel.at<uchar>(m + 1, n + 1) * dy[m + 1][n + 1];
				}
			}
			int sum = abs(sumX) + abs(sumY);
			//cout << sum << endl;
			output.at<uchar>(i, j) = (sum > 255) ? 255 : sum;
			//output2.at<uchar>(i, j) = kernel.at<uchar>(i, j);
		}
	}
	return output;
}

	// Detección de bordes Sobel
	sobel = Mat(src.rows, src.cols, CV_32F);
	sobel = SobelDetect(gray);
	namedWindow("Sobel Edge Detection", WINDOW_NORMAL);
	imshow("Sobel Edge Detection", sobel);
	waitKey(0);
	destroyWindow("Sobel Edge Detection");


// Función para difuminar la imagen
Mat Difuminar(Mat gradiente) {
	Mat output = Mat(gradiente.rows, gradiente.cols, CV_8U);
	for (int i = 1; i < gradiente.rows - 2; i++) {
		for (int j = 1; j < gradiente.cols - 2; j++) {
			int sum = 0;
			for (int m = -1; m <= 1; m++) {
				for (int n = -1; n <= 1; n++) {
					sum += gradiente.at<uchar>(i + m, j + n);
				}
			}
			output.at<uchar>(i, j) = sum / 9;
		}
	}
	return output;
}

// Funcion main
int main() {
	String imgName;
	cout << "Introduzca el nombre del archivo de imagen (ex. barcode.jpg): " << endl;
	cin >> imgName;
	// Se lee la imagen
	src = ReadImage(imgName);
	// Se muestra la imagen original
	namedWindow("Original Image", WINDOW_NORMAL);
	imshow("Original Image", src);
	waitKey(0);
	destroyWindow("Original Image");

	// Se muestra la imagen difuminada
	Mat difuminada = Difuminar(gradiente);
	namedWindow("Difuminada", WINDOW_NORMAL);
	imshow("Difuminada", difuminada);
	waitKey(0);
	destroyWindow("Difuminada");
	

	return 0;
}
