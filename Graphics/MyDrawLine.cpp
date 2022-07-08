#include "pch.h"
#include "MyDrawLine.h"

using namespace Graphics;

_REGISTER_EXCLUSIVE_PRODUCT(CMyDrawLine, MY_DRAW_LINE)

int Graphics::CMyDrawLine::__drawLineV(const Eigen::Vector2f& vP1, const Eigen::Vector2f& vP2, std::vector<Eigen::Vector2i>& voDrawnPixels)
{
	voDrawnPixels.emplace_back(Eigen::Vector2i(1, 1));
	return 1;
}
