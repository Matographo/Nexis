start:
	g++ -Isrc/main/hpp/Interfaces/Utilities -Isrc/libs/spdlog/include -o build/result/programm src/main/cpp/main.cpp src/main/cpp/Implement/Utilities/NexisBuilder.cpp src/main/cpp/Implement/Utilities/NexisLoggerSpd.cpp