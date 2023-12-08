#include "../header/MainMenu.h"
#include "../header/Enemy.h"
#include "../header/Inventory.h"
#include "../header/Item.h"
#include "../header/Environment.h"
#include "../header/Map.h"
#include "../header/Hallway.h"
#include "../header/NPC.h"
#include "../header/playerCharacter.h"
#include "../header/battleActions.h"
#include "../header/Basar.h"
#include "../header/NPC.h"
#include "../header/Room.h"
#include <iostream>
#include <unordered_map>


int main() {
	MainMenu mainMenu;
	Basar basar;
	battleActions battle;
	bool battleOccuring = false;
	bool gameRunning = true;
	EnemyStatus* enemy;
	PlayerCharacter* protagonist; 
	string menuInput;
	//instantiate all objects required
	mainMenu.output();
	while(true) {
		std::cin >> menuInput;
		if(menuInput == "1") {
			break;
		}
		else if(menuInput == "2") {
			mainMenu.quit();
		}
		else std::cout << "\nInvalid option, Choose 1 or 2...\n\n";
	}
	
	//initialize the enemies that should spawn in each room
	EnemyStatus* noEnemy = nullptr;

	Rat ratInRatRoom;
	Rat ratInKitchen;
	Rat* ratRoomRat = &ratInRatRoom; 
	Rat* kitchenRat = &ratInKitchen;

	Alien alienInRecRoom;
	Alien alienInSleepingQuarters; 
	Alien alienInEscapeRoom;
	Alien* recRoomAlien = &alienInRecRoom;
	Alien* sleepingQuarterAlien = &alienInSleepingQuarters;
	Alien* escapeRoomAlien = &alienInEscapeRoom;

	Crewmate crewmateInLab;
	Crewmate crewmateInInfirmary;
	Crewmate crewmateInBoilerRoom;
	Crewmate* labCrewmate = &crewmateInLab;
	Crewmate* infirmaryCrewmate = &crewmateInInfirmary;
	Crewmate* boilerRoomCrewmate = &crewmateInBoilerRoom;

	Terrorist terroristInSupplyCloset;
	Terrorist terroristInLoadingZone;
	Terrorist terroristInWeaponRoom;
	Terrorist* supplyClosetTerrorist = &terroristInSupplyCloset;
	Terrorist* loadingZoneTerrorist = &terroristInLoadingZone;
	Terrorist* weaponRoomTerrorist = &terroristInWeaponRoom;

	//initialize the items that will appear in each room;
	Item* noItem = nullptr;
	
	Weapon shotgun("Shotgun", 10);
	Weapon hammer("Hammer", 8);
	Weapon fryingPan("Frying Pan", 9);
	Weapon* shotgunPointer = &shotgun; //*
	Weapon* hammerPointer = &hammer; //*
	Weapon *fryingPanPointer = &fryingPan; //*

	HelpItem kevlarVest("Kevlar Vest", 2, "defense");
	HelpItem firstAidKit("First Aid Kit", 10, "health");
	HelpItem steroids("Medicinal Steroids", 3, "attack");
	HelpItem nutritionalFood("Nutritional Sludge", 5, "health");
	HelpItem prescribedPills("Prescribed Pills", 5, "health");
	HelpItem keyCard("Key Card", 0, "wincon");
	HelpItem* kevlarVestPointer = &kevlarVest; //*
	HelpItem* firstAidKitPointer = &firstAidKit; //*
	HelpItem* steroidsPointer = &steroids; //*
	HelpItem* nutritionalFoodPointer = &nutritionalFood; //*
	HelpItem* prescribedPillsPointer = &prescribedPills; //*
	HelpItem* keyCardPointer = &keyCard; //*

	//Initialize the page that will appear in each room.
	Page* noPage = nullptr;

	//creating our map (gonna be a big chunk lol)
	
	Room controlRoom("An array of generative machinery surrounds you, disorganized wires maneuvering the floor like electric serpents.", 
	"Control Room (spawn point)", kevlarVestPointer, noEnemy, noPage);
	Room recRoom("It's a small room, with just one television and a few gaming consoles with barely any games. There are some magazines, but they're old; no one's brought any from Earth in a long time.", 
	"Recreation Room", noItem, recRoomAlien, noPage);
	Room weaponRoom("Two large, backlit storage racks with firearms and blunt weaponry meet you as you enter the room.", 
	"Weapon/Ammunition Room", shotgunPointer, weaponRoomTerrorist, noPage);
	Room infirmary("Off-white walls surround what was once a safe haven. Now, it's a mess, with beds turned over and flickering lights that fill you with dread.", 
	"Infirmary", firstAidKitPointer, infirmaryCrewmate, noPage);
	Room supplyCloset("It's a little cramped in here.", 
	"Supply Closet", keyCardPointer, supplyClosetTerrorist, noPage);
	Room testingLab("Torn-up documents and blood—is it even human?—litter the floor. On the other side, you can see the enclosure that Specimen Aleph was trapped in for seven months.", 
	"Testing Lab", steroidsPointer, labCrewmate, noPage);
	Room sleepingQuarters("An organized set of bunk beds in a boot camp-like arrangement juxtapose the disarray of the rest of the ship. By the looks of it, nobody was in here at the time of detonation.", 
	"Sleeping Quarters", prescribedPillsPointer, sleepingQuarterAlien, noPage);
	Room kitchen("It's a gray cantina with some awful-looking (and, from your experience, the taste isn't any better) sludge stored in tubs. The expiration date is around ten years from now.", 
	"Kitchen", fryingPanPointer, kitchenRat, noPage);
	Room ratRoom("I don't wanna talk about it. Get me out." ,
	"The Rat Room", nutritionalFoodPointer, ratRoomRat, noPage);
	Room loadingZone("This is where other ships usually dock to unload shipments. It's unlikely anybody's coming to help now...", 
	"Loading Zone", noItem, loadingZoneTerrorist, noPage);
	Room boilerRoom("Several pipes conjoin to form an amalgamation of mechanical prowess. They all connect to their respective machines and extend out of the room, through the walls.", 
	"Boiler Room", hammerPointer, boilerRoomCrewmate, noPage); 
	Room escapeRoom("Freedom is right in front of you.",
	"Escape Room", noItem, escapeRoomAlien, noPage);
	//hallways

	Hallway hallwayControlRec("Hallway between Control Room and Rec Room");
	Hallway hallwayControlInfirmary("Hallway between Control Room and Infirmary");
	Hallway hallwayControlKitchen("Hallway between Control Room and Kitchen");
	Hallway hallwayRatKitchen("Hallway between Rat Room and Kitchen");
	Hallway hallwayRatRec("Hallway between Rat Room and Rec Room");
	Hallway hallwayWeaponRec("Hallway between Weapon/Ammunition Room and Rec Room");
	Hallway hallwayKitchenSleeping("Hallway between Kitchen and Sleeping Quarters");
	Hallway hallwaySleepingInfirmary("Hallway between Sleeping Quarters and Infirmary");
	Hallway hallwayInfirmarySupply("Hallway between Infirmary and Supply Closet");
	Hallway hallwayRecBoiler("Hallway between Rec Room and Boiler Room");
	Hallway hallwayLoadingKitchen("Hallway between Loading Zone and Kitchen");
	Hallway hallwayControlEscape("Hallway between Control Room and Escape Room");
	Hallway hallwayTestingInfirmary("Hallway between Testing Laboratory and Infirmary");


	std::vector<Environment*> gameRooms = {
    	&controlRoom,              // Index 0
    	&hallwayControlRec,        // Index 1
    	&recRoom,                  // Index 2
    	&hallwayWeaponRec,         // Index 3
    	&weaponRoom,               // Index 4
    	&hallwayControlInfirmary,  // Index 5
    	&infirmary,                // Index 6
    	&hallwayInfirmarySupply,   // Index 7
    	&supplyCloset,             // Index 8
    	&hallwayTestingInfirmary,  // Index 9
    	&testingLab,               // Index 10
    	&hallwayControlKitchen,    // Index 11
    	&kitchen,                  // Index 12
    	&hallwayKitchenSleeping,   // Index 13
    	&sleepingQuarters,         // Index 14
    	&hallwaySleepingInfirmary, // Index 15
    	&hallwayRatKitchen,        // Index 16
    	&ratRoom,                  // Index 17
    	&hallwayRatRec,            // Index 18
    	&hallwayLoadingKitchen,    // Index 19
    	&loadingZone,              // Index 20
    	&boilerRoom,               // Index 21
    	&hallwayRecBoiler,         // Index 22
    	&hallwayControlEscape,      // Index 23
    	&escapeRoom 	//Index 24
	};
	
	const int NUM_ROOMS = gameRooms.size();
	Map gameMap(NUM_ROOMS);

	for(Environment* room: gameRooms) {
		gameMap.addRoom(room);
	}
	
	gameMap.connectRooms(0, 1);
	gameMap.connectRooms(1, 0);
	gameMap.connectRooms(1, 2);
	gameMap.connectRooms(2, 1);
	gameMap.connectRooms(2, 3);
	gameMap.connectRooms(3, 2);
	gameMap.connectRooms(3, 4);
	gameMap.connectRooms(4, 3);
	gameMap.connectRooms(0, 5);
	gameMap.connectRooms(5, 0);
	gameMap.connectRooms(5, 6);
	gameMap.connectRooms(6, 5);
	gameMap.connectRooms(6, 7);
	gameMap.connectRooms(7, 6);
	gameMap.connectRooms(7, 8);
	gameMap.connectRooms(8, 7);
	gameMap.connectRooms(9, 10);
	gameMap.connectRooms(10, 9);
	gameMap.connectRooms(9, 6);
	gameMap.connectRooms(6, 9);
	gameMap.connectRooms(0, 11);
	gameMap.connectRooms(11, 0);
	gameMap.connectRooms(11, 12);
	gameMap.connectRooms(12, 11);
	gameMap.connectRooms(12, 13);
	gameMap.connectRooms(13, 12);
	gameMap.connectRooms(13, 14);
	gameMap.connectRooms(14, 13);
	gameMap.connectRooms(14, 15);
	gameMap.connectRooms(15, 14);
	gameMap.connectRooms(15, 6);
	gameMap.connectRooms(6, 15);
	gameMap.connectRooms(12, 16);
	gameMap.connectRooms(16, 12);
	gameMap.connectRooms(16, 17);
	gameMap.connectRooms(17, 16);
	gameMap.connectRooms(17, 18);
	gameMap.connectRooms(18, 17);
	gameMap.connectRooms(18, 2);
	gameMap.connectRooms(2, 18);
	gameMap.connectRooms(19, 20);
	gameMap.connectRooms(20, 19);
	gameMap.connectRooms(19, 12);
	gameMap.connectRooms(12, 19);
	gameMap.connectRooms(21, 22);
	gameMap.connectRooms(22, 21);
	gameMap.connectRooms(22, 2);
	gameMap.connectRooms(2, 22);
	gameMap.connectRooms(23, 0);
	gameMap.connectRooms(0, 23);
	gameMap.connectRooms(23, 24);
	gameMap.connectRooms(24, 23);

	//Create the adjacency matrix ^^
	
	std::unordered_map<int, std::unordered_map<std::string, int>> roomDirections;
	roomDirections[0] = {{"west", 1}, {"east", 5}, {"north", 23}, {"south", 11}};
	roomDirections[1] = {{"west", 2}, {"east", 0}};
	roomDirections[2] = {{"west", 3}, {"east", 1}, {"north", 22 }, {"south", 18}};
	roomDirections[3] = {{"west", 4}, {"east", 2}};
	roomDirections[4] = {{"east", 3}};
	roomDirections[5] = {{"west", 0}, {"east", 6}};
	roomDirections[6] = {{"west", 5}, {"east", 7}, {"north", 9}, {"south", 15}};
	roomDirections[7] = {{"west", 6}, {"east", 8}};
	roomDirections[8] = {{"west", 7}};
	roomDirections[9] = {{"north", 10}, {"south", 6}};
	roomDirections[10] = {{"south", 9}};
	roomDirections[11] = {{"north", 0}, {"south", 12}};
	roomDirections[12] = {{"west", 16}, {"east", 13},{"north", 11},{"south", 19}};
	roomDirections[13] = {{"west", 12}, {"east", 14}};
	roomDirections[14] = {{"west", 13}, {"north", 15}};
	roomDirections[15] = {{"north", 6}, {"south", 14}};
	roomDirections[16] = {{"west", 17}, {"east", 12}};
	roomDirections[17] = {{"east", 16}, {"north", 18}};
	roomDirections[18] = {{"north", 2}, {"south", 3}};
	roomDirections[19] = {{"north", 12}, {"south", 20}};
	roomDirections[20] = {{"north", 19}};
	roomDirections[21] = {{"south", 22}};
	roomDirections[22] = {{"north", 21}, {"south", 2}};
	roomDirections[23] = {{"north", 24}, {"south", 0}};
	roomDirections[24] = {{"south", 23}};

	//^^ which directions we can move from when we’re in a certain room, and the room that it’ll take us to defined by the index in the vector

	std::string characterChoice;
	Weapon soldierDefault("Rifle", 7);
	Soldier soldier(&soldierDefault);
	Weapon engineerDefault("Wrench", 5);
	Engineer engineer(&engineerDefault);
	Weapon biologistDefault("Syringe", 4);
	Biologist biologist(&biologistDefault);


	while(true) {
		std::cout << "\n\nChoose your class…\n\n1. Soldier:\nHP: 120\nAttack: 7\nDefense: 5\nDifficulty: Easy\n\n2. Engineer:\nHP: 100\nAttack: 5\nDefense: 4\nDifficulty: Medium\n\n3. Biologist:\nHP: 80\nAttack: 4\nDefense: 3\nDifficulty: Hard\n\n";
		std:: cin >> characterChoice;
		if(characterChoice == "1" || characterChoice == "soldier" || characterChoice == "Soldier") {
			protagonist = &soldier;
			break;
		}
		else if(characterChoice == "2" || characterChoice == "engineer" || characterChoice == "Engineer") {
			protagonist = &engineer;
			break;
		}
		else if(characterChoice == "3" || characterChoice == "biologist" || characterChoice == "Biologist") {
			protagonist = &biologist;
			break;
		}
		else {
			std:: cout << "\n\nInvalid option for class, type carefully!\n\n";
		}
	}
	
	std::cout << "\n\nYou wake up in a room…blah blah idk youssef writes better lore than me this is a test\n\n";
	//Some lore things 
	int currentRoomIndex = 0;
	int nextRoomIndex;
	Environment* currentRoom = gameMap.getRoom(currentRoomIndex);
	//while loop will be our actual game loop
	std::string playerChoice;
	HelpItem realPills("Pills", 3, "health");
	HelpItem* pills = &realPills;

	protagonist->addToInventory(&engineerDefault);
	protagonist->addToInventory(pills);

	while(gameRunning) {		
		std::cout << "You are currently in the " << currentRoom->displayDescription() <<".\n\n";
	

		if(battleOccuring) {
			std::cout << "\n\nYou're now engaged in combat against the " << enemy->getEnemyType() << "!";
			std::string battleInput;
			std::string itemChoice;
			while(battleOccuring) {
				while(true) {
					std::cout << "\n\n";
					protagonist->printStatus();
					std::cout << "\nWhat will you do?\n1. Attack\n2. Use Item\n\n";
					cin >> battleInput;
					if(battleInput == "1" || battleInput == "attack" || battleInput == "Attack") {
						std::cout << "\n\n";
						enemy->takeDamage(battle.attack(enemy, protagonist));
						std::cout << "\n\n";
						enemy->printStatus();
						std::cout << "\n";
						break;
					}
					else if(battleInput == "2" || battleInput == "Item" || battleInput == "item") {
						if(protagonist->showCurrNumItems() == 0) {
							std::cout << "\n\nNothing in your inventory... in that case you should attack.\n\n";
							continue;
						}
						std::cout << "\n\nUse which item?\n\n";
						protagonist->showInventory();
						std::cin >> itemChoice;
						if(!protagonist->itemInInventory(itemChoice)) {
							std::cout << "\n\nYou don't have that item….\n\n";
						}
						Item* item = protagonist->getItemFromInventory(itemChoice);
						battle.useItem(item, protagonist);
						break; 
					} 	
					else std::cout << "\n\nNot a valid move! Do a real move, cmon now!\n\n";
				}
				if(enemy->isAlive()) {
					std::cout << "\n\n";
					battle.defend(protagonist, enemy->dealDamage());
					std::cout << "\n\n"; 
				}		
				if(!protagonist->isAlive()) {
					std::cout << "You fall to your knees, and you feel your strength fading away. \"Not like this…\"\n\n";
					std::cout << "You've lost the game! Restart the program to give it another try, you'll be able to load a save file coming soon!\n\nThanks for playing!\n\n";
					mainMenu.quit();
				}
				if(!enemy->isAlive()) {
					std::cout << "You have won this battle!\n\n";
					battleOccuring = false;
				}
			}
		}
		
		std::cout << "1. Move Rooms\n2. Pick Up Item\n3. Basar\n4. Look for Page\n5. Player Status\n6. Check Inventory\n\n";

		std::cin >> playerChoice;

		if(playerChoice == "1"|| playerChoice == "Move" || playerChoice == "move") {
			std::string direction;
			while(true){
				std::cout << "\n\nChoose a direction:\n1.North\n2.South\n3.East\n4.West\n\n";
				std::cin >> direction;
				if(direction == "1" || direction == "north" || direction == "North") {
					direction = "north";
				}
				else if(direction == "2" || direction == "south" || direction == "South") {
					direction = "south";
				}
				else if(direction == "3" || direction == "east" || direction == "East") {
					direction = "east";
				}
				else if(direction == "4" || direction == "west" || direction == "West") {
					direction = "west";
				}
				else {
					std::cout << "\n\nInvalid input, choose a proper direction man!";
					continue;
				}
				if(roomDirections[currentRoomIndex].find(direction) != roomDirections[currentRoomIndex].end()) {
					nextRoomIndex = roomDirections[currentRoomIndex][direction];
					if(gameMap.canMove(currentRoomIndex, nextRoomIndex)) {
						currentRoomIndex = nextRoomIndex;
						currentRoom = gameMap.getRoom(currentRoomIndex);
						std::cout << "\nI move to the " << currentRoom->displayDescription() << "\n\n";
						break;
					}
				}
				else {
					std::cout << "\n\nI can't go that way, just a wall.";
					continue;
				}

			}
		} 
		else if(playerChoice == "2" || playerChoice == "Item" || playerChoice == "item") {
			
		}
		else if(playerChoice == "3" || playerChoice == "Basar" || playerChoice == "page") {
			basar.outputBasarScreen();
		}
		else if(playerChoice == "4" || playerChoice == "Page" || playerChoice == "page") {
	
		}
		else if(playerChoice == "5" || playerChoice =="Status" || playerChoice == "status") {
			std::cout << "\n\n";
			protagonist->printStatus();
			std::cout << "\n\n";
		}
		else if(playerChoice == "6" || playerChoice =="inventory" || playerChoice == "Inventory") {
			if(protagonist->showCurrNumItems() == 0) {
				cout << "\n\nYou currently have nothing in your inventory\n\n";
				continue;
			}
			else {
				while(true){
					std::cout << "\n\n";
					protagonist->showInventory();
					std::cout<<"\n\nDo you want to use an item?\n\n1.Yes \n2.No\n\n";
					std::cin >> playerChoice;
					if(playerChoice == "1" || playerChoice == "Yes" || playerChoice == "yes") {
						std::cout << "\n\nType the name of the item you wish to use (case sensitive)\n\n >> ";
						std::cin >> playerChoice;
						if(protagonist->itemInInventory(playerChoice)) {
							Item* itemToUse = protagonist->getItemFromInventory(playerChoice);
							if(itemToUse->getType() != "weapon") {
							battle.useItem(itemToUse, protagonist);
							break;	
							}
							else {
								std::cout << "\n";
								protagonist->addToInventory(protagonist->getWeapon());
								protagonist->setWeapon(itemToUse);
								protagonist->setAttack(itemToUse); 
								std::cout << itemToUse->getName() << " has been equipped.\n" << itemToUse->getName() << " deals " << itemToUse->getValue() << " damage.\n\n";
								protagonist->removeFromInventory(itemToUse);
								std::cout << "\n\n";
								break;
							}
						}
						else {
							std::cout << "\n\nNot a valid item in inventory, try again (CASE SENSITIVE).";
						}
					}
					else if(playerChoice == "2" || playerChoice == "No" || playerChoice == "no") {
						std::cout << "\n\n";
						break;
					}
					else {
						std::cout <<"\n\nInvalid input. Choose one of the options given\n\n";
					}	
				}
			}
			
		}
		else {
			std::cout << "\n\nInvalid input. Choose one of the options given\n\n";
			continue;
		}

	}	
	
}

	/*	cin >> ;
		while(cin.fail()){ //input check loop
    		cin.clear();
    		cin.ignore();
    		cin >> ;
		} */