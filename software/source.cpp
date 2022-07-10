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


Mat src;
Mat ReadImage(string imgName) {
	Mat img = imread(imgName, IMREAD_COLOR);
	if (img.empty()) {
		cout << "No se puede leer la imagen: " << imgName << std::endl;
		system("EXIT");
	}
	return img;
}
// Se lee la imagen mediante imgName y sino no se puede leer


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


