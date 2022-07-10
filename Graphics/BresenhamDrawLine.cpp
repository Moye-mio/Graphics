#include "pch.h"
#include "BresenhamDrawLine.h"

using namespace Graphics;

_REGISTER_EXCLUSIVE_PRODUCT(CBresenhamDrawLine, BRESENHAM_DRAW_LINE)

int CBresenhamDrawLine::__drawLineV(const Eigen::Vector2f& vP1, const Eigen::Vector2f& vP2, std::vector<Eigen::Vector2i>& voDrawnPixels)
{
	auto x1 = vP1.x();
	auto y1 = vP1.y();
	auto x2 = vP2.x();
	auto y2 = vP2.y();
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;

	dx = x2 - x1;
	dy = y2 - y1;
	dx1 = fabs(dx);
	dy1 = fabs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;

	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		Eigen::Vector2i Point = Eigen::Vector2i(x, y);
		voDrawnPixels.emplace_back(Point);
		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			Eigen::Vector2i Point = Eigen::Vector2i(x, y);
			voDrawnPixels.emplace_back(Point);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		Eigen::Vector2i Point = Eigen::Vector2i(x, y);
		voDrawnPixels.emplace_back(Point);
		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					x = x + 1;
				}
				else
				{
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			Eigen::Vector2i Point = Eigen::Vector2i(x, y);
			voDrawnPixels.emplace_back(Point);
		}
	}

	return 1;
}
