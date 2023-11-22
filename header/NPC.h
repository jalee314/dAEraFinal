#ifndef NPC_H
#define NPC_H
#include <string>
#include <vector>

class INPCPrint {
public:
    virtual void printName() = 0;
    virtual void printResponse(int index) = 0;
    virtual ~INPCPrint(){}
};

class INPCInteraction {
public:
    virtual void addQuestion(const std::string& question) = 0;
    virtual void addResponse(const std::string& response) = 0;
    virtual int getQuestionsSize() = 0;
    virtual int getResponsesSize() = 0;
    virtual std::string getResponse(int index) = 0;
    virtual ~INPCInteraction(){}
};

//^^Interfaces for NPC class, 

class NPCQuestionManager: public INPCInteraction {
public: 
    virtual void addResponse(const std:: string& response);
    virtual void addQuestion(const std::string& question);
    virtual std::string getResponse(int index);
    virtual int getQuestionsSize(){return askableQuestions.size();}
    virtual int getResponsesSize(){return responses.size();}
private:
    std::vector<std::string> responses;
    std::vector<std::string> askableQuestions;
};


class NPCPrinter: public INPCPrint {
public:     
    NPCPrinter(const std::string& NPCName, NPCQuestionManager& npcQuestionManager):
    name(NPCName), questionManager(npcQuestionManager){}
    virtual void printName();
    virtual void printResponse(int index);
private:
    std::string name;
    NPCQuestionManager& questionManager;
};

#endif //NPC_H