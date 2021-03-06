#pragma once
#include <vector>
#include <string>
#include "BF/ECS/IComponent.h"
#include "BF/Graphics/Transform.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class App;
		class Scene;
	}

	namespace ECS
	{
		class BFE_API GameObject
		{
			friend class BF::Application::Scene;
			friend class BF::Graphics::Transform;

		private:
			static int globalID;
			int id;
			bool added;
			BF::Application::Scene* scene;
			GameObject* parent;
			std::vector<GameObject*> gameObjects;
			std::vector<IComponent*> components;

		public:
			bool Active;
			std::string Name;

		public:
			GameObject(const std::string& name);
			virtual ~GameObject();

			IComponent* AddComponent(IComponent* component);
			void RemoveComponent(IComponent* component);

			template <typename T>
			T* GetComponent();

		private:
			void SetParent(GameObject* parent);

		public:
			inline int GetID() const { return id; }

			inline const GameObject* GetParent() const { return parent; }

			inline BF::Graphics::Transform* GetTransform() const { return (BF::Graphics::Transform*)components[0]; }
			inline const std::vector<IComponent*>& GetComponents() const { return components; }
		};

#include "GameObject.inl"
	}
}