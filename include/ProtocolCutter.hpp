#ifndef PROTOCOLCUTTER_HPP
#define PROTOCOLCUTTER_HPP


#include <boost/regex.hpp>
#include <map>


enum ActionType{GET_DIFF,GET_ALL,ACTION,AUTH,UPDATE_ENTITY,CHANGE_SYN,UNKNOWN};

namespace ProtocolCutter
{
    std::pair<ActionType,std::string> cut(const std::string& str);
};


#endif
