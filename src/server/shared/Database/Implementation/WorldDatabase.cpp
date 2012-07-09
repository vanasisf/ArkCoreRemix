/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "WorldDatabase.h"

void WorldDatabaseConnection::DoPrepareStatements() {
    if (!m_reconnecting)
        m_stmts.resize(MAX_WORLDDATABASE_STATEMENTS);

    PREPARE_STATEMENT(WORLD_LOAD_QUEST_POOLS,
            "SELECT entry, pool_entry FROM pool_quest", CONNECTION_SYNCH);
    PREPARE_STATEMENT(WORLD_DEL_CRELINKED_RESPAWN,
            "DELETE FROM linked_respawn WHERE guid = ?", CONNECTION_ASYNC);
    PREPARE_STATEMENT(WORLD_REP_CRELINKED_RESPAWN,
            "REPLACE INTO linked_respawn (guid, linkedGuid) VALUES (?, ?)",
            CONNECTION_ASYNC);
    PREPARE_STATEMENT(
            WORLD_LOAD_CRETEXT,
            "SELECT entry, groupid, id, content_default, type, language, probability, emote, duration, sound FROM creature_text",
            CONNECTION_SYNCH);
    PREPARE_STATEMENT(
            WORLD_LOAD_SMART_SCRIPTS,
            "SELECT entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o FROM smart_scripts ORDER BY entryorguid, source_type, id, link",
            CONNECTION_SYNCH);
    PREPARE_STATEMENT(
            WORLD_LOAD_SMARTAI_WP,
            "SELECT entry, pointid, position_x, position_y, position_z FROM waypoints ORDER BY entry, pointid",
            CONNECTION_SYNCH);
    PREPARE_STATEMENT(
            WORLD_SEL_LOCALES_CREATURE_TEXT,
            "SELECT entry, groupid, id, text_loc1, text_loc2, text_loc3, text_loc4, text_loc5, text_loc6, text_loc7, text_loc8 FROM locales_creature_text",
            CONNECTION_SYNCH);
}
