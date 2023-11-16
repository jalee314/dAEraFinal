#ifndef NPC_H
#define NPC_H
#include <string>
#include <vector>

class INPCPrint {
public:
    virtual void printName() = 0;
    virtual void printResponse(int index) = 0;
};

class INPCAdd {
public:
    virtual void addQuestion(const std::string& question) = 0;
    virtual void addResponse(const std::string& response) = 0;
};

//^^Interfaces for NPC class, 


class NPC : public INPCPrint, public INPCAdd {
public:
    NPC(const std::string& NPCName):name(NPCName){}
    void addResponse(const std:: string& response);
    void addQuestion(const std::string& question);
    void printName();
    void printResponse(int index);
    int getQuestionsSize(){return askableQuestions.size();}//How many questions are in the vector

private:
    std::string name;
    std::vector<std::string> responses;
    std::vector<std::string> askableQuestions;
};

#endif //NPC_H