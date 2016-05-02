//
//  UserModel.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/28.
//
//

#ifndef UserModel_h
#define UserModel_h

namespace CatFootPrint
{
    class UserModel
    {
    public:
        UserModel() {};
        ~UserModel() {};
    public:
        void setCurrentScore(int score);
        void toggleSoundState();
        bool isSoundOpend();
        bool isBeginner();
        int getBestScore();
    private:
        int _score = 0;
    };
}

#endif /* UserModel_h */
