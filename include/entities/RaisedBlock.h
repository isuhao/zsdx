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
#ifndef ZSDX_RAISED_BLOCK_H
#define ZSDX_RAISED_BLOCK_H

#include "Common.h"
#include "entities/Detector.h"

/**
 * An orange or blue block that can be raised or lowered with the help of a crystal switch.
 */
class RaisedBlock: public Detector {

 public:

  /**
   * Subtypes of raised blocks.
   */
  enum Subtype {
    ORANGE = 0, /**< an orange block */
    BLUE   = 1, /**< a blue block */
  };

 private:

  Subtype subtype;    /**< indicates whether this is an orange or a blue block */
  bool orange_raised; /**< true if the orange blocks are raised,
	               * false if the blue blocks are raised */

 public:

  RaisedBlock(Layer layer, int x, int y, int width, int height, Subtype subtype);
  ~RaisedBlock(void);

  EntityType get_type(void);

  bool is_obstacle_for(MapEntity *other);

  void update(void);
  void display_on_map(void);
};

#endif
