# dÆRA
 
_Developed by:_ [Sydney Hilton](https://github.com/Sydnyepie), [Youssef Adam](https://github.com/atxm), [Jason Lee](https://github.com/jalee314), [Mario Koa Miranda](https://github.com/KoaMiranda)  

## Project Description
 > **_Maneuver your way through the chaos of al-Dæra, an Egyptian space station left in disarray after an unidentified organism breaches containment._**

The developers all share the desire to develop a compelling and immersive narrative where _you_ choose your story.  
The player can interact with a variety of aspects—including the assistant that helps them navigate the station—through various input options.
This project provides a science-fiction horror experience in the form of a text-based roleplaying video game.  
It is being developed via the language C++.

| Input                                                                        | Output                                                                                      |
| :--------------------------------------------------------------------------: |    :-----------------------------------------------------------------------------------:    |
| Player is given options regarding character classes and can choose           | Player is sent straight into the game to be able to play                                    |
| Player makes choice based on options given                                   | Terminal outputs pre-determined text for the given choice                                   |
| Player chooses to check on current stats and information about character     | Terminal outputs health and current weapon of the player character		             |
| Player encounters enemies and engages in combat                              | Terminal prints either a victory or defeat screen depending on the situation                |
| Player finds an item in a given room in the game                             | Item is added to the player's inventory for later use exploring the world or while in combat|
| Player chooses to drop item from inventory                                   | Item is removed from player inventory and the result is outputted in the terminal           |
| Player chooses to traverse the map                                           | Terminal outputs movement options, and whether or not they are valid.                       |
| Player interacts with **Basar** to read the journal     | **Basar** outputs a page upon user request and selection                                                 |
| Player equips items found during the game                                    | Player stats are changed and shown to the player in the terminal                            |
| Player looks inside journal item                                             | Terminal outputs hints on what needs to be done next, and expands on the lore of the story  |
| Player asks for a description of current room                                | Terminal returns a brief description and expands upon the lore of the game                  |


A [project board](https://github.com/orgs/cs100/projects/314/views/1) has been set up to streamline the development process.
## User Interface Specification
### Navigation Diagram
```mermaid
graph TD
    n1((Main Menu))
    n2([Character Class Screen])
    n3([Game Screen])
    n4([Inventory Screen])
    n5([<i>Basar</i> Screen])
    n6([Battle Screen])
    n7([Victory Screen])
    n8([Lose Screen])
    n1-->n2
    n2-- Start Game -->n3
    n3-->n4
    n3-->n5
    n4-- Equip/trash item -->n4
    n5-- Prompt/exit <i>Basar</i> -->n5
    n3-- Encounter enemy -->n6
    n6-- Win battle -->n7
    n6-- Lose battle -->n8
    n7-->n3
    n8-- Back to Main Menu -->n1
```
Our navigation diagram shows all the options the players have once in the game. All users will start at the main menu, from which they will have the option to start a new game or exit. At that point, the user will have options to open an inventory menu or open a menu to interact with Basar. The user will also randomly encounter enemies, from which they can either win or lose the battle.

### Screen Layouts
![Picture of Screen Layouts](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/Screen_Layout.png) <br/>
This chart detailing expected user interface layouts is present above. Users can expect to see a main menu upon executable launch and, when starting a new game, a description of the in-universe lore before prompted to create their character. After this, the game begins and the program will provide the user with information regarding what they can do to progress.

## Class Diagram
```mermaid
%%{
  init: {
    "fontFamily": "monospace",
    "classDiagram": {
      "curve": "linear"
    }
  }
}%%

classDiagram
direction RL
class mainMenu {
    +output()void
    +saveGame()void
    +getSave()void
    +exit()void
    +selectCharacter()void
}

class Entity {
    #health : int 
    #attack : int 
    #defense : int
    +printStatus()void
}
<<abstract>> Entity

class Soldier {
    +buffAttack()void
}

class Engineer {
    +buffDefense()void
}

class Biologist {
    +buffHealth()void
}
class playerActions {
    +walkForward()void
	+walkBackwards()void
	+walkRight()void
	+walkLeft()void
	+heal()void
	+openJournal()void
	+talktoBasar()void
}
<<friend>> playerActions

playerActions<..Room
class Room {
    -hasItem : bool
    -clearance : unsigned int
    -lightLevel : int
    +getItem()Item
}

class battleActions {
	+attack(Enemy*, PlayerCharacter*) : const int
	+defend(PlayerCharacter*, int) : void
	+useItem(HelpItem, PlayerCharacter*) : void
}
<<friend>> battleActions

class Basar {
    -playerAffinity : int
    -userJournal : Journal
    +basarOutput()void
}
Journal --* Basar

class Journal {
    -pages : vector~Page~ 
    +printPages(int)void
}

class Page {
    -pageWords : string
    +printPage()void
}
Page --* Journal

playerActions..>PlayerCharacter
battleActions..>PlayerCharacter
Basar --* PlayerCharacter
Soldier--|>PlayerCharacter
Engineer--|>PlayerCharacter
Biologist--|>PlayerCharacter
Inventory --* PlayerCharacter
class Inventory { 
    - vector~Item~ backpack
    - int carryCap
    - int currSize
    + displayInventory()void
    + addItem(Item)void
    + removeItem(Item)void
}

class NPC {
    -responses : vector~string~ 
	-askableQuestions : vector~string~ 
	-name : string 
	+printResponse(int)void
	+printName()void
	+addQuestion(string)void
	+addResponse(string)void
}

class PlayerCharacter {
    -difficulty : string 
    -basar : Basar 
    -userInventory : Inventory 
}
<<abstract>> PlayerCharacter

class Enemy {
    -evasion : int
    -accuracy : int
    +dealDamage()int
    +takeDamage(int)void
    +getHealth()int
    +getAttack()int
    +setHealth(int)void
    +setEvasion(int)void
    +setAccuracy(int)void
    +evadeAttack()bool
    +attackHits()bool
    +isAlive()bool
	
}
<<abstract>> Enemy

Rat--|>Enemy
Terrorist--|>Enemy
Crewmate--|>Enemy
Alien--|>Enemy

class Item {
    -assistance : int
    -name : string
    +getAssistance()int
    +useItem()int
    +printItem()void*
}

class HelpItem {
    +useHelpItem()void
    +printItem()void
}

class Weapon { 
    -damage : int
}

Item --o Inventory
PlayerCharacter--|>Entity
Enemy--|>Entity

Weapon--|>Item
HelpItem--|>Item
```

## Updated Class Diagram

```mermaid
%%{
  init: {
    "fontFamily": "monospace",
    "classDiagram": {
      "curve": "linear"
    }
  }
}%%

classDiagram
direction LR
class MainMenu {
    +output()void
    +quit()void
}

class Entity {
    #health : int 
    #attack : int 
    #defense : int
    +printStatus()void
    +isAlive()bool
}
<<abstract>> Entity

class Soldier {
    +buffStat()void
}

class Engineer {
    +buffStat()void
}

class Biologist {
    +buffStat()void
}


Lab --|> Environment
Hallway--|>Environment
class Environment {
    -items : vector~Item*~
    -description : string
    +displayDescription()void
    +addItem(Item)void
    +takeItem(Item*, PlayerCharacter&)bool
    +displayItems()void
    +getNumberItems()size_t
}
<<abstract>> Environment

class Map {
    -vector~Environment~ rooms
    +canMove()bool
    +connectTo(Environment*, Environment*)void
    +getLocation()Environment
}

Environment --* Map

Hallway .. playerActions
Lab .. playerActions

class battleActions {
	+attack(Enemy*, PlayerCharacter*)const int
	+defend(PlayerCharacter*, int)void
	+useItem(HelpItem, PlayerCharacter*)void
}
<<friend>> battleActions

class Basar {
    -playerAffinity : int
    -userJournal : Journal
    +basarOutput()void
}
Journal --* Basar

class Journal {
    -pages : vector~Page~ 
    +printPage(int)void
}

class Page {
    -pageWords : string
    +printPage()void
}
Page --* Journal

playerActions..>PlayerCharacter
battleActions..>PlayerCharacter
Basar --* PlayerCharacter
Soldier--|>PlayerCharacter
Engineer--|>PlayerCharacter
Biologist--|>PlayerCharacter

class IAdjustInventory {
    +addItem(Item*)void
    +removeItem(Item*)void
}
<<interface>> IAdjustInventory

class IDisplayInventory {
    +displayInventory()void
    +getNumItems()size_t
}
<<interface>> IDisplayInventory

class InventoryManagement { 
    - backpack : vector~Item*~ 
    - carryCap : int
    +getBackpack()vector~Item*~
}

class InventoryDisplay {
    - inventory : InventoryManagement&
}

InventoryDisplay --* PlayerCharacter
InventoryManagement --* PlayerCharacter
InventoryDisplay --o InventoryManagement
InventoryManagement--|>IAdjustInventory
InventoryDisplay--|>IDisplayInventory

class PlayerCharacter {
    -difficulty : string
    -inventory : InventoryManagement
    -inventoryDisplay : InventoryDisplay
    -weapon : Item*
    +printStatus()void
    +getDifficulty()string
    +getHealth()int
    +getAttack()int
    +getDefense()int
    +setAttack(Item* weapon)void
    +getWeapon()Item*
    +setWeapon()void
    +addToInventory(Item* item);
    +removeFromInventory(Item* item)void
    +itemInInventory(const string& item)bool
    +getItemFromInventory(string& item)Item*
    +showInventory()void
    +showCurrNumItems()size_t
}

class IEnemyState {
    +getHealth()int
    +getAttack()int
    +getEvasion()int
    +getAccuracy()int
    +getEnemyType()string
    +setHealth(int)void
    +setEvasion(int)void
    +setAccuracy(int)void
    +printStatus()void
}
<<interface>> IEnemyState

class IEnemyCombatActions {
    +takeDamage(int) int
    +dealDamage() int
    +evadeAttack() bool
    +attackHits() bool
    +isAlive() bool
}
<<interface>> IEnemyCombatActions

Enemy--|>IEnemyState
Enemy--|>IEnemyCombatActions

class INPCPrint {
    +printName() void 
    +printResponse()void 
}
<<interface>> INPCPrint

class INPCInteraction {
    +addQuestion(string)void 
    +addResponse(string)void
    +getQuestionsSize()int
    +getResponsesSize()int
    +getResponse(int)string
}
<<interface>> INPCInteraction

class NPCQuestionManager {
    -responses : vector~string~ 
    -askableQuestions : vector~string~ 
	-name : string 
}

class NPCPrinter {
    -name : string
    -questionManager& : NPCQuestionManager
}

NPCQuestionManager --|> INPCInteraction
NPCPrinter --|> INPCPrint
NPCQuestionManager --o NPCPrinter

class Enemy {
    -evasion : int
    -accuracy : int
}
<<abstract>> Enemy

Rat--|>Enemy
Terrorist--|>Enemy
Crewmate--|>Enemy
Alien--|>Enemy

class Item {
    #name : string
    +useItem()int
    +printItem()void
    +getValue()int
    +getType()string
}

<<abstract>> Item

class HelpItem {
    -type : string
    -assistance : int
}

class Weapon {
    -damage : int
}

Item --o InventoryManagement
PlayerCharacter--|>Entity
Enemy--|>Entity

HelpItem--|>Item
Weapon--|>Item
```

The game starts off with the `MainMenu` class that allows the user to start their game, whether it be from a save file or from the start which involves difficulty selection. This is also the class that allows for exiting and saving.

The primary class in this game is the `Entity` class which contains the `health`, `attack`, and `defense` private members as well as the `printStatus()` function. This class acts as a parent for the subclasses of `Enemy` and `PlayerCharacter` which, along with this class, are both abstract classes.

The `PlayerCharacter` class has the 3 options for the character type (i.e., `Soldier`, `Engineer`, and `Biologist`) as subclasses. This class (as well as its derived forms) now introduce the `difficulty`, `Inventory`, and `Basar` private member variables.

The `PlayerCharacter` class includes the mention of an `Inventory` class which keeps track of all of the items in the inventory including the capacity and current size. This class has functions that allow the user to add items, remove items, and display the inventory.

The `Inventory` class also includes members of the `Item` class which includes `assistance` (i.e., the number of damage added or health gained) and the name of the `Item`. This class also includes the pure virtual function that prints the item, grabs the assistance amount, and uses the item. Its derived classes include the `Weapon` and `HelpItem` classes which have the implementation of the functions `printItem()` and `useItem()` and `damage()` member functions respectively.

The `PlayerCharacter` class also makes use of the `Basar` class, the latter being compositionally related to the former in that the user will have access to this particular object that serves as both a fictional AI assistant with hard-coded dialogue options and responses (dependent on the `playerAffinity` which is, in turn, dependent on the dialogue options the user chooses) and as the accessor for the player’s journal, as implemented in the `Journal` class.

The `Journal` class is made of a vector of `Page` objects, the latter class also being compositionally related due to its only implementation as a member variable for the former. `Journal` also possesses a `printPage(int)` function that will make use of the `printPage()` function in the `Page` class.

As a friend to the `PlayerCharacter` class, the `battleActions` class controls any of the combat actions the player can take like doing damage, defending, or using an item.

Similarly, the `playerActions` class is another friend of the `PlayerCharacter` class that allows the user to move around (left, right, back, or forward), heal, or make use of Basar (i.e., access the journal and/or speak with the AI assistant itself).

The `NPC` class includes all the NPC-specific list of responses, NPC name, and list of questions the NPC will answer. This class has functions that allow one to print the NPC's name and response as well as add new questions and responses for the NPC to answer to or ask.

Finally is the `Enemy` class derived from the `Entity` class that contains the subclasses of our common enemies of `Rat`, `Terrorist`, `Crewmate`, and `Alien` classes. All of these classes include a `health`, `attack`, `accuracy`, and `evasion` stat on top of a `dealDamage()`, `takeDamage(int)`, and `printStatus()` function. In this class, the `printStatus()` function just prints the enemy’s current health. As for the `dealDamage()` and `takeDamage(int)` functions, these deal with how much damage the enemy does and how much damage the enemy takes respectively.
The `Environment` is an abstract class that handles the locations that the player will move through during the game. It contains a description `string`, vector of `Item` objects, and methods to list and take items from the `Environment`. Classes like `Hallway`, `Lab`, and others will inherit from `Environment` and implement methods specific to those rooms.

The `Map` class contains all the `Environment`-child classes and arranges them into a map that the player will move through. The `Map` class contains a vector of `Environment` objects and an adjacency matrix that handles the connections between the rooms. The methods include `canMove()` which deduces whether the player made a valid movement command, a `connectTo()` method that creates connections or "doors" between rooms, and `getLocation()` which returns the room the player is currently in.  

# SOLID Principles added

{Sydney}
One update we made to our class diagram was the change to conform to the Open-Closed Principle was the creation of our Entity class. This creation for this class allowed for more entities able to be created in case we wanted to expand our game. This means our code was improved by allowing for easier scalability.
</br>
Another change we made to our class diagram was the change meant to apply the Single responsibility principle. Our change was removing the changeWeapon function from the Weapon class and instead letting that be managed outside of the class. This allowed for our code to require less changes and less work needing to be done for every Weapon object made throughout the game.
</br>
</br>
{Jason}
</br>
Within my inventory class, I implemented SRP and ISP. Originally, I had one single Inventory classes handling all the responsibilities of my inventory. I split my Inventory class into two classes, InventoryManagement and InventoryDisplay, inventorymanagement controls the responsibility of adding and removing items, and inventoryDisplay controls the responsibility of actually displaying the inventory. They inherit from an AdjustInventory interface and a DisplayInventory interface respectively.  This change helped me make my inventory more scalable and flexible; if I ever make a change to my inventory management logic, I know that it won’t affect my inventory display logic. 

</br>

I also have an item class in which I implemented ISP, and LSP.  I have an abstract item class, with a derived helpItem class and Weapon class. helpItem has an assistance private member that would basically do something to the player character, which the weapon doesn’t have, so I used an interface and inherited that into my helpItem class so that I don’t have weapon with a getAssistance function that doesn’t do anything. Also, I made sure that my derived classes have the same functionality when replacing any instances of item in the code, such as in the inventory class. It also kind of follows SRP, I didn’t see the need to split the Item class up into multiple classes, cause I thought the methods all referred to the functionality of the items. These changes helped me write better code by making it cleaner and more maintainable, and makes sure that expected behavior is preserved across any subclass instances. 

</br>

I implemented SRP and ISP to my NPC class.  Like the inventory class, I originally had a single NPC class, and that got split up into NPCPrinter and NPCQuestionManager, both inheriting from a NPCPrint interface and NPCInteraction interface. NPCPrinter controls the output functions related to the NPC, and NPCQuestionManager controls the questions and response logic from our npcs. Like the inventory class, this made my NPC class a lot more scalable and flexible; If I make changes to one class, I can be confident that the other class won’t be messed with, and I’d be able to track errors a lot easier. The interfaces also made sure that each class only has things related to its role.

</br>
Lastly, I made changes to my Enemy Class, implementing SRP ISP and LSP. I separated my one Enemy class into three classes, EnemyBattle and EnemyStatus, EnemyBattle deals with chance events in combat and EnemyStatus deals with updating the stats of the enemy. I have three implemented interfaces, IEnemyState, IEnemyCombatChance, and IEnemyDamage. IEnemyState is used by EnemyStatus, IEnemyCombatChance is used by EnemyBattle, and IEnemyDamage is used directly by the subclasses that represent the actual enemies to fight. For LSP, all my different enemies that inherit from the Enemy class serve the same functionality and are interchangeable with any instances of an Enemy object within the code. The benefits that these changes are the added scalability and flexibility of course. If I plan on adding any more enemies in the future, these principles streamline that process and make sure each new class will follow the same fundamental interface.
</br>
</br>
{Mario}
</br>
To anticipate more types of rooms being added as we develop our story, I decided to change the Environment class to an abstract class. Originally my plan was to have a single "room" class that would simply change its description and functions depending on whether or not it was a lab or an escape pod etc. The player would need different options and items to interact with depending on the room they were in. But as I learned about the SOLID principles, particularly the Open-closed principle, I decided to make Environment an abstract class that would never need to be changed as more room types were added. Specifically, the methods inside Environment (like description, addItem, etc) apply to all future room types and won't need to be changed. And any number of new room types could be added without issue.



 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 <i>Numbers correlate to row number on the table on top of the readme file.<i></br></br>
 Input 1: </br>
 ![Picture of Input 1](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input1.png) </br>
 Output 1: </br>
 ![Picture of Output 1](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output1.png) </br>
 Input 2: </br>
 ![Picture of Input 2](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input2.png) </br>
 Output 2: </br>
 ![Picture of Output 2](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output2.png) </br>
 Input 3: </br>
 ![Picture of Input 3](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input3.png) </br>
 Output 3: </br>
 ![Picture of Output 3](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output3.png) </br>
 Input 4: </br>
 ![Picture of Input 4](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input4.png) </br>
 Output 4a, victory: </br>
 ![Picture of Output 4a](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output4a.png) </br>
 Output 4b, defeat: </br>
 ![Picture of Output 4b](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output4b.png) </br>
 Input 5: </br>
 ![Picture of Input 5](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input5.png) </br>
 Output 5: </br>
 ![Picture of Output 5](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output5.png) </br>
 Input 6: </br>
 ![Picture of Input 6](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input6.png) </br>
 Output 6: </br>
 ![Picture of Output 6](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output6.png) </br>
 Input 7: </br>
 ![Picture of Input 7](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input7.png) </br>
 Output 7a, direction valid: </br>
 ![Picture of Output 7a](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output7a.png) </br>
 Output 7b, direction invalid: </br>
 ![Picture of Output 7b](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output7b.png) </br>
 Input 8: </br>
 ![Picture of Input 8](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input8.png) </br>
 Output 8: </br>
 ![Picture of Output 8](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output8.png) </br>
 Input 9: </br>
 ![Picture of Input 9](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input9.png) </br>
 Output 9: </br>
 ![Picture of Output 9](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output9.png) </br>
 Input 10: </br>
 ![Picture of Input 10](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input10.png) </br>
 Output 10: </br>
 ![Picture of Output 10](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output10.png) </br>
 Input 11: </br>
 ![Picture of Input 11](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/input11.png) </br>
 Output 11: </br>
 ![Picture of Output 11](https://github.com/cs100/final-project-jlee1667-yadam003-shilt003-mmira069/blob/master/img/output11.png) </br>
 
 ## Installation/Usage
Steps to run dÆRA
- Clone the online repository onto your local machine.
- First, type ```$ cmake .``` into your terminal.
- Next, type ```$ make``` into your terminal.
- Finally, type ```$ ./dAEra``` into your terminal.
- Enjoy your gaming experience!  
 ## Testing
All modules of our project were unit-tested using Google's Googletest submodules. In approaching this project, our group opted for a top-down testing approach, creating our large modules first and developing stubs for our smaller modules, and slowly worked our way down and ensured that our stubs and low-level modules gave the same result in our unit tests. After finishing a lower module, we immediately integrated the related classes and ensured that our test results were the same between the stubs and actual implementation.
