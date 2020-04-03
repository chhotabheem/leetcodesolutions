//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

#include <algorithm>
#include <vector>
using namespace std;
struct BitInfo
{
    int m_num;
    int m_bit_count;
    BitInfo(int num, int bit_count)
    {
        m_num = num;
        m_bit_count = bit_count;
    }
};

bool bit_compare(const BitInfo &first, const BitInfo &sec)
{
    if (first.m_bit_count > sec.m_bit_count)
    {
        return false;
    }
    if (first.m_bit_count < sec.m_bit_count)
    {
        return true;
    }
    if (first.m_num > sec.m_num)
    {
        return false;
    }
    return true;
}

class Solution
{
public:
    int getNumOfSetBits(int n)
    {
        int bit_count = 0;
        while (n)
        {
            if (n & 1)
            {
                ++bit_count;
            }

            n = n >> 1;
        }
        return bit_count;
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<int> result;
        vector<BitInfo> bitinfo_vec;
        for (const auto &n : arr)
        {
            int bit_count = getNumOfSetBits(n);
            BitInfo bit_info(n, bit_count);
            bitinfo_vec.emplace_back(bit_info);
        }

        sort(bitinfo_vec.begin(), bitinfo_vec.end(), bit_compare);
        for (const auto &bit_info : bitinfo_vec)
        {
            result.emplace_back(bit_info.m_num);
        }
        return result;
    }
};
