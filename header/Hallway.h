#ifndef HALLWAY_H
#define HALLWAY_H

#include "Environment.h"

class Hallway : public Environment {
public:
   Hallway(const std::string& name);
   virtual ~Hallway();
};

#endif // HALLWAY_H
