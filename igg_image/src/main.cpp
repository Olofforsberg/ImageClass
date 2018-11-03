#include <image.h>
#include <iostream>



int main()
{
	/* code */
	igg::Image test_img(25,25);
	test_img.at(10,10,8);
	std::cout << test_img.at(10,10) << std::endl;
	std::cout << "cols " << test_img.cols() << std::endl;
	std::cout << "rows " << test_img.rows() << std::endl;


	return 0;
}