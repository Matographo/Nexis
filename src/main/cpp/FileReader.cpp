#include "FileReader.h"


std::string readFileAsString(const std::string& filePath) {
    std::ifstream fileStream(filePath); // Öffnet die Datei im Eingabemodus
    if (!fileStream.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf(); // Liest den gesamten Dateiinhalt in einen stringstream

    return buffer.str(); // Gibt den Inhalt als String zurück
}