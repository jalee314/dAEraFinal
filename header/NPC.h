#ifndef NPC_H
#define NPC_H
#include <string>
#include <vector>

class INPCResponse {
public:
    virtual void addResponse(const std::string& response) = 0;
    virtual void printResponse(int index) = 0;
};

class INPCInteract {
public:
    virtual void addQuestion(const std::string& question) = 0;
    virtual void printName() = 0;
};

//^^Interfaces for NPC class, 


class NPC : public INPCResponse, public INPCInteract {
public:
    NPC(const std::string& NPCName):name(NPCName){}
    void addResponse(const std:: string& response);
    void addQuestion(const std::string& question);
    void printName();
    void printResponse(int index);

private:
    std::string name;
    std::vector<string> responses;
    std::vector<string> askableQuestions;
};

#endif //MAINMENU_H