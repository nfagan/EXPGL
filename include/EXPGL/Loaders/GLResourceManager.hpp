//
//  ResourceManager.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <EXPGL/Mesh/MeshLibrary.hpp>
#include <EXPGL/Model/Model.hpp>
#include <EXPGL/Loaders/TextureLoader.hpp>
#include <EXPUtil/assert/EXP_ASSERT.h>
#include <EXPGL/Resource/GLResourcePrimitive.hpp>
#include <EXPGL/Resource/GLResourceIdentifier.hpp>
#include <typeinfo>
#include <typeindex>

namespace EXP {
    class GLResourceManager
    {
    public:
        GLResourceManager(EXP::RenderTarget *target)
        {
            this->target = target;
            texture_loader = std::make_unique<TextureLoader>();
            n_items = 0;
        }
        
        ~GLResourceManager()
        {
            for (unsigned i = 0; i < items.size(); ++i)
            {
                delete items[i];
            }
        }
        
        template<typename T, typename... A>
        T* Create(A... args)
        {
            static_assert(std::is_base_of<EXP::GLResourcePrimitive, T>::value,
                          "Template type must be derived from GLResourcePrimitive.");
            T* item = new T(args...);
            item->Initialize(target);
            GLResourceIdentifier id;
            std::string name = std::string("item__") + std::to_string(n_items);
            id.SetId(n_items);
            id.SetName(name);
            item->set_identifier(id);
            items.push_back(item);
            types.push_back(std::type_index(typeid(T)));
            indices[name] = n_items;
            n_items++;
            return item;
        }
        
        Model* CreateRectangle(void)
        {
            Mesh *mesh = Create<Mesh>();
            MeshLibrary::make_quad(mesh);
            mesh->Finalize(target);
            Material *mat = Create<Material>();
            Model *model = Create<Model>(mesh, mat);
            return model;
        }
        
        Model* CreateSphere(int vertex_count = 128)
        {
            Mesh *mesh = Create<Mesh>();
            MeshLibrary::make_sphere(mesh, vertex_count);
            mesh->Finalize(target);
            Material *mat = Create<Material>();
            Model *model = Create<Model>(mesh, mat);
            return model;
        }
        
        Model* CreateTriangle(void)
        {
            Mesh *mesh = Create<Mesh>();
            MeshLibrary::make_triangle(mesh);
            mesh->Finalize(target);
            Material *mat = Create<Material>();
            Model *model = Create<Model>(mesh, mat);
            return model;
        }
        
        void SetName(GLResourcePrimitive *resource, std::string name)
        {
            for (unsigned i = 0; i < items.size(); ++i)
            {
                if (items[i]->GetIdentifier().GetName() == name)
                {
                    throw std::runtime_error("An item with the name `" + name + "` already exists.");
                }
            }
            
            std::string current_name = resource->GetIdentifier().GetName();
            auto it = indices.find(current_name);
            //  shouldn't happen (TM)
            EXP_ASSERT(it != indices.end(), "Name `" << current_name << "` was not present???");
            unsigned index = it->second;
            indices.erase(it);
            indices[name] = index;
        }
        
        template<typename T>
        T* Get(std::string name)
        {
            auto it = indices.find(name.c_str());
            if (it == indices.end())
            {
                throw std::runtime_error("No items with the name `" + name + "` were present.");
            }
            GLResourcePrimitive *item = items[it->second];
            EXP_ASSERT(std::type_index(typeid(T)) == types[it->second],
                         "The type of the retreived item must match its original type.");
            return static_cast<T*>(item);
        }
        
        template<typename T>
        std::vector<T*> GetByTag(std::string tag)
        {
            std::vector<T*> res;
            for (unsigned i = 0; i < items.size(); ++i)
            {
                if (items[i]->GetIdentifier().GetTag() == tag)
                {
                    T* item = dynamic_cast<T*>(items[i]);
                    EXP_ASSERT(item, "The type of the retreived item must match its original type.");
                    res.push_back(item);
                }
            }
            return res;
        }
        
        template<typename T>
        T* GetTexture(const char *filename)
        {
            return texture_loader->GetTexture(filename);
        };
    private:
        void initialize(RenderTarget *target)
        {
            this->target = target;
        }
        
        RenderTarget *target = nullptr;
        std::unique_ptr<TextureLoader> texture_loader;
        std::vector<GLResourcePrimitive*> items;
        std::vector<std::type_index> types;
        std::unordered_map<std::string, unsigned int> indices;
        unsigned n_items;
    };
}

#endif /* ResourceManager_hpp */
