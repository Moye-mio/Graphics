#include "pch.h"

#include "DrawLine.h"

using namespace Graphics;

int main()
{
	auto* DrawLine = hiveDesignPattern::hiveGetOrCreateProduct<IDrawLine>(MY_DRAW_LINE);
	auto r = DrawLine->drawLine(Eigen::Vector2f(), Eigen::Vector2f());
	
	if (r.has_value())
	{
		std::vector<Eigen::Vector2i> Pixels = r.value();
		for (auto& e : Pixels)
			std::cout << e << std::endl;
	}
	else
		return -1;
		
	return 0;
}