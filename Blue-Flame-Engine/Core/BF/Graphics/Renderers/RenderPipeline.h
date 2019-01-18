#pragma once
#include <vector>
#include "BF/ECS/Component.h"
#include "BF/Graphics/Camera.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Graphics/Renderers/ForwardRenderer.h"
#include "BF/Graphics/Renderers/SkyboxRenderer.h"
#include "BF/Graphics/Renderers/PostProcessing.h"
#include "Renderer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BFE_API RenderPipeline
			{
			private:
				Camera*			 camera;
				SpriteRenderer*  spriteRenderer;
				ForwardRenderer* forwardRenderer;
				SkyboxRenderer*  skyboxRenderer;
				PostProcessing*  postProcessing;

			public:
				RenderPipeline();
				~RenderPipeline();

				void Initialize();
				void Load();
				void PostLoad();
				void Update();
				void Render();

				void AddRenderable(BF::ECS::Component* component);
				void RemoveRenderable(BF::ECS::Component* component);
			};
		}
	}
}