#pragma once

#include<chrono>

namespace Utils{

class TimeUtils{
    public:
    TimeUtils();
    ~TimeUtils();
    double get_duration(void);

    private:
    std::chrono::high_resolution_clock::time_point t_;
};

TimeUtils::TimeUtils(){
    t_=std::chrono::high_resolution_clock::now();
}

TimeUtils::~TimeUtils(){};

double TimeUtils::get_duration(void){
    auto t2 = std::chrono::high_resolution_clock::now();
    // std::ratio 接受两个模板参数，分别代表分子和分母，这两个参数在编译时会被除以它们的最大公约数来得到一个最简分数。
    // 在实际应用中，std::ratio 可以用于定义各种计量单位之间的转换比率，例如长度单位米和千米之间的转换，或者时间单位秒和毫秒之间的转换。
    // 当分子和分母相等时，它表示的是1:1的关系，即没有转换或者说转换比率为1。
    std::chrono::duration<double, std::ratio<1, 1>> d(t2 - t_);
    return d.count();
}

}