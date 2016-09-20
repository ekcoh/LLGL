/*
 * DXTypes.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_DX_TYPES_H__
#define __LLGL_DX_TYPES_H__


#include <LLGL/VertexAttribute.h>
#include <LLGL/RenderSystemFlags.h>
#include <LLGL/GraphicsPipelineFlags.h>
#include <dxgiformat.h>
#include <d3dcommon.h>


namespace LLGL
{

namespace DXTypes
{


[[noreturn]]
void MapFailed(const std::string& typeName, const std::string& dxTypeName);

[[noreturn]]
void UnmapFailed(const std::string& typeName, const std::string& dxTypeName);


DXGI_FORMAT             Map( const VertexAttribute&     attrib          );
DXGI_FORMAT             Map( const DataType             dataType        );
D3D_PRIMITIVE_TOPOLOGY  Map( const PrimitiveTopology    topology        );


} // /namespace DXTypes

} // /namespace LLGL


#endif



// ================================================================================