#ifndef __INPUT_H__
#define __INPUT_H__
#include <string>
#include <vector>

class Input {
public:
    Input(std::string filename);
    std::string GetMapString() { return _mapstring; }
private:
    int _T;
    int _N;
    bool _bh2;
    int _upper_limit;
    std::string _mapstring;
    std::vector<int> _monster_data;
};

int processLineNumber(int line_nubmer);
#endif
