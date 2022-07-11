#include "pch.h"

#include "DrawLine.h"

using namespace Graphics;

int main()
{
	auto* DrawLine = hiveDesignPattern::hiveGetOrCreateProduct<IDrawLine>(BRESENHAM_DRAW_LINE);
	auto r = DrawLine->drawLine(Eigen::Vector2f(0, 0), Eigen::Vector2f(200, 300));

	if (r.has_value())
	{
		std::vector<Eigen::Vector2i> Pixels = r.value();
		for (auto& e : Pixels)
			std::cout << e.x() << ", " << e.y() << std::endl;

		int Width, Height;
		Width = 700;
		Height = 700;
		std::vector<Eigen::Vector3f> Buffer;
		Buffer.resize(Width * Height, Eigen::Vector3f(0, 0, 0));
		for (auto& e : Pixels)
			Buffer[(Height - 1 - e.y()) * Height + e.x()] = Eigen::Vector3f(255, 0, 0);

		while (1)
		{
			cv::Mat ShowImage(700, 700, CV_32FC3, Buffer.data());
			ShowImage.convertTo(ShowImage, CV_8UC3, 1.0f);
			cv::imshow("image", ShowImage);
			cv::waitKey(10);
		}


	}
	else
		return -1;


	return 0;
}