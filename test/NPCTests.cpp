#include "gtest/gtest.h"
#include "../header/NPC.h"
#include <iostream>
#include <sstream>

TEST(NPCTestSuite, TestNPCNaming) {
    NPCQuestionManager questionManager;
    NPCPrinter npc("Thomas", questionManager);
    std::stringstream buffer; //buffer object created form stringstream class
    std::cout.rdbuf(buffer.rdbuf()); //any buffer meant for cout is redirected to stringstream buffer object
    npc.printName(); 
    EXPECT_EQ("Thomas\n", buffer.str());
}

TEST(NPCTestSuite, PrintResponseError) {
    NPCQuestionManager questionManager;
    NPCPrinter npc("John", questionManager);
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    npc.printResponse(5); //index 5 not initialized, should fail.
    EXPECT_EQ("I am unable to answer your question.\n", buffer.str());
}

TEST(NPCTestSuite, PrintResponse) {
    NPCQuestionManager questionManager;
    NPCPrinter npc("Carla", questionManager);
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    questionManager.addResponse("I thought I was the only survivor... this is wonderful to see.");
    npc.printResponse(0);
    EXPECT_EQ("I thought I was the only survivor... this is wonderful to see.\n", buffer.str());
}

TEST(NPCTestSuite, AddQuestion) {
    NPCQuestionManager questionManager;
    std::stringstream buffer;TEST(NPCTestSuite, PrintResponse) {
    NPCQuestionManager questionManager;
    NPCPrinter npc("Carla", questionManager);
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    questionManager.addResponse("I thought I was the only survivor... this is wonderful to see.");
    npc.printResponse(0);
    EXPECT_EQ("I thought I was the only survivor... this is wonderful to see.\n", buffer.str());
}

    std::cout.rdbuf(buffer.rdbuf());
    questionManager.addQuestion("How many more rooms are there to discover?");
    questionManager.addQuestion("Are you doing alright?");
    EXPECT_EQ(questionManager.getQuestionsSize(), 2);
}