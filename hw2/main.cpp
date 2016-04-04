#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>

#define MAX_POWER 5
#define NUMBER_OF_COEFFICIENTS highpow+1
#define DEBUG 1
int fun_one(float array[]);
void fun_two(int highpow,float array[]);
void fun_three(int highpow,float array[],float derivative[]);
float fun_four(int highpow,float array[],float value);
using namespace std;
ifstream inp; //�إ߿�J�ɮת���

int main()
{
    inp.open("polydata.txt",ios::in);//���}�ɮ�

    int i,control,highest_power;
    float array[20],derivative[20];
    float temp,result,value = 0.0;
    while(1)
    {
        cout << "Please enter 1 to start this program,or enter 0 to stop." << endl;
        cin >> control;
        if(control == 1) // start program
        {
            highest_power = fun_one(array);

            if(highest_power > MAX_POWER) // �̰��������~
            {
                cout << "Error!MaxPower is limit to 5,please enter again." << endl;
                continue;
            }
            else if(highest_power == -2) // �h�����Y�ƭӼƦ��~
            {
                cout << "Error!Number of Coefficients must equal MaxPower+1,please enter again." << endl;
                continue;

            }

            fun_two(highest_power,array);
            //�ΰj��v�@�ǤJ�a�J��
            for(value = 0.0 ; value <= 1.0 ;value = value + 0.2)
            {
                result = fun_four(highest_power,array,value);
                cout << result; //�L�X���G
                if(value < 1.0)
                    cout << ", ";
            }
            cout << endl;

            //�L���h�����æL�X�a�J��
            fun_three(highest_power,array,derivative);
            for(value = 0.0 ; value <= 1.0 ;value = value + 0.2)
            {
                result = fun_four(highest_power-1,derivative,value);
                cout << result;
                if(value < 1.0)
                    cout << ", ";
            }
            cout << endl;
        }
        else
        {
            inp.close(); //�����ɮ�
            cout << "Program over.";
            return 0;
        }
    }
}
//function1 Ū�J�h����
int fun_one(float array[])
{
    int i,option,highpow,n=0;
    float temp;
    char buf[300];
    char *ptr;

    cout << "Please enter 1 or 0,[1->read from keyboard,0->read from file]" << endl;
    cin >> option;
    if(option == DEBUG) //  read from keyboard
    {
        cin >> highpow;
        cin.getline(buf,sizeof(buf),'\n'); // ��MAXPOWER�᭱���@��Ʀr
        ptr = strtok(buf," ");
        while(ptr != NULL)
        {
            array[n] = atof(ptr);
            n++;
            ptr = strtok(NULL," ");
        }
    }
    else   //  read from file
    {
        inp >> highpow; // highpow = �̰����� , highpow+1 = �`�@���X���Ʀr
        inp.getline(buf,sizeof(buf),'\n'); // ��MAXPOWER�᭱���@��Ʀr
        ptr = strtok(buf," ");
        while(ptr != NULL)
        {
            array[n] = atof(ptr);
            cout << array[n] << endl;
            n++;
            ptr = strtok(NULL," ");
        }
    }
    cout << "n=" << n << endl;
    if( (NUMBER_OF_COEFFICIENTS) != n ) // �p�G�h�����Y�ƿ�J���~�A�h�^��-2
            highpow = -2;
    return highpow;
}

//function2 �L�X�h����
void fun_two(int highpow,float array[])
{
    int i,j,n;

    if((highpow == -1) || (highpow == 0 && array[0] == 0))
        cout << 0;

    for(i=0;i<=highpow;i++)
    {
        if(array[i] == 0)
            continue;
        cout << array[i];
        for(j=0;j<i;j++)
            cout << "*x";
        if(i<highpow)
            cout << "+";
    }
    cout << endl;
}
//function3 �L���h����
void fun_three(int highpow,float array[],float derivative[])
{
    int i;
    //�̧ǰ��L���æs�J�}�C��
    for(i=1;i<=highpow;i++)
        derivative[i-1] = i*array[i];
    fun_two(highpow-1,derivative); // �]���L��,�ҥH���Ʒ|��1,�G�ǤJhighpow-1

}

//function4 �N�ƭȱa�J�h����
float fun_four(int highpow,float array[],float value)
{
    int i;
    float sum;
    sum = 0;
    for(i=0;i<=highpow;i++)
        sum = sum + array[i]*pow(value,i); //compute x^
    return sum;
}
