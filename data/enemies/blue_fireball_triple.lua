local enemy = ...

-- A triple bouncing fireball that the hero cannot fight

local speed = 192
local bounces = 0
local max_bounces = 8
local sprite2 = nil
local sprite3 = nil

function enemy:on_appear()

  self:set_life(1)
  self:set_damage(8)
  self:create_sprite("enemies/blue_fireball_triple")
  self:set_size(16, 16)
  self:set_origin(8, 8)
  self:set_obstacle_behavior("flying")
  self:set_invincible()
  self:set_attack_consequence("sword", "custom")

  -- two smaller fireballs just for the displaying
  sprite2 = sol.sprite.create("enemies/blue_fireball_triple")
  sprite2:set_animation("small")
  sprite3 = sol.sprite.create("enemies/blue_fireball_triple")
  sprite3:set_animation("tiny")
end

function enemy:on_restart()

  local x, y = self:get_position()
  local hero_x, hero_y = self:get_map():hero_get_position()
  local angle = sol.main.get_angle(x, y, hero_x, hero_y - 5)
  local m = sol.movement.create("straight")
  m:set_speed(speed)
  m:set_angle(angle)
  self:start_movement(m)
end

function enemy:on_obstacle_reached()

  if bounces < max_bounces then

    -- compute the bouncing angle
    -- (works good with horizontal and vertical walls)
    local m = self:get_movement()
    local angle = m:get_angle()
    if not self:test_obstacles(1, 0)
      and not self:test_obstacles(-1, 0) then
      angle = -angle
    else
      angle = math.pi - angle
    end

    m:set_angle(angle)
    m:set_speed(speed)

    bounces = bounces + 1
    speed = speed + 48
  else
    self:get_map():enemy_remove(self:get_name())
  end
end

function enemy:on_custom_attack_received(attack, sprite)

  if attack == "sword" then
    -- explode
    local x, y, layer = self:get_position()
    self:get_map():hero_start_hurt(x, y, 8, 0)
    sol.audio.play_sound("explosion")
    self:get_map():explosion_create(x, y, layer)
    self:get_map():enemy_remove(self:get_name())
  end
end

function enemy:on_pre_draw()

  local m = self:get_movement()
  local angle = m:get_angle()
  local x, y = self:get_position()

  local x2 = x - math.cos(angle) * 12
  local y2 = y + math.sin(angle) * 12

  local x3 = x - math.cos(angle) * 24
  local y3 = y + math.sin(angle) * 24

  self:get_map():sprite_display(sprite2, x2, y2)
  self:get_map():sprite_display(sprite3, x3, y3)
end

