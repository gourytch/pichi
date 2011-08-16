/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  <copyright holder> <email>

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

#ifdef WITH_LUA

#include "luapichi.h"

#include <algorithm>

#include "helper.h"
#include "log.h"
#include "pichiexception.h"
#include "pichicore.h"

namespace pichi
{

LuaPichi::LuaPichi()
{
	loadLuaFiles();
	
	luaMap["SendAnswer"] = PichiManager::sendAnswer;
	registerLuaMap(); // регитрируем map
}
  
void LuaPichi::loadLuaFiles(void )
{
	std::vector< std::string > luaFiles = Helper::getDirFiles(PICHI_INSTALLED_DIR + std::string("lua/"));
	if(luaFiles.size() == 0)
	{
		Log("No lua plugins :(", Log::DEBUG);
		return;
	}
	
	std::for_each(luaFiles.begin(), luaFiles.end(), [this](const std::string& fileName){
		this->loadFile((PICHI_INSTALLED_DIR + std::string("lua/") + fileName).c_str());
		if(this->loadFileStatus != 0)
			throw PichiException("Load lua file " + fileName + " problem...");
		else
			this->loadedLuaList.push_back(fileName);
	});
}

std::list<std::string> LuaPichi::getLuaFunctionsList(void)
{
     std::list<std::string> registerList;
     std::for_each(luaMap.begin(), luaMap.end(), [&registerList](std::pair<const char * const, lua_CFunction>& p){
		registerList.push_back(p.first);
     });
     return registerList;
}

int PichiManager::sendAnswer(lua_State* L)
{
	PichiCore* pichi = (PichiCore*)lua_touserdata(L, -2);
	std::string toSend = lua_tostring(L, -1);
	pichi->sendAnswer(toSend);
	return 0;
}

};

#endif