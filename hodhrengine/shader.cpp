#include "shader.hpp"
#include "color.hpp"
#include "debug.hpp"

#include <string>
#include <map>

using namespace Hodhr;

// static variable
std::map<std::string, Shader*> shaders;

std::map<std::string, Color> Shader::globalColors;

Shader::Shader(const std::string& source)
    : mSource(source)
{

}

Shader::~Shader()
{
    glDeleteShader(mFragmentShader);
    glDeleteShader(mVertexShader);

    glDeleteProgram(shaderProgramID);


    Debug::log("Shader", "Deleting the shader");


}

Shader* Shader::Find(const std::string &name)
{
    return shaders[name];
}

void Shader::setGlobalColor(const std::string &propertyName, Color color )
{
    globalColors[propertyName] = color;
}

bool Shader::isKeywordEnabled(const std::string &keyword)
{
    return true;
}

void Shader::compile()
{

    // parse the file for separate shaders

    std::size_t vertexsection = mSource.find("//vertex");
    std::size_t fragsection = mSource.find("//fragment");

    std::string str1 = mSource.substr(0,vertexsection);
    std::string str2 = mSource.substr(vertexsection,fragsection);
    std::string str3 = mSource.substr(fragsection);

    mVertexShader = CompileShader(str2, GL_VERTEX_SHADER);
    mFragmentShader = CompileShader(str3, GL_FRAGMENT_SHADER);

    shaderProgramID = Link();

    int i = str1.find("\n");
    str1 = str1.substr(0,i);

    shaders[str1] = this;


}

int Shader::CompileShader(const std::string& src, GLenum shaderType)
{
    GLint result, length;
    GLint shaderID;

    const char* c_str = src.c_str();


    shaderID = glCreateShader(shaderType);

    glShaderSource( shaderID, 1, &c_str, NULL);
    glCompileShader( shaderID );

    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        char *log;

        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
        log = (char*) malloc(length);
        glGetShaderInfoLog(shaderID, length, &result, log);

         if (Debug::getInstance()) {
            Debug::getInstance()->addLog("Shader", log);
         }

        free(log);
    }

    return shaderID;
}

int Shader::Link()
{
    char logInfo[128];
    GLint result;
    GLint programID;

    programID = glCreateProgram();

    glAttachShader(programID, mVertexShader);
    glAttachShader(programID, mFragmentShader);

    glBindAttribLocation(programID, 0, "VertexPosition");
    glBindAttribLocation(programID, 1, "VertexNormal");


    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &result);

    if (result == GL_FALSE)
    {

        glGetProgramInfoLog(programID, 128, NULL, logInfo);


        Debug::log("Shader", logInfo);

    } else {

        Debug::log("Shader", "Shader successfully linked.");

    }

    return programID;
}

int Shader::GetProgramID() const
{
    return shaderProgramID;
}

/**
 * @brief Gets unique identifier for a shader property name.
 *
 * Using property identifiers is more efficient than passing strings to all material
 * property functions. For example if are calling Material.SetColor a lot, or using
 * MaterialPropertyBlock, then it is better to get the identifiers of the properties you
 * need just once.
 *
 * Each name of shader property (for example _MainTex or _Color) is assigned unique integer
 * number in Unity, that stays the same for the whole game. The numbers will not be the same
 * between different runs of the game or between machiens, so do not store them or send them over
 * network.
 *
 * @param name
 * @return
 */
int Shader::propertyToID(const std::string & name)
{

}
