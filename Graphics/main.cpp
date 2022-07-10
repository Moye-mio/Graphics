#include "pch.h"

#include "DrawLine.h"

using namespace Graphics;

int main()
{
	auto* DrawLine = hiveDesignPattern::hiveGetOrCreateProduct<IDrawLine>(BRESENHAM_DRAW_LINE);
	auto r = DrawLine->drawLine(Eigen::Vector2f(0, 0), Eigen::Vector2f(-2, -3));
	
	if (r.has_value())
	{
		std::vector<Eigen::Vector2i> Pixels = r.value();
		for (auto& e : Pixels)
			std::cout << e.x() << ", " << e.y() << std::endl;
	}
	else
		return -1;
		
	return 0;
}