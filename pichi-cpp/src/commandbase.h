/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <2010>  <Alexey Kasyanchuk (deg@uruchie.org)>

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

#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include "commandhandler.h"
#include <map>
#include <string>
#include <algorithm>

class pichicore;

class commandbase : public commandhandler
{
  public:
    commandbase(pichicore* p);
    void fetchCommand(std::string command);
        
    protected:
	  std::map<std::string, void (commandbase::*)(std::string)> commands;
	  
	  void command_version(std::string);
	  void command_enable(std::string arg);
	  void command_disable(std::string arg);
	  void command_log(std::string arg);
	  void command_wtf(std::string arg);
	  void command_wtfcount(std::string arg);
	  void command_wtfrand(std::string arg);
	  void command_wtfrev(std::string arg);
	  void command_wtfull(std::string arg);
	  void command_wtfset(std::string arg);
	  void command_top(std::string arg);
	  void command_talkers(std::string arg);
	  void command_count(std::string arg);
	  void command_dfn(std::string arg);
	  void command_set(std::string arg);
	  void command_msg(std::string arg);
};

#endif // COMMANDBASE_H