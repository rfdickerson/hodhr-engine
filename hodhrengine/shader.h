#ifndef SHADER_H
#define SHADER_H

#include "object.h"
#include "color.h"

#include <string>
#include <map>

namespace Hodhr {

    class Shader : public Object
    {
    public:
        Shader(const std::string& source);
        ~Shader();

        bool isSupported();


        // static methods

        /**
         * @brief Finds a shader with the given name.
         *
         * Shader.find can be used to switch to another shader without having to keep a
         * reference to the shader.
         *
         * @param name is the name you can see the shader popup of any material. Common
         * names are "Diffuse", "Bumped Diffuse", "VertexLit", etc.
         *
         * @return
         */
        static Shader* Find(const std::string &name);

        static void setGlobalColor(const std::string &propertyName, Color color );

        static bool isKeywordEnabled(const std::string &keyword);

        int getUniformLocation(const std::string &name);

        void compile();

        int CompileShader(const std::string& src, GLenum shaderType);

        int Link();

        int GetProgramID() const;

        /**
         * @brief Shader LOD level for the shader.
         */
        int maximumLOD;

        /**
         * @brief Render queue of this shader.
         */
        int renderQueue;

        /**
         * @brief Program ID in hardware.
         */
        int shaderProgramID;

        int mVertexShader = -1;
        int mFragmentShader = -1;

        /**
         * @brief links hardware Uniform ids to values.
         */
        // std::map<std::string, int> uniformIDs;

        std::string mSource;



        static std::map<std::string, Color> globalColors;


    };

}

#endif // SHADER_H
