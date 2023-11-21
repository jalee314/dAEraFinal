#ifndef MAP_H
#define MAP_H

#include "../header/Environment.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Map {
private:
    std::vector<Environment> rooms;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    Map(int numRooms);
    void addRoom(const Environment& room);
    void connectRooms(int from, int to);
    bool canMove(int from, int to) const;
    const Environment& getRoom(int index) const;
};

#endif //MAP_H