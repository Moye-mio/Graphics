#pragma once
#include "DrawLine.h"

namespace Graphics
{
	class CBresenhamDrawLine : public IDrawLine
	{

	private:
		int __drawLineV(const Eigen::Vector2f& vP1, const Eigen::Vector2f& vP2, std::vector<Eigen::Vector2i>& voDrawnPixels) override;
	};
}