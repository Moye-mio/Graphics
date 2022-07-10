#include "pch.h"
#include "MyDrawLine.h"

using namespace Graphics;

_REGISTER_EXCLUSIVE_PRODUCT(CMyDrawLine, MY_DRAW_LINE)

int Graphics::CMyDrawLine::__drawLineV(const Eigen::Vector2f& vP1, const Eigen::Vector2f& vP2, std::vector<Eigen::Vector2i>& voDrawnPixels)
{
	voDrawnPixels.clear();

	float Dx = std::fabsf(vP1.x() - vP2.x());
	float Dy = std::fabsf(vP1.y() - vP2.y());

	bool IsToReverse = (Dx >= Dy) ? false : true;
	Eigen::Vector2f Min = (Dx >= Dy) ? Eigen::Vector2f(vP1.y(), vP2.y()) : Eigen::Vector2f(vP1.x(), vP2.x());
	Eigen::Vector2f Max = (Dx < Dy) ? Eigen::Vector2f(vP1.y(), vP2.y()) : Eigen::Vector2f(vP1.x(), vP2.x());

	for (float Start = std::min(Max.x(), Max.y()); Start <= std::max(Max.x(), Max.y()); Start++)
	{
		float NextValue = (Start - std::min(Max.x(), Max.y())) * (Min.y() - Min.x()) / (Max.y() - Max.x()) + std::min(Min.x(), Min.y());
		Eigen::Vector2i NewPixel = Eigen::Vector2i((int)Start, (int)NextValue);

		if (IsToReverse)
		{
			NewPixel = Eigen::Vector2i((int)NextValue, (int)Start);
		}

		voDrawnPixels.emplace_back(NewPixel);
	}

	

	return 1;
}
