class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.length() < 3) return false;
        int alice = 0;
        int bob = 0;
        for(int i = 0; i < colors.length()-2; i++)
        {
            if(colors[i] == 'A' && colors[i+1] == 'A' && colors[i+2] == 'A')
            {
                alice++;
            }
            if(colors[i] == 'B' && colors[i+1] == 'B' && colors[i+2] == 'B')
            {
                bob++;
            }
        }
        bool alice_turn = true;
        while(alice || bob)
        {
            if(alice_turn && alice)
            {
                alice--;
                alice_turn = false;
            }
            else if(alice_turn && alice == 0)
            {
                return false;
            }
            else if(alice_turn == false && bob)
            {
                bob--;
                alice_turn = true;
            }
            else if(alice_turn == false && bob == 0)
            {
                return true;
            }
        }
        if(alice_turn && alice == 0) return false;
        else return true;
    }
};