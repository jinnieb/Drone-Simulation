#include "RepairStation.h"

Repair::Repair(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = 0;
  available = false;
}

JsonObject Repair::GetDetails() const { return details; }
