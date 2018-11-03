#include <gtest/gtest.h>

#include <image.h>
#include <array>
#include <iostream>

using namespace igg;

TEST(Test_initiate_class, Output_test) {
	Image test_img(12,10);
	EXPECT_EQ(12,test_img.rows());
	EXPECT_EQ(10,test_img.cols());
}

TEST(Test_image_at,Output_test) {
	const int rows  = 5;
	const int cols = 5;
	const int size = rows*cols;
	Image test_img(rows,cols);
	std::array<int, size> pixelvalue;
	for (int i = 0; i < size; ++i)
	{
		pixelvalue[i] = i;
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			test_img.at(i,j) = pixelvalue[i*cols+j];
		}
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			EXPECT_EQ(test_img.at(i,j) , pixelvalue[i*cols+j]);
		}
	}
}

TEST(Test_image_read,Output_test) {
	Image test_img;
	EXPECT_TRUE(test_img.FillFromPgm("../data/lena.ascii.pgm"));
}

TEST(Test_image_write,Output_test) {
	Image test_img;
	test_img.FillFromPgm("../data/lena.ascii.pgm");
	test_img.WriteToPgm("../data/lena.ascii2.pgm");
}

TEST(Scale_down,Output_test) {
	Image test_img;
	test_img.FillFromPgm("../data/lena.ascii.pgm");
	int cols = test_img.cols();
	int rows = test_img.rows();
	test_img.DownScale(2);
	test_img.WriteToPgm("../data/lena.ascii_downs.pgm");


	EXPECT_EQ(test_img.rows(),rows/2);
	EXPECT_EQ(test_img.cols(),cols/2);
}

TEST(Scale_Up,Output_test) {
	Image test_img;
	test_img.FillFromPgm("../data/lena.ascii.pgm");
	int cols = test_img.cols();
	int rows = test_img.rows();
	test_img.UpScale(2);
	std::cout << "write" << std::endl;
	test_img.WriteToPgm("../data/lena.ascii_ups.pgm");

	EXPECT_EQ(test_img.rows(),rows*2);
	EXPECT_EQ(test_img.cols(),cols*2);
}


TEST(Hitsogram,Output_test) {
	Image test_img;
	std::vector<float> hist;
	test_img.FillFromPgm("../data/lena.ascii.pgm");
	hist = test_img.ComputeHistogram(10);
	double hist_sum = 0.0;
	for (int i = 0; i < 9; ++i)
	{
		hist_sum += hist[i];
	}
	EXPECT_EQ(hist.size(),10);
	//std::cout << "hist_sum " << hist_sum << std::endl;
	EXPECT_GT(hist_sum,0.999f);
	EXPECT_LT(hist_sum,1.001f);
}