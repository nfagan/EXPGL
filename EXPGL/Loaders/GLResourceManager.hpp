//
//  ResourceManager.hpp
//  EXPGL
//
//  Created by Nick Fagan on 10/22/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <stdio.h>
#include "TextureLoader.hpp"
#include "../Util/EXPGL_ASSERT.hpp"
#include "../Resource/GLResourcePrimitive.hpp"
#include "../Resource/GLResourceIdentifier.hpp"
#include <typeinfo>
#include <typeindex>

namespace EXP {
    class GLResourceManager
    {
    public:
        GLResourceManager(void);
        ~GLResourceManager(void);
        
        enum GETTER_TYPES
        {
            BY_NAME,
            BY_VALUE
        };
        
        template<typename T, typename... A>
        T* Create(EXP::RenderTarget *target, A... args)
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
            types.push_back(typeid(T));
            indices[name] = n_items;
            n_items++;
            return item;
        }
        
        void SetName(GLResourcePrimitive* resource, std::string name)
        {
            for (unsigned i = 0; i < items.size(); ++i)
            {
                if (items[i]->GetIdentifier().GetName() == name)
                {
                    EXPGL_ASSERT(false, "An item with the name `" << name << "` already exists." << std::endl);
                }
            }
            
            std::string current_name = resource->GetIdentifier().GetName();
            auto it = indices.find(current_name);
            //  shouldn't happen (TM)
            EXPGL_ASSERT(it != indices.end(), "Name `" << current_name << "` was not present???");
            unsigned index = it->second;
            indices.erase(it);
            indices[name] = index;
        }
        
        template<typename T>
        T* Get(std::string name)
        {
            auto it = indices.find(name.c_str());
            EXPGL_ASSERT(it != indices.end(), "No items with the name `" << name << "` were present.");
            GLResourcePrimitive *item = items[it->second];
            EXPGL_ASSERT(typeid(T).hash_code() == types[it->second].hash_code(),
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
                    res.push_back(static_cast<T*>(items[i]));
                }
            }
            return res;
        }
        
        template<typename T>
        T* GetTexture(const char* filename)
        {
            return texture_loader->GetTexture(filename);
        };
    private:
        TextureLoader *texture_loader;
        std::vector<GLResourcePrimitive*> items;
        std::vector<std::type_index> types;
        std::unordered_map<std::string, unsigned int> indices;
        unsigned n_items;
    };
}

#endif /* ResourceManager_hpp */
