/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ULTIMA8_GUMPS_MODALGUMP_H
#define ULTIMA8_GUMPS_MODALGUMP_H

#include "ultima/ultima8/gumps/gump.h"
#include "ultima/ultima8/misc/classtype.h"

namespace Ultima {
namespace Ultima8 {

/**
 * Base class for any gump which blocks the game (menu, credits, movie, etc)
 */
class ModalGump : public Gump {
protected:
	bool _pauseGame;

public:
	ENABLE_RUNTIME_CLASSTYPE()

	ModalGump();
	ModalGump(int x, int y, int width, int height, uint16 owner = 0,
			  uint32 flags = FLAG_DONT_SAVE | FLAG_PREVENT_SAVE, int32 layer = LAYER_MODAL,
			  bool pauseGame = true);

	~ModalGump() override;

	void InitGump(Gump *newparent, bool take_focus = true) override;

	void Close(bool no_del = false) override;

	bool PointOnGump(int mx, int my) override;
	Gump *FindGump(int mx, int my) override;
	uint16 TraceObjId(int32 mx, int32 my) override;

	Gump *onMouseDown(int button, int32 mx, int32 my) override;

	bool loadData(Common::ReadStream *rs, uint32 version);
	void saveData(Common::WriteStream *ws) override;
};

} // End of namespace Ultima8
} // End of namespace Ultima

#endif
