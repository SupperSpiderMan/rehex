/* Reverse Engineer's Hex Editor
 * Copyright (C) 2020 Daniel Collins <solemnwarning@solemnwarning.net>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "Events.hpp"

wxDEFINE_EVENT(REHex::COMMENT_LEFT_CLICK,     REHex::OffsetLengthEvent);
wxDEFINE_EVENT(REHex::COMMENT_RIGHT_CLICK,    REHex::OffsetLengthEvent);
wxDEFINE_EVENT(REHex::DATA_RIGHT_CLICK,       wxCommandEvent);

wxDEFINE_EVENT(REHex::DATA_ERASE,        REHex::OffsetLengthEvent);
wxDEFINE_EVENT(REHex::DATA_INSERT,       REHex::OffsetLengthEvent);
wxDEFINE_EVENT(REHex::DATA_OVERWRITE,    REHex::OffsetLengthEvent);

wxDEFINE_EVENT(REHex::CURSOR_UPDATE,    REHex::CursorUpdateEvent);

REHex::CursorUpdateEvent::CursorUpdateEvent(wxWindow *source, off_t cursor_pos, Document::CursorState cursor_state):
	wxEvent(source->GetId(), CURSOR_UPDATE),
	cursor_pos(cursor_pos),
	cursor_state(cursor_state)
{
	m_propagationLevel = wxEVENT_PROPAGATE_MAX;
	SetEventObject(source);
}

wxEvent *REHex::CursorUpdateEvent::Clone() const
{
	return new CursorUpdateEvent(*this);
}