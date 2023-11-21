#include "../header/Map.h"
#include "../header/Environment.h"
#include <vector>

//Honestly kinda forgor how adjancency matrix work. Should grow to fit whenever room is added.
Map::Map(int numRooms) :
    adjacencyMatrix.resize(numRooms, std::vector<int>(numRooms, 0));
{}

Map::~Map() {}

void Map::addRoom(const Environment& room) {
    rooms.push_back(room);
}

//SHOULD allow us to create a "door" between any two rooms 
void Map::connectRooms(int from, int to) {
    if (from >= 0 && from < rooms.size() && to >= 0 && to < rooms.size()) {
        adjacencyMatrix[from][to] = 1;
    }
}

//If the "door" is good at the matrix location, will return true.
bool Map::canMove(int from, int to) const {
    return adjacencyMatrix[from][to] != 0;
}

const Environment& Map::getRoom(int index) const {
    return rooms[index];
}