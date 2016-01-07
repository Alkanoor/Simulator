#include "ProtocolCutter.hpp"


std::pair<ActionType,std::string> ProtocolCutter::cut(const std::string& str)
{
    boost::smatch match;
    boost::regex reg("GET_DIFF\\s*(.*)");
    if(boost::regex_match(str, match, reg))
        return std::pair<ActionType,std::string>(GET_DIFF,match[1]);
    else
    {
        boost::regex reg("GET_ALL\\s*(.*)");
        if(boost::regex_match(str, match, reg))
            return std::pair<ActionType,std::string>(GET_ALL,match[1]);
        else
        {
            boost::regex reg("ACTION\\s*(.*)");
            if(boost::regex_match(str, match, reg))
                return std::pair<ActionType,std::string>(ACTION,match[1]);
            else
            {
                boost::regex reg("AUTH\\s*(.*)");
                if(boost::regex_match(str, match, reg))
                    return std::pair<ActionType,std::string>(AUTH,match[1]);
                else
                {
                    boost::regex reg("UPDATE_ENTITY\\s*(.*)");
                    if(boost::regex_match(str, match, reg))
                        return std::pair<ActionType,std::string>(UPDATE_ENTITY,match[1]);
                    else
                    {
                        boost::regex reg("CHANGE_SYN\\s*(.*)");
                        if(boost::regex_match(str, match, reg))
                            return std::pair<ActionType,std::string>(CHANGE_SYN,match[1]);
                        else
                            return std::pair<ActionType,std::string>(UNKNOWN,"");
                    }
                }
            }
        }
    }
}
