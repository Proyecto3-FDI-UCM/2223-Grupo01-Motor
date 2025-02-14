#pragma once

#ifndef __ENTITYCOMPONENT_SCENE_MANAGER
#define __ENTITYCOMPONENT_SCENE_MANAGER

#include "MotorEngineAPI.h"
#include "Utils/Singleton.h"
#include "InfoScene.h"
#include <memory>

namespace me {
    class Scene;
    class Entity;

    /**
    SceneManager stores all existing scenes and makes one of them active 
    at will. All other scenes are inactive.
    */
    class __MOTORENGINE_API SceneManager : public Singleton<SceneManager> {
        friend Singleton<SceneManager>;

        /**
        Build the foundation of the SceneManager.
        */
        SceneManager();

    public:
        /**
        * Deletes scenes and clears entities, global and otherwise.
        */
        virtual ~SceneManager();

        /**
        Add a new Scene to the SceneManager.
        Name is assumed to be a unique identifier.
        @param String name to identify the new scene.
        */
        Scene* addScene(const SceneName& name);

        /**
        Remove an scene from the SceneManager.
        Name is assumed to be a unique identifier.
        @param String name to identify the scene to be remove.
        */
        bool removeScene(const SceneName& name);

        /**
        Get a scene from the SceneManager.
        Name is assumed to be a unique identifier.
        @param String name to identify the scene.
        */
        Scene* getScene(const SceneName& name) const;

        /**
        Get currently active scene from the SceneManager.
        */
        Scene* getActiveScene() const;

        /**
        Rename a scene. 
        Names are assumed to be unique identifiers.
        @param String oldName to be change.
        @param String newName to be set.
        */
        bool renameScene(const SceneName& oldName, const SceneName& newName);

        /**
        Set the active scene from the SceneManager.
        Name is assumed to be a unique identifier.
        @param String name to identify the scene suggested.
        */
        bool setActiveScene(const SceneName& name);

        /**
        Main loop of this manager, if there is an active scene 
        this will call the scene loop methods by the order of: 
        processNewEntities, update, lateUpdate and refresh.

        @param dt Seconds that have passed since last update.
        @param q Boolean that exits main loop when true.
        */
        void update(const double& dt, bool& q);

        /**
        Load a new scene to set as active.
        @returns True on Success.
        */
        bool loadScene();

        /**
        Deletes all scenes and clears the map of scenes.
        */
        void deleteAllScenes();

        /**
        Set the new scene to be made active.
        @param newScene Name of the new scene.
        */
        void change(std::string newScene, 
            std::list<std::string> awake = std::list<std::string>(), std::list<std::string>start = std::list<std::string>());

        /**
        Begin quitting process.
        */
        void quit();

        /**
        Get name of the new scene to be made active.
        */
        std::string getNewScene();

        bool isChanging();

        bool isQuiting();

    private:
        /*
        This function calls the active scene and passes the unordered_map with all the entities information.
        @returns true if all entitys and their components were created successfully.
        @returns false if any component failed to create.
        */
        bool pushEntities(InfoScene& entitiesMap);

        //Change scene
        bool mChange = false;

        //Quit app
        bool mQuit = false;

        std::string mNewScene;

        std::unordered_map<SceneName, Scene*> mScenes;
        Scene* mActiveScene = nullptr;

        std::list<std::string> mAwake;
        std::list<std::string> mStart;
    };

    /**
    This macro defines a compact way for using the singleton SceneManager, 
    instead of writing SceneManager::instance()->method() we write sceneManager().method()
    */
    inline SceneManager& sceneManager() {
        return *SceneManager::Instance();
    };

};

#endif