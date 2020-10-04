#pragma once

// Common blendmodes used across multiple systems
enum BLENDMODE
{
	BLENDMODE_OPAQUE,
	BLENDMODE_ALPHA,
	BLENDMODE_PREMULTIPLIED,
	BLENDMODE_ADDITIVE,
	BLENDMODE_COUNT
};

// Do not alter order or value because it is bound to lua manually!
enum RENDERTYPE
{
	RENDERTYPE_VOID			= 0,
	RENDERTYPE_OPAQUE		= 1,
	RENDERTYPE_TRANSPARENT	= 2,
	RENDERTYPE_WATER		= 4,
	RENDERTYPE_ALL = RENDERTYPE_OPAQUE | RENDERTYPE_TRANSPARENT | RENDERTYPE_WATER
};

enum RENDERPASS
{
	RENDERPASS_TEXTURE,
	RENDERPASS_DEFERRED,
	RENDERPASS_FORWARD,
	RENDERPASS_TILEDFORWARD,
	RENDERPASS_DEPTHONLY,
	RENDERPASS_ENVMAPCAPTURE,
	RENDERPASS_SHADOW,
	RENDERPASS_SHADOWCUBE, 
	RENDERPASS_VOXELIZE,
	RENDERPASS_COUNT
};

// There are two different kinds of stencil refs:
//	ENGINE	: managed by the engine systems (STENCILREF enum values between 0-15)
//	USER	: managed by the user (raw numbers between 0-15)
enum STENCILREF_MASK
{
	STENCILREF_MASK_ENGINE = 0x0F,
	STENCILREF_MASK_USER = 0xF0,
	STENCILREF_MASK_ALL = STENCILREF_MASK_ENGINE | STENCILREF_MASK_USER,
};

// engine stencil reference values. These can be in range of [0, 15].
// Do not alter order or value because it is bound to lua manually!
enum STENCILREF 
{
	STENCILREF_EMPTY = 0,
	STENCILREF_SKY = 1,
	STENCILREF_DEFAULT = 2,
	STENCILREF_SKIN = 3,
	STENCILREF_LAST = 15
};

// constant buffers
enum CBTYPES
{
	CBTYPE_FRAME,
	CBTYPE_CAMERA,
	CBTYPE_MISC,
	CBTYPE_VOLUMELIGHT,
	CBTYPE_DECAL,
	CBTYPE_CUBEMAPRENDER,
	CBTYPE_API,
	CBTYPE_TESSELLATION,
	CBTYPE_DISPATCHPARAMS,
	CBTYPE_RAYTRACE,
	CBTYPE_MIPGEN,
	CBTYPE_FILTERENVMAP,
	CBTYPE_COPYTEXTURE,
	CBTYPE_FORWARDENTITYMASK,
	CBTYPE_POSTPROCESS,
	CBTYPE_POSTPROCESS_MSAO,
	CBTYPE_POSTPROCESS_MSAO_UPSAMPLE,
	CBTYPE_LENSFLARE,
	CBTYPE_PAINTRADIUS,
	CBTYPE_SHADINGRATECLASSIFICATION,
	CBTYPE_COUNT
};

// resource buffers (StructuredBuffer, Buffer, etc.)
enum RBTYPES
{
	RBTYPE_ENTITYARRAY,
	RBTYPE_ENTITYTILES_OPAQUE,
	RBTYPE_ENTITYTILES_TRANSPARENT,
	RBTYPE_VOXELSCENE,
	RBTYPE_MATRIXARRAY,
	RBTYPE_COUNT
};

// textures
enum TEXTYPES
{
	TEXTYPE_2D_DEBUGUAV,
	TEXTYPE_3D_VOXELRADIANCE,
	TEXTYPE_3D_VOXELRADIANCE_HELPER,
	TEXTYPE_2D_IMPOSTORARRAY,
	TEXTYPE_CUBEARRAY_ENVMAPARRAY,
	TEXTYPE_COUNT
};

// vertex shaders
enum VSTYPES
{
	VSTYPE_OBJECT_DEBUG,
	VSTYPE_OBJECT_COMMON,
	VSTYPE_OBJECT_SIMPLE,
	VSTYPE_OBJECT_POSITIONSTREAM,
	VSTYPE_OBJECT_COMMON_TESSELLATION,
	VSTYPE_OBJECT_SIMPLE_TESSELLATION,
	VSTYPE_SHADOW,
	VSTYPE_SHADOW_ALPHATEST,
	VSTYPE_SHADOW_TRANSPARENT,
	VSTYPE_SHADOWCUBEMAPRENDER,
	VSTYPE_SHADOWCUBEMAPRENDER_ALPHATEST,
	VSTYPE_IMPOSTOR,
	VSTYPE_VERTEXCOLOR,
	VSTYPE_TRAIL,
	VSTYPE_DIRLIGHT,
	VSTYPE_POINTLIGHT,
	VSTYPE_SPOTLIGHT,
	VSTYPE_LIGHTVISUALIZER_SPOTLIGHT,
	VSTYPE_LIGHTVISUALIZER_POINTLIGHT,
	VSTYPE_LIGHTVISUALIZER_SPHERELIGHT,
	VSTYPE_LIGHTVISUALIZER_DISCLIGHT,
	VSTYPE_LIGHTVISUALIZER_RECTANGLELIGHT,
	VSTYPE_LIGHTVISUALIZER_TUBELIGHT,
	VSTYPE_SKY,
	VSTYPE_DECAL,
	VSTYPE_ENVMAP,
	VSTYPE_ENVMAP_SKY,
	VSTYPE_SPHERE,
	VSTYPE_CUBE,
	VSTYPE_VOXELIZER,
	VSTYPE_VOXEL,
	VSTYPE_FORCEFIELDVISUALIZER_POINT,
	VSTYPE_FORCEFIELDVISUALIZER_PLANE,
	VSTYPE_RENDERLIGHTMAP,
	VSTYPE_RAYTRACE_SCREEN,
	VSTYPE_SCREEN,
	VSTYPE_LENSFLARE,
	VSTYPE_COUNT
};
// pixel shaders
enum PSTYPES
{
	PSTYPE_OBJECT_DEFERRED,
	PSTYPE_OBJECT_DEFERRED_NORMALMAP,
	PSTYPE_OBJECT_DEFERRED_POM,
	PSTYPE_OBJECT_DEFERRED_PLANARREFLECTION,
	PSTYPE_OBJECT_DEFERRED_NORMALMAP_POM,
	PSTYPE_OBJECT_DEFERRED_NORMALMAP_PLANARREFLECTION,
	PSTYPE_OBJECT_DEFERRED_TERRAIN,
	PSTYPE_IMPOSTOR_DEFERRED,

	PSTYPE_OBJECT_FORWARD,
	PSTYPE_OBJECT_FORWARD_NORMALMAP,
	PSTYPE_OBJECT_FORWARD_TRANSPARENT,
	PSTYPE_OBJECT_FORWARD_TRANSPARENT_NORMALMAP,
	PSTYPE_OBJECT_FORWARD_PLANARREFLECTION,
	PSTYPE_OBJECT_FORWARD_NORMALMAP_PLANARREFLECTION,
	PSTYPE_OBJECT_FORWARD_TRANSPARENT_PLANARREFLECTION,
	PSTYPE_OBJECT_FORWARD_TRANSPARENT_NORMALMAP_PLANARREFLECTION,
	PSTYPE_OBJECT_FORWARD_POM,
	PSTYPE_OBJECT_FORWARD_NORMALMAP_POM,
	PSTYPE_OBJECT_FORWARD_TRANSPARENT_POM,
	PSTYPE_OBJECT_FORWARD_TRANSPARENT_NORMALMAP_POM,
	PSTYPE_OBJECT_FORWARD_WATER,
	PSTYPE_OBJECT_FORWARD_TERRAIN,
	PSTYPE_IMPOSTOR_FORWARD,

	PSTYPE_OBJECT_TILEDFORWARD,
	PSTYPE_OBJECT_TILEDFORWARD_NORMALMAP,
	PSTYPE_OBJECT_TILEDFORWARD_TRANSPARENT,
	PSTYPE_OBJECT_TILEDFORWARD_TRANSPARENT_NORMALMAP,
	PSTYPE_OBJECT_TILEDFORWARD_PLANARREFLECTION,
	PSTYPE_OBJECT_TILEDFORWARD_NORMALMAP_PLANARREFLECTION,
	PSTYPE_OBJECT_TILEDFORWARD_TRANSPARENT_PLANARREFLECTION,
	PSTYPE_OBJECT_TILEDFORWARD_TRANSPARENT_NORMALMAP_PLANARREFLECTION,
	PSTYPE_OBJECT_TILEDFORWARD_POM,
	PSTYPE_OBJECT_TILEDFORWARD_NORMALMAP_POM,
	PSTYPE_OBJECT_TILEDFORWARD_TRANSPARENT_POM,
	PSTYPE_OBJECT_TILEDFORWARD_TRANSPARENT_NORMALMAP_POM,
	PSTYPE_OBJECT_TILEDFORWARD_WATER,
	PSTYPE_OBJECT_TILEDFORWARD_TERRAIN,
	PSTYPE_IMPOSTOR_TILEDFORWARD,

	PSTYPE_OBJECT_HOLOGRAM,

	PSTYPE_OBJECT_DEBUG,
	PSTYPE_OBJECT_PAINTRADIUS,
	PSTYPE_OBJECT_SIMPLEST,
	PSTYPE_OBJECT_BLACKOUT,
	PSTYPE_OBJECT_TEXTUREONLY,
	PSTYPE_OBJECT_ALPHATESTONLY,
	PSTYPE_IMPOSTOR_ALPHATESTONLY,
	PSTYPE_IMPOSTOR_SIMPLE,
	PSTYPE_IMPOSTOR_WIRE,

	PSTYPE_SHADOW_ALPHATEST,
	PSTYPE_SHADOW_TRANSPARENT,
	PSTYPE_SHADOW_WATER,

	PSTYPE_VERTEXCOLOR,
	PSTYPE_TRAIL,
	PSTYPE_ENVIRONMENTALLIGHT,
	PSTYPE_DIRLIGHT,
	PSTYPE_POINTLIGHT,
	PSTYPE_SPOTLIGHT,
	PSTYPE_SPHERELIGHT,
	PSTYPE_DISCLIGHT,
	PSTYPE_RECTANGLELIGHT,
	PSTYPE_TUBELIGHT,
	PSTYPE_LIGHTVISUALIZER,
	PSTYPE_VOLUMETRICLIGHT_DIRECTIONAL,
	PSTYPE_VOLUMETRICLIGHT_POINT,
	PSTYPE_VOLUMETRICLIGHT_SPOT,
	PSTYPE_DECAL,
	PSTYPE_SKY_STATIC,
	PSTYPE_SKY_DYNAMIC,
	PSTYPE_SUN,
	PSTYPE_ENVMAP,
	PSTYPE_ENVMAP_TERRAIN,
	PSTYPE_ENVMAP_SKY_STATIC,
	PSTYPE_ENVMAP_SKY_DYNAMIC,
	PSTYPE_CUBEMAP,
	PSTYPE_CAPTUREIMPOSTOR_ALBEDO,
	PSTYPE_CAPTUREIMPOSTOR_NORMAL,
	PSTYPE_CAPTUREIMPOSTOR_SURFACE,
	PSTYPE_VOXELIZER,
	PSTYPE_VOXELIZER_TERRAIN,
	PSTYPE_VOXEL,
	PSTYPE_FORCEFIELDVISUALIZER,
	PSTYPE_RENDERLIGHTMAP,
	PSTYPE_RAYTRACE_DEBUGBVH,
	PSTYPE_DOWNSAMPLEDEPTHBUFFER,
	PSTYPE_DEFERREDCOMPOSITION,
	PSTYPE_POSTPROCESS_SSS,
	PSTYPE_POSTPROCESS_UPSAMPLE_BILATERAL,
	PSTYPE_POSTPROCESS_OUTLINE,
	PSTYPE_LENSFLARE,
	PSTYPE_COUNT
};
// geometry shaders
enum GSTYPES
{
	GSTYPE_VOXELIZER,
	GSTYPE_VOXEL,
	GSTYPE_LENSFLARE,
	GSTYPE_COUNT
};
// hull shaders
enum HSTYPES
{
	HSTYPE_OBJECT,
	HSTYPE_COUNT
};
// domain shaders
enum DSTYPES
{
	DSTYPE_OBJECT,
	DSTYPE_COUNT
};
// compute shaders
enum CSTYPES
{
	CSTYPE_LUMINANCE_PASS1,
	CSTYPE_LUMINANCE_PASS2,
	CSTYPE_SHADINGRATECLASSIFICATION,
	CSTYPE_SHADINGRATECLASSIFICATION_DEBUG,
	CSTYPE_TILEFRUSTUMS,
	CSTYPE_RESOLVEMSAADEPTHSTENCIL,
	CSTYPE_VOXELSCENECOPYCLEAR,
	CSTYPE_VOXELSCENECOPYCLEAR_TEMPORALSMOOTHING,
	CSTYPE_VOXELRADIANCESECONDARYBOUNCE,
	CSTYPE_VOXELCLEARONLYNORMAL,
	CSTYPE_GENERATEMIPCHAIN2D_UNORM4,
	CSTYPE_GENERATEMIPCHAIN2D_FLOAT4,
	CSTYPE_GENERATEMIPCHAIN3D_UNORM4,
	CSTYPE_GENERATEMIPCHAIN3D_FLOAT4,
	CSTYPE_GENERATEMIPCHAINCUBE_UNORM4,
	CSTYPE_GENERATEMIPCHAINCUBE_FLOAT4,
	CSTYPE_GENERATEMIPCHAINCUBEARRAY_UNORM4,
	CSTYPE_GENERATEMIPCHAINCUBEARRAY_FLOAT4,
	CSTYPE_FILTERENVMAP,
	CSTYPE_COPYTEXTURE2D_UNORM4,
	CSTYPE_COPYTEXTURE2D_FLOAT4,
	CSTYPE_COPYTEXTURE2D_UNORM4_BORDEREXPAND,
	CSTYPE_COPYTEXTURE2D_FLOAT4_BORDEREXPAND,
	CSTYPE_SKINNING,
	CSTYPE_SKINNING_LDS,
	CSTYPE_RAYTRACE_LAUNCH,
	CSTYPE_RAYTRACE_KICKJOBS,
	CSTYPE_RAYTRACE_CLOSESTHIT,
	CSTYPE_RAYTRACE_SHADE,
	CSTYPE_RAYTRACE_TILESORT,
	CSTYPE_PAINT_TEXTURE,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_FLOAT1,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_FLOAT3,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_FLOAT4,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_UNORM1,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_UNORM4,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_WIDE_FLOAT1,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_WIDE_FLOAT3,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_WIDE_FLOAT4,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_WIDE_UNORM1,
	CSTYPE_POSTPROCESS_BLUR_GAUSSIAN_WIDE_UNORM4,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_FLOAT1,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_FLOAT3,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_FLOAT4,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_UNORM1,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_UNORM4,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_WIDE_FLOAT1,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_WIDE_FLOAT3,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_WIDE_FLOAT4,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_WIDE_UNORM1,
	CSTYPE_POSTPROCESS_BLUR_BILATERAL_WIDE_UNORM4,
	CSTYPE_POSTPROCESS_SSAO,
	CSTYPE_POSTPROCESS_HBAO,
	CSTYPE_POSTPROCESS_MSAO_PREPAREDEPTHBUFFERS1,
	CSTYPE_POSTPROCESS_MSAO_PREPAREDEPTHBUFFERS2,
	CSTYPE_POSTPROCESS_MSAO_INTERLEAVE,
	CSTYPE_POSTPROCESS_MSAO,
	CSTYPE_POSTPROCESS_MSAO_BLURUPSAMPLE,
	CSTYPE_POSTPROCESS_MSAO_BLURUPSAMPLE_BLENDOUT,
	CSTYPE_POSTPROCESS_MSAO_BLURUPSAMPLE_PREMIN,
	CSTYPE_POSTPROCESS_MSAO_BLURUPSAMPLE_PREMIN_BLENDOUT,
	CSTYPE_POSTPROCESS_SSR_RAYTRACE,
	CSTYPE_POSTPROCESS_SSR_RESOLVE,
	CSTYPE_POSTPROCESS_SSR_TEMPORAL,
	CSTYPE_POSTPROCESS_SSR_MEDIAN,
	CSTYPE_POSTPROCESS_RTAO_DENOISE_TEMPORAL,
	CSTYPE_POSTPROCESS_RTAO_DENOISE_BLUR,
	CSTYPE_POSTPROCESS_LIGHTSHAFTS,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_TILEMAXCOC_HORIZONTAL,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_TILEMAXCOC_VERTICAL,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_NEIGHBORHOODMAXCOC,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_KICKJOBS,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_PREPASS,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_PREPASS_EARLYEXIT,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_MAIN,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_MAIN_EARLYEXIT,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_MAIN_CHEAP,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_POSTFILTER,
	CSTYPE_POSTPROCESS_DEPTHOFFIELD_UPSAMPLE,
	CSTYPE_POSTPROCESS_MOTIONBLUR_TILEMAXVELOCITY_HORIZONTAL,
	CSTYPE_POSTPROCESS_MOTIONBLUR_TILEMAXVELOCITY_VERTICAL,
	CSTYPE_POSTPROCESS_MOTIONBLUR_NEIGHBORHOODMAXVELOCITY,
	CSTYPE_POSTPROCESS_MOTIONBLUR_KICKJOBS,
	CSTYPE_POSTPROCESS_MOTIONBLUR,
	CSTYPE_POSTPROCESS_MOTIONBLUR_EARLYEXIT,
	CSTYPE_POSTPROCESS_MOTIONBLUR_CHEAP,
	CSTYPE_POSTPROCESS_BLOOMSEPARATE,
	CSTYPE_POSTPROCESS_BLOOMCOMBINE,
	CSTYPE_POSTPROCESS_VOLUMETRICCLOUDS_SHAPENOISE,
	CSTYPE_POSTPROCESS_VOLUMETRICCLOUDS_DETAILNOISE,
	CSTYPE_POSTPROCESS_VOLUMETRICCLOUDS_CURLNOISE,
	CSTYPE_POSTPROCESS_VOLUMETRICCLOUDS_WEATHERMAP,
	CSTYPE_POSTPROCESS_VOLUMETRICCLOUDS_RENDER,
	CSTYPE_POSTPROCESS_VOLUMETRICCLOUDS_REPROJECT,
	CSTYPE_POSTPROCESS_VOLUMETRICCLOUDS_FINAL,
	CSTYPE_POSTPROCESS_FXAA,
	CSTYPE_POSTPROCESS_TEMPORALAA,
	CSTYPE_POSTPROCESS_LINEARDEPTH,
	CSTYPE_POSTPROCESS_SHARPEN,
	CSTYPE_POSTPROCESS_TONEMAP,
	CSTYPE_POSTPROCESS_CHROMATIC_ABERRATION,
	CSTYPE_POSTPROCESS_UPSAMPLE_BILATERAL_FLOAT1,
	CSTYPE_POSTPROCESS_UPSAMPLE_BILATERAL_UNORM1,
	CSTYPE_POSTPROCESS_UPSAMPLE_BILATERAL_FLOAT4,
	CSTYPE_POSTPROCESS_UPSAMPLE_BILATERAL_UNORM4,
	CSTYPE_POSTPROCESS_DOWNSAMPLE4X,
	CSTYPE_POSTPROCESS_NORMALSFROMDEPTH,
	CSTYPE_COUNT
};
// raytracing shaders
enum RTTYPES
{
	RTTYPE_RTAO,
	RTTYPE_RTREFLECTION,
	RTTYPE_COUNT
};

// input layouts
enum ILTYPES
{
	ILTYPE_OBJECT_DEBUG,
	ILTYPE_OBJECT_POS,
	ILTYPE_OBJECT_POS_TEX,
	ILTYPE_OBJECT_ALL,
	ILTYPE_SHADOW_POS,
	ILTYPE_SHADOW_POS_TEX,
	ILTYPE_RENDERLIGHTMAP,
	ILTYPE_VERTEXCOLOR,
	ILTYPE_TRAIL,
	ILTYPE_COUNT
};
// rasterizer states
enum RSTYPES
{
	RSTYPE_FRONT,
	RSTYPE_BACK,
	RSTYPE_DOUBLESIDED,
	RSTYPE_WIRE,
	RSTYPE_WIRE_SMOOTH,
	RSTYPE_WIRE_DOUBLESIDED,
	RSTYPE_WIRE_DOUBLESIDED_SMOOTH,
	RSTYPE_SHADOW,
	RSTYPE_SHADOW_DOUBLESIDED,
	RSTYPE_OCCLUDEE, 
	RSTYPE_VOXELIZE,
	RSTYPE_SKY,
	RSTYPE_COUNT
};
// depth-stencil states
enum DSSTYPES
{
	DSSTYPE_DEFAULT,
	DSSTYPE_SHADOW,
	DSSTYPE_XRAY,
	DSSTYPE_DEPTHREAD,
	DSSTYPE_DEFERREDLIGHT,
	DSSTYPE_DEPTHREADEQUAL,
	DSSTYPE_ENVMAP,
	DSSTYPE_CAPTUREIMPOSTOR,
	DSSTYPE_WRITEONLY,
	DSSTYPE_DEFERREDCOMPOSITION,
	DSSTYPE_SSS,
	DSSTYPE_COUNT
};
// blend states
enum BSTYPES
{
	BSTYPE_OPAQUE,
	BSTYPE_TRANSPARENT,
	BSTYPE_INVERSE,
	BSTYPE_ADDITIVE,
	BSTYPE_PREMULTIPLIED,
	BSTYPE_COLORWRITEDISABLE,
	BSTYPE_DEFERREDLIGHT,
	BSTYPE_ENVIRONMENTALLIGHT,
	BSTYPE_DECAL,
	BSTYPE_MULTIPLY,
	BSTYPE_TRANSPARENTSHADOWMAP,
	BSTYPE_COUNT
};
