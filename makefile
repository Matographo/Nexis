start:
	g++ -g -Isrc/libs/yaml-cpp-master/include -Isrc/main/include -Isrc/libs/spdlog/include -o build/result/Nexis src/main/cpp/main.cpp src/main/cpp/TimeCalc.cpp src/main/cpp/FileReader.cpp src/main/cpp/DataObject.cpp src/main/cpp/YamlToDataObjectParser.cpp src/main/cpp/LifecycleExecuter.cpp src/main/cpp/Implement/Utilities/NexisLoggerSpd.cpp src/main/cpp/DynamicLibraryLoader.cpp src/libs/yaml-cpp-master/src/*.cpp src/libs/yaml-cpp-master/src/contrib/*.cpp
	
plugin:
	g++  -Isrc/main/Plugins/CPP_1.0 -Isrc/main/include -Isrc/main/include/Interfaces/Lifecycles -Isrc/main/include/Interfaces/Utilities -Isrc/main/include/Interfaces -shared -fPIC -g -o build/result/cpp_1.0.so src/main/Plugins/CPP_1.0/cpp_1.0.cpp src/main/cpp/DataObject.cpp