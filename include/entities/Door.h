/*
 * Copyright (C) 2009 Christopho, Zelda Solarus - http://www.zelda-solarus.com
 * 
 * Zelda: Mystery of Solarus DX is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Zelda: Mystery of Solarus DX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ZSDX_DOOR_H
#define ZSDX_DOOR_H

#include "Common.h"
#include "Detector.h"

/**
 * A door to open with a key or an event.
 */
class Door: public Detector {

 public:

  /**
   * The different kinds of doors.
   */
  enum Subtype {
    CLOSED,
    SMALL_KEY,
    SMALL_KEY_BLOCK,
    BIG_KEY,
    BOSS_KEY,
    WEAK,
    VERY_WEAK,
    WEAK_INVISIBLE,
  };

 private:

  static const std::string animations[]; /**< animation name of each subtype */

  // properties
  Subtype subtype;           /**< subtype of door */
  int savegame_variable;     /**< variable where the door state is saved */

  // state
  bool door_open;            /**< indicates that this door is open */
  bool changing;             /**< indicates that the door is being open or closed */

  void set_open(bool open);

  bool has_action_key_effect(void);
  bool requires_small_key(void);
  bool can_open(void);

 public:

  Door(const std::string &name, Layer layer, int x, int y,
      int direction, Subtype subtype, int savegame_variable);
  ~Door(void);

  EntityType get_type(void);

  bool is_obstacle_for(MapEntity *other);
  void set_suspended(bool suspended);
  void update(void);
  void display_on_map(void);
  void collision(MapEntity *entity_overlapping, CollisionMode collision_mode);
  void action_key_pressed(void);

  bool is_open(void);
  void open(void);
  void close(void);
};

#endif

