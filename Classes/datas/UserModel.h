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
        bool isSoundOpend();
        bool isBeginner();
        int getBestScore();
    };
}

#endif /* UserModel_h */
