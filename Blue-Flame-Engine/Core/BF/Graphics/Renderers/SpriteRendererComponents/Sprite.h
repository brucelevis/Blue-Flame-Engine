#pragma once
#include "BF/Graphics/Renderers/SpriteRendererComponents/Renderable.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				struct BFE_API SpriteBuffer
				{
					BF::Math::Vector2f position;
					Color color;
					BF::Math::Vector2f UV;
					float renderingType;
				};

				class BFE_API Sprite : public Renderable<Sprite>
				{
					friend class SpriteRenderer;

				private:
					const BF::Graphics::API::Texture2D* texture2D;
					BF::Math::Rectangle scissorRectangle;

				public:
					Sprite(const BF::Graphics::API::Texture2D* texture2D, BF::Graphics::Renderers::RenderLayer& renderLayer);
					/*
					@pivot:
					Top left = 0, 0
					Top right = 1, 0
					Center = 0.5f, 0.5f
					Bottom right = 1, 1
					Bottom left = 0, 1
					*/
					Sprite(const BF::Graphics::API::Texture2D* texture2D, const BF::Math::Vector2f& pivot, BF::Graphics::Renderers::RenderLayer& renderLayer);
					Sprite(const BF::Graphics::API::Texture2D* texture2D, const BF::Math::Vector2f& pivot, int zSortingOrder, BF::Graphics::Renderers::RenderLayer& renderLayer);
					Sprite(const BF::Graphics::API::Texture2D* texture2D, const BF::Math::Vector2f& pivot, int zSortingOrder, BF::Graphics::Renderers::RenderLayer& renderLayer, const BF::Graphics::Color& color);
					Sprite(const BF::Graphics::API::Texture2D* texture2D, const BF::Math::Vector2f& pivot, int zSortingOrder, BF::Graphics::Renderers::RenderLayer& renderLayer, const BF::Math::Rectangle& scissorRectangle, const BF::Graphics::Color& color);
					Sprite(const BF::Graphics::API::Texture2D* texture2D, const BF::Math::Vector2f& pivot, const BF::Math::Vector2i& size, int zSortingOrder, BF::Graphics::Renderers::RenderLayer& renderLayer, const BF::Graphics::Color& color);
					Sprite(const BF::Graphics::API::Texture2D* texture2D, const BF::Math::Vector2f& pivot, const BF::Math::Vector2i& size, int zSortingOrder, BF::Graphics::Renderers::RenderLayer& renderLayer, const BF::Math::Rectangle& scissorRectangle, const BF::Graphics::Color& color);
					~Sprite();

					void SetTexture(const BF::Graphics::API::Texture2D* texture2D);
					void SetScissorRectangle(const BF::Math::Rectangle& scissorRectangle);

					inline const BF::Graphics::API::Texture2D* GetTexture() const { return texture2D; }
					inline const BF::Math::Rectangle& GetScissorRectangle() const { return scissorRectangle; }
				};
			}
		}
	}
}