function event_map_started()

   if savegame_get_boolean(24) then
      npc_remove("monkey")
   end

   npc_random_walk("hat_man")
   npc_random_walk("grand_son")
end

-- Function called when the player wants to talk to a non-playing character
function event_npc_dialog(npc_name)

   if npc_name == "monkey" then
      -- monkey dialog
      play_sound("la_monkey")
      show_message("outside_world.village.monkey")
   end
end

-- Function called when the dialog box is being closed
function event_message_sequence_finished(first_message_id, answer)

   if first_message_id == "outside_world.village.monkey" then

      if equipment_get_shield() > 0 then
	 show_message("outside_world.village.monkey.with_shield")
      else
	 show_message("outside_world.village.monkey.without_shield")
      end
   end
end
