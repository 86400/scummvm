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

#ifdef ENABLE_MADSV2

#include "mads/forest/globals_forest.h"

namespace MADS {

namespace Forest {

ForestGlobals::ForestGlobals()
	: Globals() {
	// Initialize lists
	resize(140);
	_spriteIndexes.resize(30);
	_sequenceIndexes.resize(30);
	_animationIndexes.resize(30);
}

void ForestGlobals::synchronize(Common::Serializer &s) {
	Globals::synchronize(s);

	_spriteIndexes.synchronize(s);
	_sequenceIndexes.synchronize(s);
	_animationIndexes.synchronize(s);
}


} // End of namespace Forest

} // End of namespace MADS

#endif
