class battleActions{ //friend to playerCharacter class
    public:
        virtual int attack(EnemyStub);
        //virtual int defend();
        //void useItem();
};


class PlayerCharacterStub{
    private:
        int attack;
        int defense;
        int weaponDmg;

    public:
    
    friend class battleActions;
};


class EnemyStub{
    private:
        int attack;
        int evasion; 

    public:
        int getEvasion() {return evasion;}
        int dealDamage();
};