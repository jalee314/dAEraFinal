class EnemyStub{
    private:
        int attack;
        int evasion; 

    public:
        EnemyStub(int num, int num2): attack(num), evasion(num2){};

        int getEvasion() {return evasion;}
        int dealDamage();
};


class PlayerCharacterStub{
    private:
        int attack;
        int defense;
        int weaponDmg;

    public:
        PlayerCharacterStub(int num, int num2, int num3): attack(num), defense(num2), weaponDmg(num3){};
    
    friend class battleActions;
};


class battleActions{ //friend to playerCharacter class
    public:
        virtual int attack(EnemyStub, PlayerCharacterStub);
        //virtual int defend();
        //void useItem();
};