#pragma once
#ifndef __PHYSICS_PHYSICSMANAGER
#define __PHYSICS_PHYSICSMANAGER

#include "MotorEngine/MotorEngineAPI.h"
#include "Utils/Singleton.h"

#include "PhysicsEnums.h"
#include <vector>

class btDiscreteDynamicsWorld;
class btRigidBody;
class btDefaultCollisionConfiguration;
class btDbvBroadphase;
class btActionInterface;
class btCollisionShape;
class btConstrainSolver;
class btSequentialImpulseConstraintSolver;
class btDefaultMotionState;
class btDispatcher;
class btBroadphaseInterface;
class btCollisionConfiguration;
class btVector3;
class btTransform;


namespace me {
	class DebugDrawer;

	/**
	PhysicsManager manages physics using Bullet Engine.
	*/
	class __MOTORENGINE_API PhysicsManager : public Singleton<PhysicsManager>
	{
		friend Singleton<PhysicsManager>;

		PhysicsManager();

		//DynamicWorld
		btDiscreteDynamicsWorld* mDynamicsWorld;

		//Variables used to inicializate the dynamicsWorld
		btDispatcher* mDispatcher;
		btBroadphaseInterface* mBroadphaseInterface;
		btCollisionConfiguration* mCollisionConfiguration;
		btSequentialImpulseConstraintSolver* mConstraintSolver;

		DebugDrawer* mDebug;

		std::vector<btCollisionShape*>	mCollisionShapes;

	public:
		/**
		Destructor for the PhysicsManager class.
		*/
		~PhysicsManager();

		void destroyRigidBody(btRigidBody* rb);

		/**
		Initializes a default collision configuration,
		a collision dispatcher, a broadphase interface, and a dynamics world.
		*/
		void start();

		/**
		Adds a rigid body to the dynamics world. The rigid body will be subject to physical forces
		and will interact with other objects in the world.

		@param rigidBody A pointer to the btRigidBody to add to the dynamics world.
		*/
		void addRigidBody(btRigidBody* rigidBody, int group, int mask);

		/**
		Adds a vehicle to the dynamics world. The vehicle will be subject to physical forces
		and will interact with other objects in the world.

		@param vehicle A pointer to the btActionInterface that represents the vehicle.
		*/
		void addVehicle(btActionInterface* vehicle);

		/*
		Returns the Collision Shape of the rigidbody

		@param shape indicates the shape of the rigidbody (0 = sphere, 1 = box, 2 = cylinder, 3 = capsule)
		@param scale indicates the scale of transform
		@param size indicates the size of transform
		*/
		btCollisionShape* createShape(Shapes shape, const btVector3 &scale, const btVector3 &colliderScale);

		/*
		Create and add a rigidbody to the dynamic world

		@param transform is the transform of the rigidBody
		@param scale indicates the scale of transform
		@param size indicates the size of transform
		@param shape indicates the shape of the rigidbody (0 = sphere, 1 = box, 2 = cylinder, 3 = capsule)
		@param mvType the movement of the object (0 = Dynamic, 1 = Static, 2 = Kinematic)
		@param isTrigger indicates if the object is trigger or not
		@param friction friction of the objetct
		@param mass mass of the object
		@param restitution restitution of the object
		*/
		btRigidBody* createRigidBody(btTransform *transform, const btVector3 &scale, const btVector3 &colliderScale, 
			int group, int mask, Shapes shape, MovementType mvType, bool isTrigger, float friction, float &mass, float restitution);

		/**
		Simulate the physics world every. If maxSubSteps > 0, it will interpolate motion between fixedTimeStep's.
		@param timeStep deltaTime, or time since last frame
		@param maxSubsteps maximum substeps of this frame
		@param fixedTimeStep Interpolation time between substeps
		*/
		void update(const double& timeStep, int maxSubsteps = 1, const double& fixedTimeStep = 1 / 60.0);
	};

	/**
	This macro defines a compact way for using the singleton PhysicsManager, instead of
	writing PhysicsManager::instance()->method() we write physicsManager().method()
	*/
	inline PhysicsManager& physicsManager() {
		return *PhysicsManager::Instance();
	}

}

#endif