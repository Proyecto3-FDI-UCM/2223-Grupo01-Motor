#pragma once

#ifndef __ENTITYCOMPONENT_MESHRENDERER
#define __ENTITYCOMPONENT_MESHRENDERER

#include "EntityComponent/Component.h"
#include "EntityComponent/FactoryComponent.h"
#include <string>

namespace me {
	class Transform;

	//Creates and destroys MeshRenderer components
	class FactoryMeshRenderer : public FactoryComponent {
	public:
		Component* create(Parameters& params) override;
		void destroy(Component* component) override;
	};


	/**
	The MeshRenderer class represents a visual object in 3D space and can be attached to entities.
	*/
	class __MOTORENGINE_API MeshRenderer : public Component
	{
	private:
	protected:
		//name for om() map and for entity that attached in node
		std::string mName;
		//name of .mesh file
		std::string mMeshName;
		//componenet transform of this.Entity
		Transform* mTransform;
		//static state of this.Entity 
		bool mStaticObject = false;

	public:

		/**
		Construct a new MeshRenderer component 
		*/
		MeshRenderer();
		//Destroy om() map saved mesh (ogreMesh)
		~MeshRenderer();

		/**
		Calls renderManager to create a new mesh with this name and store it
		@return false: if a mesh with that name already exist
		@return true: if succeed
		*/
		bool createMesh();

		/**
		Get info for mTransform and create ogreMesh and set the start pos
		*/
		void start() override;
		

		/**
		Update transform info to mesh(ogreMesh)
		*/
		void update(const double& dt) override;

		/**
		 Set material to mesh (ogreMesh).
		 @param materialName: name of material that is written in MaterialResource.material.
		*/
		void setMaterial(std::string materialName);
		/**
		 Set name to mesh (renderMesh in rendermanager array).
		 @param name: name for map and for entity that attached in node
		*/
		void setName(std::string name);
		/**
		 Set meshname to mesh (renderMesh in rendermanager array).
		 @param meshName: name of .mesh file
		*/
		void setMeshName(std::string meshName);

		/**
		Set it is static entity or not
		 @param stat: true if mesh is static, false if not
		*/
		void setStatic(bool stat);

		/**
		Set it is static entity or not
		*/
		std::string getName();

		//active mesh
		void activeMesh();

		//desactive mesh
		void desactiveMesh();
			
	};
}
#endif


