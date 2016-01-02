ADD_LIBRARY( HodhrEngine STATIC behavior.cpp camera.cpp color.cpp 
  commandbuffer.cpp component.cpp consoledebug.cpp debug.cpp display.cpp gameobject.cpp
  graphics.cpp light.cpp material.cpp materialpropertyblock.cpp mesh.cpp
  meshfilter.cpp meshrenderer.cpp object.cpp rect.cpp renderbuffer.cpp
  renderer.cpp rendertexture.cpp resources.cpp scene.cpp shader.cpp 
  texture.cpp texture2d.cpp transform.cpp vector3.cpp	
  )

target_link_libraries(HodhrEngine ${LIBS})
