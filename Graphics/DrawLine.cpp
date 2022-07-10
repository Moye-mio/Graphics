#include "pch.h"
#include "DrawLine.h"

using namespace Graphics;

std::optional<std::vector<Eigen::Vector2i>> IDrawLine::drawLine(const Eigen::Vector2f& vP1, const Eigen::Vector2f& vP2)
{
	_ASSERTE(!std::isnan(vP1.x() + vP1.y() + vP2.x() + vP2.y()));

	std::vector<Eigen::Vector2i> DrawnPixels;

	try
	{
		int r = __drawLineV(vP1, vP2, DrawnPixels);
		if (r == 0)
		{
			hiveEventLogger::hiveOutputEvent("Draw Line Failed...");
			return std::nullopt;
		}
		else
		{
			hiveEventLogger::hiveOutputEvent("Draw Line Succeed!");
			return DrawnPixels;
		}
	}
	catch (...)
	{
		hiveEventLogger::hiveOutputEvent("Draw Line Throws exception...");
		return std::nullopt;
	}

}
