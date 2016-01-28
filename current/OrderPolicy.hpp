#ifndef ORDERPOLICY_HPP_INCLUDED
#define ORDERPOLICY_HPP_INCLUDED


enum ORDER_REACTION_TYPE {AGREE,WAIT_NETWORK,DISAGREE};

class OrderPolicy
{
    public:
        virtual ORDER_REACTION_TYPE getGroupReaction(const std::vector<ORDER_REACTION_TYPE>& individualReactions) const = 0;
};


class DisagreePolicy : public OrderPolicy
{
    public:
        ORDER_REACTION_TYPE getGroupReaction(const std::vector<ORDER_REACTION_TYPE>& individualReactions) const
        {return DISAGREE;}
};

class AgreePolicy : public OrderPolicy
{
    public:
        ORDER_REACTION_TYPE getGroupReaction(const std::vector<ORDER_REACTION_TYPE>& individualReactions) const
        {return AGREE;}
};

class OneAgreeSufficePolicy : public OrderPolicy
{
    public:
        ORDER_REACTION_TYPE getGroupReaction(const std::vector<ORDER_REACTION_TYPE>& individualReactions) const
        {
            if(!individualReactions.size())
                return AGREE;
            for(unsigned int i=0;i<individualReactions.size();i++)
                if(individualReactions[i]==AGREE)
                    return AGREE;
            for(unsigned int i=0;i<individualReactions.size();i++)
                if(individualReactions[i]==WAIT_NETWORK)
                    return WAIT_NETWORK;
            return DISAGREE;
        }
};

class AllAgreeNeededPolicy : public OrderPolicy
{
    public:
        ORDER_REACTION_TYPE getGroupReaction(const std::vector<ORDER_REACTION_TYPE>& individualReactions) const
        {
            if(!individualReactions.size())
                return AGREE;
            for(unsigned int i=0;i<individualReactions.size();i++)
                if(individualReactions[i]==DISAGREE)
                    return DISAGREE;
            for(unsigned int i=0;i<individualReactions.size();i++)
                if(individualReactions[i]==WAIT_NETWORK)
                    return WAIT_NETWORK;
            return AGREE;
        }
};

class MajorityPolicyWaitForNetwork : public OrderPolicy
{
    public:
        ORDER_REACTION_TYPE getGroupReaction(const std::vector<ORDER_REACTION_TYPE>& individualReactions) const
        {
            if(!individualReactions.size())
                return AGREE;
            for(unsigned int i=0;i<individualReactions.size();i++)
                if(individualReactions[i]==WAIT_NETWORK)
                    return WAIT_NETWORK;
            unsigned int agree=0, disagree=0;
            for(unsigned int i=0;i<individualReactions.size();i++)
                if(individualReactions[i]==AGREE)
                    agree++;
                else if(individualReactions[i]==DISAGREE)
                    disagree++;
            if(agree>=disagree)
                return AGREE;
            else
                return DISAGREE;
        }
};


#endif
