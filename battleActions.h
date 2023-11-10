class battleActions{ //friend to playerCharacter class
    public:
        virtual int attack();
        virtual int defend();
        void useItem();
}