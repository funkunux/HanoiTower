// HanoiTower.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

class HanoiTower
{
private:
    uint16_t totalLevel = 0;
    const char* pillarName[3] = { "A", "B", "C" };
    enum Pillar
    {
        A = 0,
        B,
        C
    };
    int howToMove(uint16_t level, Pillar from, Pillar to, Pillar by)
    {
        if (level == 1)
        {
            showStep(from, to);
            return 1;
        }
        int stepCount = 0;
        if (level > 1)
        {
            stepCount += howToMove(level - 1, from, by, to);
            stepCount += howToMove(1, from, to, by);
            return stepCount + howToMove(level - 1, by, to, from);
        }
        return 0;
    }

    void showStep(Pillar from, Pillar to)
    {
        std::cout << pillarName[from] << "->" << pillarName[to] << std::endl;
    }
public:
    HanoiTower(uint16_t level)
        : totalLevel(level) {}
    int showSteps()
    {
        return howToMove(totalLevel, A, B, C);
    }
};

int main()
{
    HanoiTower t(4);
    int steps = t.showSteps();
    std::cout << "Total steps: " << steps << std::endl;
    return 0;
}
