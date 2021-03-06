/*
Minetest-c55
Copyright (C) 2011 celeron55, Perttu Ahola <celeron55@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef GAMEDEF_HEADER
#define GAMEDEF_HEADER

#include <string>

class IToolDefManager;
class INodeDefManager;
class ICraftDefManager;
class ICraftItemDefManager;
// Mineral too?
class ITextureSource;

/*
	An interface for fetching game-global definitions like tool and
	mapnode properties
*/

class IGameDef
{
public:
	// These are thread-safe IF they are not edited while running threads.
	// Thus, first they are set up and then they are only read.
	virtual IToolDefManager* getToolDefManager()=0;
	virtual INodeDefManager* getNodeDefManager()=0;
	virtual ICraftDefManager* getCraftDefManager()=0;
	virtual ICraftItemDefManager* getCraftItemDefManager()=0;

	// This is always thread-safe, but referencing the irrlicht texture
	// pointers in other threads than main thread will make things explode.
	virtual ITextureSource* getTextureSource()=0;
	
	// Used for keeping track of names/ids of unknown nodes
	virtual u16 allocateUnknownNodeId(const std::string &name)=0;

	// Shorthands
	IToolDefManager* tdef(){return getToolDefManager();}
	INodeDefManager* ndef(){return getNodeDefManager();}
	ICraftDefManager* cdef(){return getCraftDefManager();}
	ICraftItemDefManager* cidef(){return getCraftItemDefManager();}
	ITextureSource* tsrc(){return getTextureSource();}
};

#endif

