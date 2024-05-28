namespace GamesLibrary{
    class Games {
    private:
        bool checkForZero(int (*table)[3]);
        int checkForWin(int (*table)[3]);
        int minimax(int (&table)[3][3], int depth, bool isMax);
        void move(int (&table)[3][3], int player);
        void drawTable(int (*table)[3]);
    public:
        void TicTacToe();
        void RockPaperScissor();
    };
}