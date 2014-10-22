#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
#define pi (acos(-1.0))
#define inf (1<<28)
using namespace std;

#define  LOCAL

bool is_runnian(int year)
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0) return true;
        return false;
    }
    else if (year % 4 == 0) return true;
    return false;
}
int m[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const float eps = 365.25 - 365.2425;

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("OnSiteF.in", "r", stdin);
    //freopen("OnSiteF.out", "w", stdout);
#endif

    int cha, start_year, start_month, start_day, ed_year, ed_month, ed_day;
    while (scanf("%d-%d-%d", &start_year, &start_month, &start_day) != EOF)
    {
        cha = eps * (start_year - 1582) + 11.5;
        ed_year = start_year;
        ed_month = start_month;
        ed_day = start_day + cha;
        if (start_month == 2 && !is_runnian(start_year) && ed_day > 28)
        {
            ed_month = 3;
            ed_day -= 28;
        }
        else if (start_month == 2 && is_runnian(start_year) && ed_day > 29)
        {
            ed_month = 3;
            ed_day -= 29;
        }
        else if (start_month != 2 && start_month != 12 && ed_day > m[start_month])
        {
            ed_month = start_month + 1;
            ed_day -= m[start_month];
        }
        else if (start_month == 12 && ed_day > 31)
        {
            ed_year = start_year + 1;
            ed_month = 1;
            ed_day -= 31;
        }
            printf("%d-%02d-%02d\n", ed_year, ed_month, ed_day);
    }
    return 0;
}