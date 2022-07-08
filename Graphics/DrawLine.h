#pragma once

namespace Graphics
{
	class IDrawLine : public hiveDesignPattern::IProduct
	{
	public:
		IDrawLine() = default;
		~IDrawLine() override = default;

		std::optional<std::vector<Eigen::Vector2i>> drawLine(const Eigen::Vector2f& vP1, const Eigen::Vector2f& vP2);

	private:
		virtual int __drawLineV(const Eigen::Vector2f& vP1, const Eigen::Vector2f& vP2, std::vector<Eigen::Vector2i>& voDrawnPixels) = 0;

	private:
	};
}