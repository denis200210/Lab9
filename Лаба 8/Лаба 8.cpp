#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

class Operation
{

private:
    int symbol = 0;
    unsigned int priority = 0;

public:

    virtual int res(int a, int b)
    {
        return (-1);
    }

    int getSymbol()
    {
        return this->symbol;
    }
    void setSymbol(char name1)
    {
        this->symbol = name1;
    }
   


protected:
};

class Plus: public Operation
{
    int c;
private:

public:

    Plus()
    {
        this->setSymbol('+');
       
    };

    int res(int a, int b)
    {
        c = a + b;
        return (c);
    }

protected:

};

class Minus : public Operation
{
    int c;
private:

public:

    Minus()
    {
        this->setSymbol('-');
        
    };

    int res(int a, int b)
    {
        c = a - b;
        return (c);
    }

protected:

};

class Umnozhit : public Operation
{
    int c;

private:

public:

    Umnozhit()
    {
        this->setSymbol('*');
       
    };

    int res(int a, int b)
    {
        c = a * b;
        return (c);
    }

protected:

};

class Razdelit : public Operation
{
    int c;

private:

public:

    Razdelit()
    {
        this->setSymbol('/');
        
    };

    int res(int a, int b)
    {
        if (b != 0)
        {
            c = a / b;
            return (c);
        }
        else
        {
            return a;
        }
    }

protected:

};

struct SymbolLink
{
    char symb = ' ';
    Operation* link;
};

const unsigned short int MaxCountOfOperations = 20;

Operation* o[MaxCountOfOperations];
SymbolLink symbolmass[MaxCountOfOperations] = {};



int SymbolContained(char ab)
{
    for (unsigned short int i = 0; i < MaxCountOfOperations; ++i)
    {
        if (symbolmass[i].symb == ab)
        {
            return i;
        }
    }
    return -1;
}

int Obratnaipoliskai(char* input)
{

    Plus* op0 = new Plus();  // тут подключаются операции
    o[0]   = op0;
    symbolmass[0].symb = op0->getSymbol();
    symbolmass[0].link = op0;

    Minus* op1 = new Minus();
    o[1] = op1;
    symbolmass[1].symb = op1->getSymbol();
    symbolmass[1].link = op1;

    Umnozhit* op2 = new Umnozhit();
    o[2] = op2;
    symbolmass[2].symb = op2->getSymbol();
    symbolmass[2].link = op2;

    Razdelit* op3 = new Razdelit();
    o[3] = op3;
    symbolmass[3].symb = op3->getSymbol();
    symbolmass[3].link = op3;


    stack <char> steck;
    stack <char> steck2;

    int otvet;
    const int N = 100;
    char output[N];
    otvet = 0;
    int j = 0;
    for (j = 0; j < N; ++j)
    {
        output[j] = 0;
    }
    int i = 0;
    int istack = 0;
    int ioutput = 0;
    while (input[i] != 0)
    {
        if (input[i] != ' ')
        {
            if ((SymbolContained(input[i]) != -1) || (input[i] == '(') || (input[i] == ')'))
            {
                if ((istack > 0))
                {
                    if (((((input[i]) != '(') && (input[i]) != ')')) && ((((steck.top()) != '(') && (steck.top()) != ')')) )
                    {


                        output[ioutput] = steck.top();
                        ++ioutput;



                        steck.pop();
                        --istack;

                        steck.push(input[i]);
                        ++istack;
                    }
                    else
                    {

                        if (((input[i] == ')')))
                        {

                            while (steck.top() != '(')
                            {
                                if ((SymbolContained(steck.top()) != -1))
                                {

                                    output[ioutput] = steck.top();
                                    ++ioutput;
                                    steck.pop();
                                    --istack;
                                }

                            }

                            steck.pop();
                            --istack;
                        }
                        else
                        {

                            steck.push(input[i]);
                            ++istack;


                        }
                    }
                }
                else
                {

                    steck.push(input[i]);
                    ++istack;
                }
            }
            else
            {
                if ((input[i] >= 48) || (input[i] <= 57))
                {
                    output[ioutput] = input[i];
                    ++ioutput;
                }
            }
        }
            ++i;

    }
    while (istack > 0)
    {
        output[ioutput] = steck.top();
        ++ioutput;
        steck.pop();
        --istack;
    }




    istack = 0;
    ioutput = 0;
    int a;
    int b;
    int c;
    while (output[ioutput] != 0)
    {
        if ((output[ioutput] >= 48) && (output[ioutput] <= 57))
        {
            steck2.push(output[ioutput] - 48);
            ++istack;
        }
        else
        {
            if (istack > 1)
            {
                if ((SymbolContained(output[ioutput]) != -1))
                {
                    a = steck2.top();
                    steck2.pop();
                    --istack;
                    b = steck2.top();
                    steck2.pop();
                    --istack;
                    j = 0;

                    c = symbolmass[(SymbolContained(output[ioutput]))].link->res(b, a);
                    steck2.push(c);
                    ++istack;

                }
            }
        }
        ++ioutput;
    }

    cout << output << endl << endl << endl;


    return (int)steck2.top();


}