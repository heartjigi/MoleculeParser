#include "../header/MoleculeParser.h"

//initializer
MoleculeParser::MoleculeParser() {
    mName = "";
}
MoleculeParser::MoleculeParser(string name){
    mName = name;
}

//method
map<string, int> MoleculeParser::parse() {
    int nNum = 1;
    string sName = "";
    map<string, int> mRoundMulti;
    map<string, int> mSquareMulti;
    map<string, int> mResult;
    map<string, int>::iterator iter;

    int roundFlag = 0;
    int squareFlag = 0;
    
    for (int i = 0; i < mName.length(); i++) {

        if (sName != "" && (mName[i] >= 'A' && mName[i] <= 'Z')) {
            if (roundFlag == 2) {
                if (!mRoundMulti.insert(pair<string, int>(sName, nNum)).second) {
                    mRoundMulti[sName] += nNum;
                }
            } else if (squareFlag == 2) {
                if (!mSquareMulti.insert(pair<string, int>(sName, nNum)).second) {
                    mSquareMulti[sName] += nNum;
                }
            }  else {
                if (!mResult.insert(pair<string, int>(sName, nNum)).second) {
                    mResult[sName] += nNum;
                }
            }
            sName = "";
            nNum = 1;
        }

        if (roundFlag == 0 && mRoundMulti.size() != 0) {

            for (iter = mRoundMulti.begin(); iter != mRoundMulti.end(); ++iter) {
                string name = (*iter).first;
                int num = (*iter).second;
                
                if (squareFlag == 2) {
                    if (!mSquareMulti.insert(pair<string, int>(name, num * nNum)).second) {
                        mSquareMulti[name] += num * nNum;
                    }
                } else {
                    if (!mResult.insert(pair<string, int>(name, num * nNum)).second) {
                        mResult[name] += num * nNum;
                    }
                }
            }
            mRoundMulti.clear();
        }
        
        if (squareFlag == 0 && mSquareMulti.size() != 0) {
            for (iter = mSquareMulti.begin(); iter != mSquareMulti.end(); ++iter) {
                string name = (*iter).first;
                int num = (*iter).second;
                if (!mResult.insert(pair<string, int>(name, num * nNum)).second){
                    mResult[name] += num * nNum;
                }
            }
            mSquareMulti.clear();
        }
        
        if (roundFlag == -1 || roundFlag == 1) roundFlag++;
        if (squareFlag == -1 || squareFlag == 1) squareFlag++;
        if ((mName[i] >= 'A' && mName[i] <= 'Z') || (mName[i] >= 'a' && mName[i] <= 'z')) {
            sName += mName[i];
            if (i != mName.length() - 1 ) {
                if (mName[i+1] >= 'a' && mName[i+1] <= 'z') {
                    sName += mName[i+1];
                    i++;
                }
            }
        } else {
            if (mName[i] >= '0' && mName[i] <= '9') {
                nNum = 0;
                while ((mName[i] >= '0' && mName[i] <= '9') && (i <= mName.length() - 1 )) {
                    nNum *= 10;
                    nNum = mName[i] - '0';
                    i++;
                }
                i--;
            } else if (mName[i] == '[') {
                squareFlag = 1;
            } else if (mName[i] == '(') {
                roundFlag = 1;
            } else if (mName[i] == ']') {
                squareFlag = -1;
                if(sName != "") {
                    if (!mSquareMulti.insert(pair<string, int>(sName, nNum)).second) {
                        mSquareMulti[sName] += nNum;
                    }
                    
                    sName = "";
                    nNum = 0;
                }
            } else if (mName[i] == ')') {
                roundFlag = -1;
                if(sName != "") {
                    if (!mRoundMulti.insert(pair<string, int>(sName, nNum)).second) {
                        mRoundMulti[sName] += nNum;
                    }
                    sName = "";
                    nNum = 0;
                }
            }
        }
    }

    if(sName != "") {
        if (!mResult.insert(pair<string, int>(sName, nNum)).second) {
            mResult[sName] += nNum;
        }
    }
    if (mRoundMulti.size() != 0) {
        for (iter = mRoundMulti.begin(); iter != mRoundMulti.end(); ++iter) {
            string name = (*iter).first;
            int num = (*iter).second;
            if (squareFlag) {
                if (!mSquareMulti.insert(pair<string, int>(name, num * nNum)).second) {
                    mSquareMulti[name] += num * nNum;
                }
            } else {
                if (!mResult.insert(pair<string, int>(name, num * nNum)).second) {
                    mResult[name] += num * nNum;
                }
            }
        }
        mRoundMulti.clear();
    }
    
    if (mSquareMulti.size() != 0) {
        for (iter = mSquareMulti.begin(); iter != mSquareMulti.end(); ++iter) {
            string name = (*iter).first;
            int num = (*iter).second;
            if (!mResult.insert(pair<string, int>(name, num * nNum)).second){
                mResult[name] += num * nNum;
            }
        }
        mSquareMulti.clear();
    }
    
    
    
    
    for (iter = mResult.begin(); iter != mResult.end(); ++iter) {
        cout<<(*iter).first<<": "<<(*iter).second<<", ";
    }
    cout<<endl;

    return mResult;
}
