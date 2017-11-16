//
//  Vertex.hpp
//  EXPGL
//
//  Created by Nick Fagan on 11/14/17.
//  Copyright © 2017 Nick Fagan. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <array>
#include <vector>

namespace EXP {
    struct Vertex
    {
    public:
        Vertex() = default;
        ~Vertex() = default;
        
        void set_position(std::array<float, 3> in_position)
        {
            position = in_position;
            n_position = 3;
        }
        void set_uv(std::array<float, 2> in_uv)
        {
            uv = in_uv;
            n_uv = 2;
        }
        void set_normal(std::array<float, 3> in_normal)
        {
            normal = in_normal;
            n_normal = 3;
        }
        
        unsigned int size() const
        {
            return n_position + n_uv + n_normal;
        }
        
        unsigned int size_position() const
        {
            return n_position;
        }
        
        unsigned int size_uv() const
        {
            return n_uv;
        }
        unsigned int size_normal() const
        {
            return n_normal;
        }
        
        bool sizes_match(const Vertex &other)
        {
            return n_position == other.n_position && n_uv == other.n_uv && n_normal == other.n_normal;
        }
        
        std::vector<float> get_interleaved_data() const
        {
            std::vector<float> data;
            for (unsigned i = 0; i < n_position; ++i)
            {
                data.push_back(position[i]);
            }
            for (unsigned i = 0; i < n_uv; ++i)
            {
                data.push_back(uv[i]);
            }
            for (unsigned i = 0; i < n_normal; ++i)
            {
                data.push_back(normal[i]);
            }
            return data;
        }
    private:
        std::array<float, 3> position;
        std::array<float, 2> uv;
        std::array<float, 3> normal;
        
        unsigned int n_position = 0;
        unsigned int n_uv = 0;
        unsigned int n_normal = 0;
    };
}

#endif /* Vertex_hpp */
