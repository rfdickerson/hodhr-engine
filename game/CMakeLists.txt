
project(GameExample)

ADD_EXECUTABLE( GameExample main.cpp game.cpp) 

message( Compiling GameExample with ${LIBS})

target_link_libraries(GameExample ${LIBS} HodhrEngine)







