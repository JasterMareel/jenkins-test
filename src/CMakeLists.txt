add_executable(app)

target_sources(app
    PRIVATE
        example.cc
)

install(TARGETS app)
