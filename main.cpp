#include <iostream>
#include "CText.h"
#include "tchar_utils.h"
#include <regex>
#ifdef _WIN32
#pragma warning(disable : 4702)
#endif

bool V(wchar_t c)
{
    CText v;
    v.fromWide(L"ÀÅ¨ÈÎÓÛÝÞßàå¸èîóûýþÿ");
    return v.contain(c);
}

bool C(wchar_t c)
{
    CText v;
    v.fromWide(L"ÁÂÃÄÆÇÊËÌÍÏÐÑÒÔÕÖ×ØÙáâãäæçêëìíïðñòôõö÷øù");
    return v.contain(c);
}

bool S(wchar_t c)
{
    CText v;
    v.fromWide(L"Éé");
    return v.contain(c);
}

bool M(wchar_t c)
{
    CText v;
    v.fromWide(L"ÚÜúü");
    return v.contain(c);
}

bool BEG(wchar_t c)
{
    return c == L'[';
}

bool END(wchar_t c)
{
    return c == L']';
}

class Result
{
public:
    std::vector<CText> strs;
    int a;
    int b;
    Result(std::vector<CText> strs, int a, int b)
    {
        this->strs = strs;
        this->a = a;
        this->b = b;
    }
};


Result apply1(CText s)
{
    if (C(s[0]))
    {
        if (V(s[1]))
        {
            if (C(s[2]))
            {
                if (V(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1]}),CText({s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
                if (C(s[3]))
                {
                    if (V(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (C(s[4]))
                    {
                        if (C(s[5]))
                        {
                            if (END(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 1);
                                }
                            }
                            if (!END(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 1);
                                }
                            }
                        }
                        if (V(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (M(s[5]))
                        {
                            if (END(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 1);
                                }
                            }
                        }
                    }
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (M(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (C(s[5]))
                        {
                            if (V(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 1);
                                }
                            }
                        }
                        if (V(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                    }
                }
                if (END(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
                if (M(s[3]))
                {
                    if (C(s[4]))
                    {
                        if (!END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (C(s[5]))
                        {
                            if (C(s[6]))
                            {
                                if (END(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5],s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 1);
                                    }
                                }
                            }
                        }
                    }
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (V(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                }
            }
            if (END(s[2]))
            {
                {
                    std::vector<CText> v({ CText({s[0],s[1]}),CText({s[2]}) });
                    return Result(v, 3, 1);
                }
            }
            if (S(s[2]))
            {
                if (C(s[3]))
                {
                    if (V(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (C(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                    }
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (M(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                    }
                }
                if (END(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }

                {
                    std::vector<CText> v({ CText({s[0],s[1],s[2]}) });
                    return Result(v, 3, 1);
                }

            }
            if (V(s[2]))
            {
                {
                    std::vector<CText> v({ CText({s[0],s[1]}),CText({s[2]}) });
                    return Result(v, 3, 1);
                }
            }
        }
        if (C(s[1]))
        {
            if (C(s[2]))
            {
                if (V(s[3]))
                {
                    if (C(s[4]))
                    {
                        if (C(s[5]))
                        {
                            if (V(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 1);
                                }
                            }
                            if (M(s[6]))
                            {
                                if (END(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5],s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 1);
                                    }
                                }
                            }
                        }
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (V(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (M(s[5]))
                        {
                            if (C(s[6]))
                            {
                                if (M(s[7]))
                                {
                                    if (END(s[8]))
                                    {
                                        {
                                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5],s[6],s[7]}),CText({s[8]}) });
                                            return Result(v, 9, 1);
                                        }
                                    }
                                }
                            }

                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                    }
                    if (S(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (V(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }

                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
                if (C(s[3]))
                {
                    if (V(s[4]))
                    {
                        if (S(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }

                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                }
            }
            if (V(s[2]))
            {
                if (C(s[3]))
                {
                    if (C(s[4]))
                    {
                        if (V(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (C(s[5]))
                        {
                            if (C(s[6]))
                            {
                                if (END(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5],s[6]}),CText({s[7]}) });

                                        return Result(v, 8, 1);
                                    }
                                }
                            }

                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (M(s[5]))
                        {
                            if (V(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 1);
                                }
                            }
                            if (C(s[6]))
                            {
                                if (V(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 1);
                                    }
                                }
                            }
                        }
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                    }
                    if (M(s[4]))
                    {
                        if (!C(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (C(s[5]))
                        {
                            if (V(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 1);
                                }
                            }
                            if (C(s[6]))
                            {
                                if (V(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}),CText({s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 1);
                                    }
                                }
                            }
                        }
                    }
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (V(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                }
                if (V(s[3]))
                {
                    if (C(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }

                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
                if (S(s[3]))
                {
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (C(s[4]))
                    {
                        if (V(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (C(s[5]))
                        {
                            if (C(s[6]))
                            {
                                if (END(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5],s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 1);
                                    }
                                }
                            }
                        }
                    }

                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
                if (END(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
            }
            if (M(s[2]))
            {
                if (V(s[3]))
                {
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (C(s[4]))
                    {
                        if (V(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                    }
                }
            }
        }
        if (M(s[1]))
        {
            if (V(s[2]))
            {
                if (C(s[3]))
                {
                    if (V(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (C(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (V(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                        if (C(s[5]))
                        {
                            if (C(s[6]))
                            {
                                if (V(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 1);
                                    }
                                }
                            }
                        }
                    }
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                }
                if (END(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
            }
            if (C(s[2]))
            {
                if (V(s[3]))
                {
                    if (S(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                    }
                    if (V(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                }
            }
        }
    }
    if (V(s[0]))
    {
        if (C(s[1]))
        {
            if (C(s[2]))
            {
                if (END(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
                if (V(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1]}),CText({s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
                if (C(s[3]))
                {
                    if (V(s[4]))
                    {
                        if (C(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }

                        {
                            std::vector<CText> v({ CText({s[0],s[1]}),CText({s[2]}),CText({s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                    if (C(s[4]))
                    {
                        if (V(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                    }
                }
                if (M(s[3]))
                {
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                }
            }
            if (V(s[2]))
            {
                {
                    std::vector<CText> v({ CText({s[0]}),CText({s[1]}),CText({s[2]}) });
                    return Result(v, 3, 1);
                }
            }
            if (M(s[2]))
            {
                if (END(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
                if (C(s[3]))
                {
                    if (C(s[4]))
                    {
                        if (V(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}),CText({s[4]}),CText({s[5]}) });
                                return Result(v, 6, 1);
                            }
                        }
                    }
                    if (V(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}),CText({s[4]}) });
                            return Result(v, 5, 1);
                        }
                    }
                }
                if (V(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
            }
            if (END(s[2]))
            {
                {
                    std::vector<CText> v({ CText({s[0],s[1]}),CText({s[2]}) });
                    return Result(v, 3, 1);
                }
            }

            {
                std::vector<CText> v({ CText({s[0],s[1]}) });
                return Result(v, 2, 1);
            }
        }
        if (END(s[1]))
        {
            {
                std::vector<CText> v({ CText({s[0]}),CText({s[1]}) });
                return Result(v, 2, 1);
            }
        }
        if (V(s[1]))
        {
            {
                std::vector<CText> v({ CText({s[0]}),CText({s[1]}) });
                return Result(v, 2, 1);
            }
        }
        if (S(s[1]))
        {
            if (END(s[2]))
            {
                {
                    std::vector<CText> v({ CText({s[0],s[1]}),CText({s[2]}) });
                    return Result(v, 3, 1);
                }
            }
            if (C(s[2]))
            {
                if (V(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0],s[1]}),CText({s[2]}),CText({s[3]}) });
                        return Result(v, 4, 1);
                    }
                }
            }
        }
    }
    if (BEG(s[0]))
    {
        if (C(s[1]))
        {
            if (C(s[2]))
            {
                if (V(s[3]))
                {
                    if (C(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 2);
                            }
                        }
                        if (C(s[5]))
                        {
                            if (END(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 2);
                                }
                            }
                            if (M(s[6]))
                            {
                                if (END(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4],s[5],s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 2);
                                    }
                                }
                            }
                        }
                    }
                    if (S(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 2);
                            }
                        }
                    }
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 2);
                        }
                    }
                }
                if (END(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 2);
                    }
                }
                if (C(s[3]))
                {
                    if (C(s[4]))
                    {
                        if (V(s[5]))
                        {
                            if (C(s[6]))
                            {
                                if (END(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4],s[5],s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 2);
                                    }
                                }
                            }
                        }
                    }
                    if (V(s[4]))
                    {
                        if (C(s[5]))
                        {
                            if (M(s[6]))
                            {
                                if (END(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4],s[5],s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 2);
                                    }
                                }
                            }
                        }
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 2);
                            }
                        }
                    }
                }
            }
            if (V(s[2]))
            {
                if (C(s[3]))
                {
                    if (C(s[4]))
                    {
                        if (M(s[5]))
                        {
                            if (END(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 2);
                                }
                            }
                        }
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 2);
                            }
                        }
                    }
                    if (M(s[4]))
                    {
                        if (C(s[5]))
                        {
                            if (C(s[6]))
                            {
                                if (END(s[7]))
                                {
                                    {
                                        std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4],s[5],s[6]}),CText({s[7]}) });
                                        return Result(v, 8, 2);
                                    }
                                }
                            }
                        }
                    }
                }
                if (S(s[3]))
                {
                    if (C(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 2);
                            }
                        }
                    }
                }
            }
            if (END(s[2]))
            {
                {
                    std::vector<CText> v({ CText({s[0]}),CText({s[1]}),CText({s[2]}) });
                    return Result(v, 3, 2);
                }
            }
            if (M(s[2]))
            {
                if (C(s[3]))
                {
                    if (V(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 2);
                            }
                        }
                        if (C(s[5]))
                        {
                            if (END(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 2);
                                }
                            }
                            if (V(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4]}),CText({s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 2);
                                }
                            }
                        }
                    }
                }
                if (V(s[3]))
                {
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 2);
                        }
                    }
                    if (S(s[4]))
                    {
                        if (END(s[5]))
                        {
                            {
                                std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4]}),CText({s[5]}) });
                                return Result(v, 6, 2);
                            }
                        }
                    }
                    if (C(s[4]))
                    {
                        if (M(s[5]))
                        {
                            if (END(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 2);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (V(s[1]))
        {
            if (C(s[2]))
            {
                if (M(s[3]))
                {
                    if (END(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3]}),CText({s[4]}) });
                            return Result(v, 5, 2);
                        }
                    }
                }
                if (END(s[3]))
                {
                    {
                        std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2]}),CText({s[3]}) });
                        return Result(v, 4, 2);
                    }
                }
                if (C(s[3]))
                {
                    if (C(s[4]))
                    {
                        if (C(s[5]))
                        {
                            if (END(s[6]))
                            {
                                {
                                    std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2],s[3],s[4],s[5]}),CText({s[6]}) });
                                    return Result(v, 7, 2);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (S(s[1]))
        {
            if (V(s[2]))
            {
                if (C(s[3]))
                {
                    if (V(s[4]))
                    {
                        {
                            std::vector<CText> v({ CText({s[0]}),CText({s[1],s[2]}),CText({s[3]}),CText({s[4]}) });
                            return Result(v, 5, 2);
                        }
                    }
                }
            }
        }
    }

    std::vector<CText> v;
    return Result(v, 0, 0);
}

CText concat(std::vector<CText> src, int start)
{
    CText res;
    for (int i = start; i < src.size(); ++i)
    {
        res += src[i];
    }
    return res;
}

std::vector<CText> split(CText word)
{
    std::vector<CText> result;
    int pos = 0;
    int len = word.length();
    std::vector<CText> vec;

    for (int i = 0; i < word.length(); ++i)
    {
        vec.push_back(word.str()[i]);
    }

    while (1)
    {
        CText input_context = concat(vec, pos);
        if (input_context.isEmpty())
        {
            break;
        }
        Result r = apply1(input_context);
        if (r.strs.size() == 0)
        {
            pos++;
        }
        else
        {
            std::vector<CText> icvec;
            for (int i = 0; i < input_context.length(); ++i)
            {
                icvec.push_back(input_context.str()[i]);
            }

            vec.resize(pos);
            for (auto s : r.strs)
            {
                vec.push_back(s);
            }
            for (int i = r.a; i < icvec.size(); ++i)
            {
                vec.push_back(icvec[i]);
            }
            pos += r.b;
        }
    }
    for (int i = 1; i < vec.size() - 1; ++i)
    {
        result.push_back(vec[i]);
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF8");
    std::locale::global(std::locale("ru_RU.UTF8"));

    CText words;
    CText test_name = _T("../../test_dict.txt");
    if (!words.readFile(test_name.str()))
    {
        std::cerr << "Error, can not open file: " << test_name.str() << std::endl;
        return 0;
    }

    std::vector<CText> words_lines;
    words.collectLines(words_lines, words.str());

    CText answers;
    CText answers_name = _T("../../test_answers.txt");

    if (!answers.readFile(answers_name.str()))
    {
        std::cerr << "Error, can not open file: " << answers_name.str() << std::endl;
        return 0;
    }

    std::vector<CText> answers_lines;
    answers.collectLines(answers_lines, answers.str());

    int i = 0;
    for (auto word : words_lines)
    {
        //CText word = L"[-äå]";
        word.removeAny(_T("\n\r"));
        word.enclose(_T("["), _T("]"));
        std::vector<CText> parts = split(word);
        CText res;
        for (auto p : parts)
        {
            res += p + CText(_T("|"));
        }
        res = res.substring(0, res.length() - 1);

        if (i % 1000 == 0)
        {
            std::wcout << res << std::endl;
        }
        CText ans = answers_lines[i];
        ans.removeAny(_T("\n\r"));
        if (res != ans)
        {
            break;
        }
        ++i;
    }

}
