serenity_component(
    Magnifier
    RECOMMENDED
    TARGETS Magnifier
)

set(SOURCES
    MagnifierWidget.cpp
    main.cpp
)

serenity_app(Magnifier ICON app-magnifier)
target_link_libraries(Magnifier PRIVATE LibCore LibGfx LibGUI LibIPC LibMain LibFileSystemAccessClient)
