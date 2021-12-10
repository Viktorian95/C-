#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <random>
#include <iomanip>
#ifdef _MSC_VER
#endif // _MSC_VER

using namespace std;

int RAND_NUM(int min, int max)
{
    int pount=min+rand()%(max-min+1);
return pount;
}

void gen_rand_num();

class number
{
private:
    int k;
    int a;
    int m;
    int c;
    double s[100];
    double r[100];

public:
    int gen_sn()
    {

        for(int i=1;i<31;i++)
        {
            s[i]=(c%m)+a*s[i-1];
            //cout<<c%m<<endl;
        }
        return s[0];
    }
    int gen_rn()
    {
        for(int i=1;i<31;i++)
        {
            r[i]=(s[i]+1)/(m+1);
        }
        return r[0];
    }

    void genAMCS()
    {
        int x=1;
        while(x!=0)
        {
            return1:
            a=RAND_NUM(1,100);
            c=RAND_NUM(1,100);
            k=RAND_NUM(1,63);

            m=pow(2,k);
            s[0]=RAND_NUM(1,m-1);
            if(m<=a || m<=s[0] || m<=c)
            {
                goto return1;
            }
            else if(a<sqrt(m) || a>m-sqrt(m) || a%8!=5 )
            {
//                cout<<a<<endl;
                goto return1;
            }

            else if(c%2 ==0)
            {
                c++;
            }
            else if(s[0]/m>0.5 || s[0]/m<0.08)
            {
                goto return1;
            }


            gen_sn();
            gen_rn();

//            cout<<"a="<<a<<endl;
//            cout<<"m="<<m<<endl;
//            cout<<"sqrt(m)="<<sqrt(m)<<endl;
//            cout<<"m-sqrt(m)="<<m-sqrt(m)<<endl;
//            cout<<"c="<<c<<endl;
//            cout<<"s0="<<s[0]<<endl;
//            for(int i=0;i<21;i++)
//            {
//                cout<<"s"<<i<<"="<<s[i]<<endl;
//            }
//            for(int i=0;i<20;i++)
//            {
//                cout<<"r"<<i<<"="<<r[i]<<endl;
//            }

            gen_rand_num();
            x=0;
        }
    }

void gen_rand_num()
{
    int x=1;
    int chose;
  do
    {
        chose=RAND_NUM(1,20);
        cout<<"\nPush 1 if you want generate whole ------ Push 2 if you want generate real ------ Push 0 for exit"<<endl;
        cin>>x;
        while (x!=2 && x!=1 && x!=0)
        {
            cout<<"Invalid value, try again"<<endl;
            cin>>x;
        }
        switch(x)
        {
        case 1:
            cout<<"Your random whole is:"<<s[chose]<<endl;
            break;
        case 2:
            cout<<"Your random real is:"<<r[chose]<<endl;
            break;
        case 0:
            break;
        }
    }while(x!=0);
}
};
number fist;

int gen_rand_s(int min, int max)
{
    int po=1+rand()%100;
    return po;
}

const double epsilon = 1e-10;

double ex(double x, double eps)
{
    long double sum = 1.0;
    long double cur = 1.0;
    unsigned int n = 1;

    while (fabs(cur) > eps) {
        sum += (cur *= ((long double)x) / n++);
    }
    return sum;
}

int exponenta()
{
    double arg;
    do
    {
    cout << "(if You push 0 program will exit) x = ";
    cin >> arg;
    cout << "exp(" << arg << ")\n"
        << "Calculated using Maclaurin series: "
        << setiosflags(ios::fixed) << setprecision(9)
        << ex(arg, epsilon) << endl
        << "Calculated using library function: "
        << exp(arg) << endl;
        if(arg!=01)
        cout<<"Enter value"<<endl;
   }while(arg!=0);

#ifdef _MSC_VER
    system("pause");
#endif
    return 0;
}

int n, i, j, k;
double d, s;
int gauss()
{
    do{
    cout << "Оrder or 0 for exit: " << endl;
    cin >> n;
    double **a = new double *[n];
    for (i = 0; i <= n; i++)
    a[i] = new double [n];
    double **a1 = new double *[n];
    for (i = 0; i <= n; i++)
    a1[i] = new double [n];
    double *b = new double [n];
    double *x = new double [n];

    cout << "Еnter coefficients and free terms " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "a[ " << i << "," << j << "]= ";
            cin >> a[i][j];
            a1[i][j] = a[i][j];
        }
        cout << "b,[ " << i << "]= ";
        cin >> b[i];
    }
    for (k = 1; k <= n; k++) // прямой ход
    {
        for (j = k + 1; j <= n; j++)
        {
            d = a[j][k] / a[k][k]; // формула (1)
            for (i = k; i <= n; i++)
            {
                a[j][i] = a[j][i] - d * a[k][i]; // формула (2)
            }
            b[j] = b[j] - d * b[k]; // формула (3)
        }
    }
    for (k = n; k >= 1; k--) // обратный ход
    {
        d = 0;
        for (j = k + 1; j <= n; j++)
        {
            s = a[k][j] * x[j]; // формула (4)
            d = d + s; // формула (4)
        }
        x[k] = (b[k] - d) / a[k][k]; // формула (4)
    }
    cout << "system roots: " << endl;
    for( i = 1; i <= n; i++)
    cout << "x[" << i << "]=" << x[i] << " " << endl;
    }while(n!=0);
    return 0;
}

int main()
{
    srand(time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int select;
    cout<<"Enter 1 to open generator"<<endl;
    cout<<"Enter 2 to open exponential decomposition"<<endl;
    cout<<"Enter 3 to open Gaussian expansion"<<endl;
    cin>>select;
    do{
        if(select==1)
        {
//            fist.gen_rand_num();
            fist.genAMCS();
        }
        if(select==2)
        {
            exponenta();
        }
        if(select==3)
        {
            gauss();
        }
        cout<<"\nEnter 1 to open generator"<<endl;
        cout<<"Enter 2 to open exponential decomposition"<<endl;
        cout<<"Enter 3 to open Gaussian expansion"<<endl;
        cin>>select;
     }while(select!=0);
}


