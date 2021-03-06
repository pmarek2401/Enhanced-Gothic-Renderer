#pragma once
#include "pch.h"
#include "RResource.h"



class RBaseShader : public RResource
{
public:
	RBaseShader();
	virtual ~RBaseShader();

protected:
	// Path to the shaderfile this holds
	std::string ShaderFile;

	// Vector of different #defines for the shaders
	std::vector<std::vector<std::string>> Definitions;

	// Whether this shader comes directly from memory (ShaderFile is the actual code in this case)
	bool IsFromMemory;
};

