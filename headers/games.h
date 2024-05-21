namespace GamesLibrary{
    class Games {
    private:
        auto checkForZero(auto table, int rows, int cols);
        auto checkForWin(auto table, int rows, int cols);
        auto move(auto& table, int rows, int cols, int player);
        auto drawTable(auto table, int rows, int cols);
    public:
        void TicTacToe();
        void RockPaperScissor();
    };
}